/**
 * Copyright (c) 2017 - 2017, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "sdk_common.h"

#if NRF_MODULE_ENABLED(ST7789)

#include "nrf_lcd.h"
#include "nrf_drv_spi.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"

#include "spi_master_fast.h"

// Set of commands described in ST7789 datasheet.
#define ST7789_NOP         0x00
#define ST7789_SWRESET     0x01
#define ST7789_RDDID       0x04
#define ST7789_RDDST       0x09

#define ST7789_SLPIN       0x10
#define ST7789_SLPOUT      0x11
#define ST7789_PTLON       0x12
#define ST7789_NORON       0x13

#define ST7789_RDMODE      0x0A
#define ST7789_RDMADCTL    0x0B
#define ST7789_RDPIXFMT    0x0C
#define ST7789_RDIMGFMT    0x0D
#define ST7789_RDSELFDIAG  0x0F

#define ST7789_INVOFF      0x20
#define ST7789_INVON       0x21
#define ST7789_GAMMASET    0x26
#define ST7789_DISPOFF     0x28
#define ST7789_DISPON      0x29

#define ST7789_CASET       0x2A
#define ST7789_RASET       0x2B
#define ST7789_RAMWR       0x2C
#define ST7789_RAMRD       0x2E

#define ST7789_PTLAR       0x30
#define ST7789_MADCTL      0x36
#define ST7789_COLMOD      0x3A

//#define ST7789_FRMCTR1     0xB1
#define ST7789_RGBCTRL     0xB1
#define ST7789_PORCTR      0xB2
//#define ST7789_FRMCTR2     0xB2
#define ST7789_FRMCTR3     0xB3
#define ST7789_INVCTR      0xB4
#define ST7789_DFUNCTR     0xB6
#define ST7789_GCTRL       0xB7

#define ST7789_VCOM        0xBB

#define ST7789_LCMCTR      0xC0
//#define ST7789_PWCTR1      0xC0
#define ST7789_PWCTR2      0xC1
#define ST7789_VDVVRHEN    0xC2
//#define ST7789_PWCTR3      0xC2
#define ST7789_VRHS        0xC3
//#define ST7789_PWCTR4      0xC3
#define ST7789_VDVS        0xC4
//#define ST7789_PWCTR5      0xC4
#define ST7789_VMCTR1      0xC5
#define ST7789_FRMCTR2     0xC6
#define ST7789_VMCTR2      0xC7
#define ST7789_PWCTRSEQ    0xCB
#define ST7789_PWCTRA      0xCD
#define ST7789_PWCTRB      0xCF

#define ST7789_PWCTRL1     0xD0

#define ST7789_RDID1       0xDA
#define ST7789_RDID2       0xDB
#define ST7789_RDID3       0xDC
#define ST7789_RDID4       0xDD

#define ST7789_PVGAMCTRL     0xE0
#define ST7789_NVGAMCTRL     0xE1
#define ST7789_DGMCTR1     0xE2
#define ST7789_DGMCTR2     0xE3
#define ST7789_SPI2EN      0xE7
#define ST7789_TIMCTRA     0xE8
#define ST7789_TIMCTRB     0xEA

#define ST7789_ENGMCTR     0xF2
#define ST7789_INCTR       0xF6
#define ST7789_PUMP        0xF7

#define ST7789_MADCTL_MY  0x80
#define ST7789_MADCTL_MX  0x40
#define ST7789_MADCTL_MV  0x20
#define ST7789_MADCTL_ML  0x10
#define ST7789_MADCTL_RGB 0x00 //replace BGR with this to get normal coloring
#define ST7789_MADCTL_BGR 0x08 //used by default
#define ST7789_MADCTL_MH  0x04

//Position setting for 240x240 LCD
#define ST7789_240x240_XSTART 0
#define ST7789_240x240_YSTART 80

//Datasheet: https://www.numworks.com/shared/binary/datasheets/st7789v-lcd-controller-73f8bc3e.pdf

static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(ST7789_SPI_INSTANCE);

static bool fast_spi = false;

static inline void spi_write(const void * data, size_t size)
{
    if(fast_spi){
      spi_master_tx(ST7789_SPI_INSTANCE, size, data);
    }
    else{
      APP_ERROR_CHECK(nrf_drv_spi_transfer(&spi, data, size, NULL, 0));
    }
}

static inline void write_command(uint8_t c)
{
    nrf_gpio_pin_clear(ST7789_DC_PIN);

    spi_write(&c, sizeof(c));
}

static inline void write_data(uint8_t c)
{
    nrf_gpio_pin_set(ST7789_DC_PIN);

      spi_write(&c, sizeof(c));
}

static inline void write_command_buffered(uint8_t * c, uint16_t len)
{
    nrf_gpio_pin_clear(ST7789_DC_PIN);

    spi_write(c, len);
}

static inline void write_data_buffered(uint8_t * c, uint16_t len)
{
    nrf_gpio_pin_set(ST7789_DC_PIN);

    spi_write(c, len);
}

static void set_addr_window(uint16_t x_0, uint16_t y_0, uint16_t x_1, uint16_t y_1)
{
    ASSERT(x_0 <= x_1);
    ASSERT(y_0 <= y_1);

    write_command(ST7789_CASET);
    write_data(x_0 >> 8);
    write_data(x_0);
    write_data(x_1 >> 8);
    write_data(x_1);
    write_command(ST7789_RASET);
    write_data(y_0 >> 8);
    write_data(y_0);
    write_data(y_1 >> 8);
    write_data(y_1);
    write_command(ST7789_RAMWR);
}

static void command_list(void)
{
    //Adafruit's
    /*
    write_command(ST7789_SWRESET); //Software reset
    nrf_delay_ms(150);

    write_command(ST7789_SLPOUT);  //Exit sleep
    nrf_delay_ms(500);

    write_command(ST7789_COLMOD);  //Color mode
    write_data(0x55); //16-bit, 565 RGB
    nrf_delay_ms(10);

    write_command(ST7789_MADCTL);  //Memory Data Access control
    write_data(0x08); //Bottom to top refresh

    write_command(ST7789_CASET);  //Column address set
    write_data(0x00);                                 //x start high byte = 0x00
    write_data(ST7789_240x240_XSTART);                //x start low byte = 0x00
    write_data((240 + ST7789_240x240_XSTART) >> 8);   //x end high byte = 0x00
    write_data((240 + ST7789_240x240_XSTART) & 0xFF - 1); //x end low byte = 0xF0

    write_command(ST7789_RASET);  //Row address set
    write_data(0x00);                                 //x start high byte = 0x00
    write_data(ST7789_240x240_YSTART);                //x start low byte = 0x50
    write_data((240 + ST7789_240x240_YSTART) >> 8);   //x end high byte = 0x01
    write_data((240 + ST7789_240x240_YSTART) & 0xFF - 1); //x end low byte = 0x40

    write_command(ST7789_INVON);  //Screen inversion on
    nrf_delay_ms(10);

    write_command(ST7789_NORON);  //Normal display mode on
    nrf_delay_ms(10);

    write_command(ST7789_DISPON); //Display on
    nrf_delay_ms(500);
    //*/

    //NewHaven's http://www.newhavendisplay.com/app_notes/2-4TFT_ST7789.txt
    //THIS ONE WORKED THE BEST
    
    write_command(ST7789_SWRESET);  //Software reset
    nrf_delay_ms(125);

    write_command(ST7789_SLPOUT);  //Exit sleep
    nrf_delay_ms(150);

    write_command(ST7789_MADCTL);  //Memory Data Access control
    write_data(0x08); //Bottom to top page address order

    write_command(ST7789_COLMOD); //Color mode
    write_data(0x55); //16-bit, 565 RGB
    //write_data(0x53); //12-bit, 444N RGB (N=col for next byte, uses 1.5B per pixel when mass sending data)

    /*
    write_command(ST7789_PORCTR); //Porch control
    write_data(0x0C); //
    write_data(0x0C); //
    write_data(0x00); //Separate porch control disabled
    write_data(0x33); //
    write_data(0x33); //

    write_command(ST7789_GCTRL);  //Gate control
    write_data(0x35); //+13.26V, -10.43V

    write_command(ST7789_VCOM); //VCOM setting
    write_data(0x2B); //1.175V

    write_command(ST7789_LCMCTR); //LCM control
    write_data(0x2C); //XOR RGB in MADCTL, XOR MV in MADCTL, reverse source output order XMH (?)

    write_command(ST7789_VDVVRHEN); //VDV & VRV command enable
    write_data(0x01); //Enable
    write_data(0xFF); //Hardcoded/ default

    write_command(ST7789_VRHS); //VRH set
    //write_data(0x11); //+4.4V + ( vcom+vcom offset+0.5vdv), -4.4V + ( vcom+vcom offset-0.5vdv)
    write_data(0x0B); //+4.1 + ( vcom+vcom offset+0.5vdv), -4.1 + ( vcom+vcom offset+0.5vdv)
    //May be an error confusing hex and decimal, 11dec = 0x0B = register default value

    write_command(ST7789_VDVS); //VDV set
    write_data(0x20); //0V
    //*/

    write_command(ST7789_FRMCTR2);  //Frame rate control in normal mode
    write_data(0x01); //111Hz
    //write_data(0x0F); //60Hz

    /*
    write_command(ST7789_PWCTRL1);  //Power control 1
    write_data(0xA4); //Hardcoded/ default
    write_data(0xA1); //Avdd = 6.8V, Avcl = -4.8V, Vdds = 2.3V
    //*/
    
    //nrf_delay_ms(2000);

    write_command(ST7789_PVGAMCTRL); //+ voltage gamma control
    write_data(0xD0);
    write_data(0x00);
    write_data(0x05);
    write_data(0x0E);
    write_data(0x15);
    write_data(0x0D);
    write_data(0x37);
    write_data(0x43);
    write_data(0x47);
    write_data(0x09);
    write_data(0x15);
    write_data(0x12);
    write_data(0x16);
    write_data(0x09);//*/

    //uint8_t dat_buf[14] = {0xD0, 0x00, 0x05, 0x0E, 0x15, 0x0D, 0x37, 0x43, 0x47, 0x09, 0x15, 0x12, 0x16, 0x09};
    //write_data_buffered(dat_buf, 14);

    write_command(ST7789_NVGAMCTRL); //- voltage gamma control
    write_data(0xD0);
    write_data(0x00);
    write_data(0x05);
    write_data(0x0D);
    write_data(0x0C);
    write_data(0x06);
    write_data(0x2D);
    write_data(0x44);
    write_data(0x40);
    write_data(0x0E);
    write_data(0x1C);
    write_data(0x18);
    write_data(0x16);
    write_data(0x19);//*/

    //uint8_t dat_buf2[14] = {0xD0, 0x00, 0x05, 0x0D, 0x0C, 0x06, 0x2D, 0x44, 0x40, 0x0E, 0x1C, 0x18, 0x16, 0x19};
    //write_data_buffered(dat_buf2, 14);

    /*write_command(ST7789_RGBCTRL);  //RGB interface control
    write_data(
    write_data(
    write_data(//*/

    /*
    write_command(ST7789_CASET);  //Column address set
    write_data(0x00); //x start high byte = 0
    write_data(0x00); //x start low byte = 0
    write_data(0x00); //x end high byte = 0
    write_data(0xEf); //x end low byte = 239

    write_command(ST7789_RASET);  //Row address set
    write_data(0x00); //x start high byte = 0
    write_data(0x50); //x start low byte = 80
    write_data(0x01); //x end high byte = 1
    write_data(0x3F); //x end low byte = 63
    nrf_delay_ms(10); //x end total = 319
    //*/
    
    write_command(ST7789_INVON);  //Screen inversion on, added in because colors were reversed without

    write_command(ST7789_DISPON);

    //*/

    // Nordic's (?) ST7789, modified from ILI9341
    /*
    write_command(ST7789_SWRESET);
    nrf_delay_ms(120);
    write_command(ST7789_DISPOFF);
    nrf_delay_ms(120);
    write_command(ST7789_PWCTRB);
    write_data(0x00);
    write_data(0XC1);
    write_data(0X30);

    write_command(ST7789_TIMCTRA);
    write_data(0x85);
    write_data(0x00);
    write_data(0x78);

    write_command(ST7789_PWCTRSEQ);
    write_data(0x39);
    write_data(0x2C);
    write_data(0x00);
    write_data(0x34);
    write_data(0x02);

    write_command(ST7789_PUMP);
    write_data(0x20);

    write_command(ST7789_TIMCTRB);
    write_data(0x00);
    write_data(0x00);

    //write_command(ST7789_PWCTR1);
    write_command(0xC0);
    write_data(0x23);

    write_command(ST7789_PWCTR2);
    write_data(0x10);

    write_command(ST7789_VMCTR1);
    write_data(0x3e);
    write_data(0x28);

    write_command(ST7789_VMCTR2);
    write_data(0x86);

    write_command(ST7789_MADCTL);
    write_data(0x48);

    write_command(ST7789_COLMOD);
    write_data(0x55);

    write_command(ST7789_FRMCTR1);
    write_data(0x00);
    write_data(0x18);

    write_command(ST7789_DFUNCTR);
    write_data(0x08);
    write_data(0x82);
    write_data(0x27);

    write_command(ST7789_ENGMCTR);
    write_data(0x00);

    write_command(ST7789_GAMMASET);
    write_data(0x01);

    write_command(ST7789_PVGAMCTRL);
    write_data(0x0F);
    write_data(0x31);
    write_data(0x2B);
    write_data(0x0C);
    write_data(0x0E);
    write_data(0x08);
    write_data(0x4E);
    write_data(0xF1);
    write_data(0x37);
    write_data(0x07);
    write_data(0x10);
    write_data(0x03);
    write_data(0x0E);
    write_data(0x09);
    write_data(0x00);

    write_command(ST7789_NVGAMCTRL);
    write_data(0x00);
    write_data(0x0E);
    write_data(0x14);
    write_data(0x03);
    write_data(0x11);
    write_data(0x07);
    write_data(0x31);
    write_data(0xC1);
    write_data(0x48);
    write_data(0x08);
    write_data(0x0F);
    write_data(0x0C);
    write_data(0x31);
    write_data(0x36);
    write_data(0x0F);

    write_command(ST7789_SLPOUT);
    nrf_delay_ms(120);
    write_command(ST7789_DISPON);
    //*/
}

static ret_code_t hardware_init(void)
{
    ret_code_t err_code;

    nrf_gpio_cfg_output(ST7789_DC_PIN);

    nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG;

    spi_config.frequency = NRF_DRV_SPI_FREQ_8M; //added in
    spi_config.mode = NRF_SPI_MODE_2; //added in

    spi_config.sck_pin  = ST7789_SCK_PIN;
    spi_config.miso_pin = ST7789_MISO_PIN;
    spi_config.mosi_pin = ST7789_MOSI_PIN;
    spi_config.ss_pin   = ST7789_SS_PIN;

    fast_spi = false;

    err_code = nrf_drv_spi_init(&spi, &spi_config, NULL, NULL);
    return err_code;
}

static ret_code_t fast_hardware_init(void)
{
    ret_code_t err_code;

    nrf_gpio_cfg_output(ST7789_DC_PIN);

    SPI_config_t spi_config =  {.pin_SCK                 = ST7789_SCK_PIN, 
                                .pin_MOSI                = ST7789_MOSI_PIN, 
                                .pin_MISO                = ST7789_MISO_PIN, 
                                .pin_CSN                 = ST7789_SS_PIN,  
                                .frequency               = SPI_FREQ_8MBPS, 
                                .config.fields.mode      = SPI_MODE2, 
                                .config.fields.bit_order = SPI_BITORDER_MSB_LSB};
    
    // Initialize the SPI
    err_code = (ret_code_t) spi_master_init(ST7789_SPI_INSTANCE, &spi_config);

    fast_spi = true;

    if(err_code != 0){
      err_code = NRF_SUCCESS;
    }
    else{
      err_code = NRF_ERROR_TIMEOUT;
    }
    return err_code;
}

static ret_code_t st7789_init(void)
{
    ret_code_t err_code;

    //err_code = hardware_init();
    err_code = fast_hardware_init();
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    command_list();

    return err_code;
}

static void st7789_uninit(void)
{
    nrf_drv_spi_uninit(&spi);
}

static void st7789_pixel_draw(uint16_t x, uint16_t y, uint32_t color)
{
    set_addr_window(x, y, x, y);

    uint8_t data[2] = {color >> 8, color};
    
    //nrf_gpio_pin_set(ST7789_DC_PIN);

    //spi_write(data, sizeof(data));

    write_data_buffered(data, sizeof(data));
}

static void st7789_rect_draw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color)
{
    set_addr_window(x, y, x + width - 1, y + height - 1);

    uint8_t data[2] = {color >> 8, color};

    nrf_gpio_pin_set(ST7789_DC_PIN);

    // Duff's device algorithm for optimizing loop.
    uint32_t i = (height * width + 7) / 8;

/*lint -save -e525 -e616 -e646 */
    switch ((height * width) % 8) {
        case 0:
            do {
                spi_write(data, sizeof(data));
        case 7:
                spi_write(data, sizeof(data));
        case 6:
                spi_write(data, sizeof(data));
        case 5:
                spi_write(data, sizeof(data));
        case 4:
                spi_write(data, sizeof(data));
        case 3:
                spi_write(data, sizeof(data));
        case 2:
                spi_write(data, sizeof(data));
        case 1:
                spi_write(data, sizeof(data));
            } while (--i > 0);
        default:
            break;
    }
/*lint -restore */

    nrf_gpio_pin_clear(ST7789_DC_PIN);
}

static void st7789_dummy_display(uint8_t * data, uint16_t len, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1)
{
    if(len == 0xFFFF){
        set_addr_window(x0, y0, x1, y1);
    }
    else{
      //spi_write(&data, len);
      write_data_buffered(data, len);
    }
}

static void st7789_rotation_set(nrf_lcd_rotation_t rotation)
{
    write_command(ST7789_MADCTL);
    switch (rotation % 4) {
        case NRF_LCD_ROTATE_0:
            write_data(ST7789_MADCTL_MX | ST7789_MADCTL_MY | ST7789_MADCTL_RGB);  //Not working correctly
            //Column address (MX): Right to left
            //Page address (MY): Bottom to top
            //Page/ Column order (MV): normal
            //RGB/BGR order: RGB
            break;
        case NRF_LCD_ROTATE_90:
            write_data(ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
            //Column address (MX): Left to right
            //Page address (MY): Top to bottom
            //Page/ Column order (MV): reverse
            //RGB/BGR order: RGB
            break;
        case NRF_LCD_ROTATE_180:
            write_data(ST7789_MADCTL_RGB);
            //Column address (MX): Left to right
            //Page address (MY): Top to bottom
            //Page/ Column order (MV): normal
            //RGB/BGR order: RGB
            break;
        case NRF_LCD_ROTATE_270:
            write_data(ST7789_MADCTL_MX | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
            //Column address (MX): Right to left
            //Page address (MY): Top to bottom
            //Page/ Column order (MV): reverse
            //RGB/BGR order: RGB
            break;
        default:
            break;
    }
}

static void st7789_display_invert(bool invert)
{
    write_command(invert ? ST7789_INVON : ST7789_INVOFF);
}

static lcd_cb_t st7789_cb = {
    .height = ST7789_HEIGHT,
    .width = ST7789_WIDTH
};


const nrf_lcd_t nrf_lcd_st7789 = {
    .lcd_init = st7789_init,
    .lcd_uninit = st7789_uninit,
    .lcd_pixel_draw = st7789_pixel_draw,
    .lcd_rect_draw = st7789_rect_draw,
    .lcd_display = st7789_dummy_display,
    .lcd_rotation_set = st7789_rotation_set,
    .lcd_display_invert = st7789_display_invert,
    .p_lcd_cb = &st7789_cb
};

#endif // NRF_MODULE_ENABLED(ST7789)