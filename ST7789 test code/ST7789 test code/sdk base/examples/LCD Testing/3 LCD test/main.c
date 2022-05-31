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

/** @file
 * @brief TFT Example Application main file.
 *
 * This file contains the source code for a sample application using the
 * GFX library based on the ILI9341 controller.
 *
 */

////////////////////////////////2 LCD TEST/////////////////////////

#include "nrf52_dk.h"
#include "app_util_platform.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_drv_gpiote.h"
#include "app_error.h"
#include <string.h>
#include "nrf_drv_timer.h"
#include "nrf_drv_clock.h"
//#include "Symbols.h"
//#include "Symbols_132x132.h"
#include "Symbols_240x240.h"
#include "Colors.h"

#define BACKGROUND_COLOR  WHITE
#define TIMER_COLOR       BLACK

/* //12-bit color
#define BLACK   0x0000
#define WHITE   0xFFFF
#define GRAY    0x7770
#define DARK_GRAY  0x5550
#define LIGHT_YELLOW  0xFF70
#define YELLOW  0xFF00
#define RED     0xF000
#define BLUE    0x00F0
#define CYAN    0x0FD0  //*/

#include "nrf_gfx.h"

#include "spi_master_fast.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "yuGothic_42pt.h"
#include "yuGothic_numeric_42pt.h"

#include "arial_24pt.h"
#include "arial_42pt.h"
#include "arial_72pt.h"

#include "arial_bold_8pt.h"
#include "arial_bold_12pt.h"
#include "arial_bold_14pt.h"
#include "arial_bold_18pt.h"
#include "arial_bold_20pt.h"
#include "arial_bold_22pt.h"
#include "arial_bold_24pt.h"
#include "arial_bold_28pt.h"
#include "arial_bold_32pt.h"
#include "arial_bold_36pt.h"
#include "arial_bold_42pt.h"
#include "arial_bold_48pt.h"
#include "arial_bold_52pt.h"
#include "arial_bold_72pt.h"

//#define RGB2BGR(x)      (x << 11) | (x & 0x07E0) | (x >> 11)

//Font dimensions for offsets
#define SPACE_SIZE        3
#define LETTER_SIZE       49
#define LETTER_HEIGHT     75
#define COLON_SIZE        13

#define XPOS_TIMER             10
#define YPOS_TIMER             164

#define XOFFSET_SECOND_ONES   (3 * LETTER_SIZE + COLON_SIZE + 4 * SPACE_SIZE)
#define XOFFSET_SECOND_TENS   (2 * LETTER_SIZE + COLON_SIZE + 3 * SPACE_SIZE)
#define XOFFSET_COLON         (2* LETTER_SIZE + 2 * SPACE_SIZE) - 3
#define XOFFSET_MINUTE_ONES   (LETTER_SIZE + SPACE_SIZE)
#define XOFFSET_MINUTE_TENS   0//*/

#define XPOS_TIMER_TEXT        14
#define YPOS_TIMER_TEXT        148

#define XPOS_SUBJECT_TEXT      14
#define YPOS_SUBJECT_TEXT      60

#define CROSS_LINE_HEIGHT      141
#define CROSS_LINE_XL          10
#define CROSS_LINE_XR          230
#define CROSS_LINE_WIDTH       4

#define LINE_STEP       10

#define TIMER_TICKS   250
#define TIMER_SECOND 1000  //2032 w/ 123 ticks

#define LCD_BL_PIN    18
#define BUTTON_4_PIN  16
#define BUTTON_1_PIN  13

static const char timer_text[] = "Timer";

char subject_text[] = "Let's talk all about this";

char timer[] = "00:00";

uint16_t timer_event = 0;
uint32_t seconds_timer = 0;

uint32_t global_timer = 0;

uint8_t display_times[4] = {48, 48, 48, 48};

char minute_tens[] = "1";
char minute_ones[] = "0";
char second_tens[] = "0";
char second_ones[] = "5";
const char colon[] = ":";

bool display_flags[4] = {true, true, true, true};

bool flag_minute_tens = true;
bool flag_minute_ones = true;
bool flag_second_tens = true;
bool flag_second_ones = true;

bool counting = false;
bool count_direction = false;  //true = up, false = down
bool selector_flashing = false;
bool selector_drawn = false;
bool backlight_state = false;

typedef enum{
    turn_attack = 0,
    turn_retreat,
}project1_player_turn_order;
project1_player_turn_order turn_order = 0;
bool update_turn_order = false;

const char attack[] = "Attack";
const char retreat[] = "Retreat";

bool colon_state = false;

bool button_read = true;
uint16_t button_tracker = 0;

const nrf_gfx_rect_t attack_outer_rect = NRF_GFX_RECT(10,100,115,40);
const nrf_gfx_rect_t attack_inner_rect = NRF_GFX_RECT(14,104,107,32);
const nrf_gfx_rect_t attack_inner_rects[] = { NRF_GFX_RECT(14,104,5,32),    //left
                                              NRF_GFX_RECT(14,104,107,5),   //top
                                              NRF_GFX_RECT(14,130,107,6),   //bottom
                                              NRF_GFX_RECT(107,104,7,32)};  //right
const nrf_gfx_rect_t retreat_outer_rect = NRF_GFX_RECT(110,100,115,40);
const nrf_gfx_rect_t retreat_inner_rect = NRF_GFX_RECT(114,104,107,32);
const nrf_gfx_rect_t retreat_inner_rects[] = {NRF_GFX_RECT(114,104,5,32),   //left
                                              NRF_GFX_RECT(114,104,107,5),  //top
                                              NRF_GFX_RECT(114,130,107,6),  //bottom
                                              NRF_GFX_RECT(216,104,5,32)};  //right

const nrf_gfx_rect_t sel_rect[] = { NRF_GFX_RECT(24, 186, 46, 6),
                                    NRF_GFX_RECT(74, 186, 46, 6),
                                    NRF_GFX_RECT(124, 186, 46, 6),
                                    NRF_GFX_RECT(174, 186, 46, 6)};
uint8_t sel_rect_no = 0;


const uint16_t player_colors[4] = {RED, SKY_BLUE, FOREST_GREEN, DARK_ORANGE};


uint8_t prev_display_times[4] = {48, 48, 48, 48};

uint8_t prev_minute_tens[] = "0";
uint8_t prev_minute_ones[] = "0";
uint8_t prev_second_tens[] = "0";
uint8_t prev_second_ones[] = "0";

const nrf_drv_timer_t timer_1hz = NRF_DRV_TIMER_INSTANCE(1);

extern const nrf_gfx_font_desc_t yuGothic_42ptFontInfo;
extern const nrf_gfx_font_desc_t yuGothic_numeric_42ptFontInfo;
extern const nrf_gfx_font_desc_t orkney_8ptFontInfo;
extern const nrf_gfx_font_desc_t orkney_24ptFontInfo;
extern const nrf_gfx_font_desc_t arial_24ptFontInfo;
extern const nrf_gfx_font_desc_t arial_42ptFontInfo;
extern const nrf_gfx_font_desc_t arial_72ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_8ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_12ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_14ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_18ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_20ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_22ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_24ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_28ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_32ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_36ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_42ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_48ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_52ptFontInfo;
extern const nrf_gfx_font_desc_t arial_bold_72ptFontInfo;

extern const nrf_lcd_t nrf_lcd_st7789;
extern const nrf_lcd_t nrf_lcd_st7735;

static const nrf_gfx_font_desc_t * timer_font = &arial_bold_72ptFontInfo;
static const nrf_gfx_font_desc_t * small_text_font = &arial_bold_14ptFontInfo;
static const nrf_gfx_font_desc_t * subject_font = &arial_bold_28ptFontInfo;

static const nrf_gfx_font_desc_t * project1_font = &arial_bold_20ptFontInfo;

static const nrf_lcd_t * p_lcd = &nrf_lcd_st7789;

static const nrf_gfx_line_t cross_line = NRF_GFX_LINE(CROSS_LINE_XL,CROSS_LINE_HEIGHT,CROSS_LINE_XR,CROSS_LINE_HEIGHT,CROSS_LINE_WIDTH);


//uint16_t font_char_buffer[18240]; //for rewriting nrf_gfx library
    //normally it reads each bit from the font files and writes that specific pixel
    //this ignores the frame buffer and updates the screen ram after each pixel is written
    //to use buffer, each pixel's color will need to be stored into an element of an array
//POSSIBLY just store bool (byte) to determine between font color or background color
//POSSIBLYPOSSIBLY check the bits after command RAMWR and send data over with if-else statement or something
    //then pass that array over SPI to LCD so it's all written into frame buffer
    //this SHOULD reduce screen flickering/ tearing/ visible updating by a lot
    //this will take up a large amount of RAM space to do, something like up to 16Kb
    //unsures: 
    //-if speed of processor is able to load every char's data into array in a timely manner
    //-if new code/ functions can be added/ implemented (ie dummy display function in nrf_lcd.h)
    //-if nrf_gfx.c will need to be rewritten to make this function
    //idea gotten from: https://kbiva.wordpress.com/2016/12/10/nokia-6020-lcd-using-framebuffer/ 
    //video showing potential impact: https://youtu.be/718ShQZI2rg/ 


void timer_init(void);
void gpiote_init(void);
void timer_handler(nrf_timer_event_t event_type, void * p_context);
void gpiote_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void backlight_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
void backlight(bool on);
static void gfx_init(bool bl_off);
static void text_print(char * string, uint16_t color, uint16_t xpos, uint16_t ypos, const nrf_gfx_font_desc_t * p_font);
static void text_print_fast(char * string, uint16_t bg_color, uint16_t font_color, uint16_t xpos, uint16_t ypos, const nrf_gfx_font_desc_t * p_font);
void screen_clear(uint16_t color);
static void line_draw(void);
void draw_rectangle(nrf_gfx_rect_t rect, uint16_t color);
void update_timer(void);
void project2_example(void);
void project1_example(void);

void timer_init(void){

  uint32_t time_ticks = TIMER_TICKS;  //123;
  ret_code_t err_code;
  
  nrf_drv_timer_config_t timer_cfg;
  timer_cfg.frequency          = (nrf_timer_frequency_t)TIMER_DEFAULT_CONFIG_FREQUENCY;
  timer_cfg.mode               = (nrf_timer_mode_t)TIMER_DEFAULT_CONFIG_MODE;        
  timer_cfg.bit_width          = (nrf_timer_bit_width_t)TIMER_DEFAULT_CONFIG_BIT_WIDTH;
  timer_cfg.interrupt_priority = TIMER_DEFAULT_CONFIG_IRQ_PRIORITY;                  
  timer_cfg.p_context          = NULL;                                                 

  err_code = nrf_drv_timer_init(&timer_1hz, &timer_cfg, timer_handler);
  APP_ERROR_CHECK(err_code);

  nrf_drv_timer_extended_compare(&timer_1hz, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);

  nrf_drv_timer_enable(&timer_1hz);

  printf("Timer initialized.\n");
}

void timer_handler(nrf_timer_event_t event_type, void* p_context){
    timer_event++;
    global_timer++;

    if(timer_event % (TIMER_SECOND / 4) == 0){
        if(selector_flashing){
            if(selector_drawn){
                draw_rectangle(sel_rect[sel_rect_no], BLACK);
                //p_lcd->lcd_rect_draw(74,186,46,6,BACKGROUND_COLOR);
                selector_drawn = false;
            }
            else{
                draw_rectangle(sel_rect[sel_rect_no], BACKGROUND_COLOR);
                //p_lcd->lcd_rect_draw(74,186,46,6,BLACK);
                selector_drawn = true;
            }
        }
    }

    if(update_turn_order){
        update_turn_order = false;
        switch(turn_order){
            case turn_attack:   //0
                draw_rectangle(Selector_retreat_rect, BACKGROUND_COLOR);
                APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Selector_attack_rect, &Selector_arrow_240x240));

                //draw_rectangle(attack_inner_rect, BLACK);
                for(int i = 0; i < 4; i++){//doesn't need left
                    draw_rectangle(attack_inner_rects[i], BLACK);
                }
                text_print_fast(attack, BLACK, BACKGROUND_COLOR, 18, 108, project1_font);

                //draw_rectangle(retreat_inner_rect, BACKGROUND_COLOR);
                for(int i = 0; i < 4; i++){ //doesn't need right
                    draw_rectangle(retreat_inner_rects[i], BACKGROUND_COLOR);
                }
                text_print_fast(retreat, BACKGROUND_COLOR, BLACK, 118, 108, project1_font);
                
                sel_rect_no++;
                sel_rect_no %= 4;
                if(sel_rect_no > 0){
                    draw_rectangle(sel_rect[sel_rect_no - 1], BACKGROUND_COLOR);
                }
                else{
                    draw_rectangle(sel_rect[3], BACKGROUND_COLOR);
                }
                draw_rectangle(sel_rect[sel_rect_no], BLACK);
                break;
            case turn_retreat:  //1
                draw_rectangle(Selector_attack_rect, BACKGROUND_COLOR);
                APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Selector_retreat_rect, &Selector_arrow_240x240));

                //draw_rectangle(attack_inner_rect, BACKGROUND_COLOR);
                for(int i = 0; i < 4; i++){ //doesn't need right
                    draw_rectangle(attack_inner_rects[i], BACKGROUND_COLOR);
                }
                text_print_fast(attack, BACKGROUND_COLOR, BLACK, 18, 108, project1_font);
                
                //draw_rectangle(retreat_inner_rect, BLACK);
                for(int i = 0; i < 4; i++){ //doesn't need left
                    draw_rectangle(retreat_inner_rects[i], BLACK);
                }
                text_print_fast(retreat, BLACK, BACKGROUND_COLOR, 118, 108, project1_font);
                break;
            default:
                break;
        }
    }

const nrf_gfx_rect_t sel_rect[] = { NRF_GFX_RECT(24, 186, 46, 6),
                                    NRF_GFX_RECT(74, 186, 46, 6),
                                    NRF_GFX_RECT(124, 186, 46, 6),
                                    NRF_GFX_RECT(174, 186, 46, 6)};
uint8_t sel_rect_no = 0;

  if(timer_event % TIMER_SECOND == 0){ //1 second occurrence
    timer_event = 0;
    seconds_timer++;
    printf("\nseconds timer: %d\n",seconds_timer);

    /*colon_state = !colon_state;
    uint32_t colon_color = BLACK;

    if(colon_state){
      printf("colon on\n");
    }
    else{
      colon_color = LIGHT_YELLOW;
      printf("colon off\n");
    }

    text_print(&colon, colon_color, XPOS_TIMER + XOFFSET_COLON, YPOS_TIMER, timer_font);//*/

    if(counting){
        prev_second_ones[0] = second_ones[0];
        if(count_direction){
          second_ones[0]++;
        }
        else{
          second_ones[0]--;
        }
        flag_second_ones = true;
        if(second_ones[0] == 58){  //":"
            second_ones[0] = 48; //"0"
            prev_second_tens[0] = second_tens[0];
            second_tens[0]++;
            flag_second_tens = true;
            if(second_tens[0] == 54){  //"6"
                second_tens[0] = 48; //"0"
                prev_minute_ones[0] = minute_ones[0];
                minute_ones[0]++;
                flag_minute_ones = true;
                if(minute_ones[0] == 58){  //":"
                    minute_ones[0] = 48; //"0"
                    prev_minute_tens[0] = minute_tens[0];
                    minute_tens[0]++;
                    flag_minute_tens = true;
                    if(minute_tens[0] == 58){  //":"
                        minute_tens[0] = 48; //"0"
                    }
                }
            }
        }
        else if(second_ones[0] == 47){  //"/"
            second_ones[0] = 57;  //"9"
            prev_second_tens[0] = second_tens[0];
            second_tens[0]--;
            flag_second_tens = true;
            if(second_tens[0] == 47){ //"/"
                second_tens[0] = 53;  //"5"
                prev_minute_ones[0] = prev_minute_ones[0];
                minute_ones[0]--;
                flag_minute_ones = true;
                if(minute_ones[0] == 47){ //"/"
                    minute_ones[0] = 57;  //"9"
                    prev_minute_tens[0] = minute_tens[0];
                    minute_tens[0]--;
                    flag_minute_tens = true;
                    if(minute_tens[0] == 47){ //"/
                        minute_tens[0] = 57;  //"9"
                    }
                }
            }
        }
        update_timer();
    }
  }
  if(button_read == false){
      button_tracker++;
      if(button_tracker > 25){
          turn_order++;
          turn_order %= 2;
          update_turn_order = true;
          button_read = true;
      }
  }
  else{
      button_tracker = 0;
  }
}


static void gfx_init(bool bl_on)
{
    APP_ERROR_CHECK(nrf_gfx_init(p_lcd));
    nrf_gfx_rotation_set(p_lcd, NRF_LCD_ROTATE_270);
    screen_clear(BLACK);
    backlight(bl_on);
    screen_clear(WHITE);
}

static void text_print(char * string, uint16_t color, uint16_t xpos, uint16_t ypos, const nrf_gfx_font_desc_t * p_font)
{
    nrf_gfx_point_t text_start = NRF_GFX_POINT(xpos, ypos);
    APP_ERROR_CHECK(nrf_gfx_print(p_lcd, &text_start, color, string, p_font, true));
}

static void text_print_fast(char * string, uint16_t bg_color, uint16_t font_color, uint16_t xpos, uint16_t ypos, const nrf_gfx_font_desc_t * p_font)
{
    nrf_gfx_point_t text_start = NRF_GFX_POINT(xpos, ypos);
    APP_ERROR_CHECK(nrf_gfx_print_fast(p_lcd, &text_start, bg_color, font_color, string, p_font, true));
}

void screen_clear(uint16_t color)
{
    nrf_gfx_rect_t screen = NRF_GFX_RECT(0,0,240,240);
    draw_rectangle(screen, color);
}

static void line_draw(void)
{
    nrf_gfx_line_t my_line = NRF_GFX_LINE(0, 0, 0, nrf_gfx_height_get(p_lcd), 2);
    nrf_gfx_line_t my_line_2 = NRF_GFX_LINE(nrf_gfx_width_get(p_lcd), nrf_gfx_height_get(p_lcd), 0, nrf_gfx_height_get(p_lcd), 1);

    for (uint16_t i = 0; i <= nrf_gfx_width_get(p_lcd); i += LINE_STEP)
    {
        my_line.x_end = i;
        APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &my_line, RED));
    }

    my_line.x_end = nrf_gfx_width_get(p_lcd);

    for (uint16_t i = 0; i <= nrf_gfx_height_get(p_lcd); i += LINE_STEP)
    {
        my_line.y_end = (nrf_gfx_height_get(p_lcd) - i);
        APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &my_line, RED));
    }

    for (uint16_t i = 0; i <= nrf_gfx_height_get(p_lcd); i += LINE_STEP)
    {
        my_line_2.y_end = (nrf_gfx_height_get(p_lcd) - i);
        APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &my_line_2, BLUE));
    }

    my_line_2.y_end = 0;

    for (uint16_t i = 0; i <= nrf_gfx_width_get(p_lcd); i += LINE_STEP)
    {
        my_line_2.x_end = i;
        APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &my_line_2, BLUE));
    }
}

void draw_rectangle(nrf_gfx_rect_t rect, uint16_t color)
{
    p_lcd->lcd_rect_draw(rect.x, rect.y, rect.width, rect.height, color);
}

void update_timer(void)
{
    if(flag_minute_tens){
      flag_minute_tens = false;
      if((minute_tens[0] == 51 || minute_tens[0] == 49) && count_direction == false)
      {   //'3' or '1', and counting down
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_MINUTE_TENS + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      else if((minute_tens[0] == 53 || minute_tens[0] == 49) && count_direction)
      {   //'5' or '1', and counting up
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_MINUTE_TENS + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      text_print_fast(minute_tens, BACKGROUND_COLOR, TIMER_COLOR, XPOS_TIMER + XOFFSET_MINUTE_TENS, YPOS_TIMER, timer_font);
    }
    if(flag_minute_ones){
      flag_minute_ones = false;
      if((minute_ones[0] == 51 || minute_ones[0] == 49) && count_direction == false)
      {   //'3' or '1', and counting down
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_MINUTE_ONES + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      else if((minute_ones[0] == 53 || minute_ones[0] == 49) && count_direction)
      {   //'5' or '1', and counting up
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_MINUTE_ONES + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      text_print_fast(minute_ones, BACKGROUND_COLOR, TIMER_COLOR, XPOS_TIMER + XOFFSET_MINUTE_ONES, YPOS_TIMER, timer_font);
      if(minute_ones[0] == 52)
      {   //'4'
          text_print((char *)colon, TIMER_COLOR, XPOS_TIMER + XOFFSET_COLON, YPOS_TIMER, timer_font);
      }
    }
    if(flag_second_tens){
      flag_second_tens = false;
      if((second_tens[0] == 51 || second_tens[0] == 49) && count_direction == false)
      {   //'3' or '1', and counting down
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_SECOND_TENS + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      else if((second_tens[0] == 53 || second_tens[0] == 49) && count_direction)
      {   //'5' or '1', and counting up
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_SECOND_TENS + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      text_print_fast(second_tens, BACKGROUND_COLOR, TIMER_COLOR, XPOS_TIMER + XOFFSET_SECOND_TENS, YPOS_TIMER, timer_font);
    }
    if(flag_second_ones){
      flag_second_ones = false;
      if((second_ones[0] == 51 || second_ones[0] == 49) && count_direction == false)
      {   //'3' or '1', and counting down
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_SECOND_ONES + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      else if(((second_ones[0] == 53 || second_ones[0] == 49) && count_direction))
      {   //'5' or '1', and counting up
          p_lcd->lcd_rect_draw(XPOS_TIMER + XOFFSET_SECOND_ONES + LETTER_SIZE * 5/8, YPOS_TIMER, LETTER_SIZE*3/8+1, LETTER_HEIGHT, BACKGROUND_COLOR);
      }
      text_print_fast(second_ones, BACKGROUND_COLOR, TIMER_COLOR, XPOS_TIMER + XOFFSET_SECOND_ONES, YPOS_TIMER, timer_font);
    }
    printf("Timer updated\n");
}

void project2_example(void)
{
    global_timer = 0;
    count_direction = false;
    seconds_timer = 0;
    timer_event = 0;

    global_timer = 0;
    APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Battery_rect, &Battery_full));
    printf("draw battery: %d\n",global_timer);

    global_timer = 0;
    APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Connect_rect, &Connect_yes));
    printf("draw connect: %d\n",global_timer);

    global_timer = 0;
    APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Speaker_rect, &Speaker_on));
    printf("draw speaker: %d\n",global_timer);

    global_timer = 0;
    APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &cross_line, BLACK));
    printf("cross line: %d\n",global_timer);

    global_timer = 0;
    text_print((char *)timer_text, BLACK, XPOS_TIMER_TEXT, YPOS_TIMER_TEXT, small_text_font);
    printf("Timer: %d\n",global_timer);

    global_timer = 0;
    text_print(subject_text, BLACK, XPOS_SUBJECT_TEXT, YPOS_SUBJECT_TEXT, subject_font);
    printf("subject text: %d\n",global_timer);

    global_timer = 0;
    text_print((char *)colon, TIMER_COLOR, XPOS_TIMER + XOFFSET_COLON, YPOS_TIMER, timer_font);
    update_timer();
    printf("timer starting up...\n");
    
    counting = true;
}

void project1_example(void)
{
    global_timer = 0;

    nrf_gfx_line_t player_h = NRF_GFX_LINE(24,192,220,192,4);
    APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &player_h, BLACK));
    nrf_gfx_line_t player_v = NRF_GFX_LINE(70,180,70,28,4);
    for(int i = 0; i < 3; i++)
    {
        APP_ERROR_CHECK(nrf_gfx_line_draw(p_lcd, &player_v, BLACK));
        player_v.x_start = player_v.x_end += 50;
    }
  
    draw_rectangle(attack_outer_rect, BLACK);
    //draw_rectangle(attack_inner_rect, WHITE);
    draw_rectangle(retreat_outer_rect, BLACK);
    draw_rectangle(retreat_inner_rect, WHITE);
    
    text_print_fast(attack, BLACK, BACKGROUND_COLOR, 18, 108, project1_font);
    text_print_fast(retreat, BACKGROUND_COLOR, BLACK, 118, 108, project1_font);

    char playerno[] = "P2";
    static const nrf_gfx_font_desc_t * project1_playerno_font = &arial_bold_42ptFontInfo;
    text_print_fast(playerno, BACKGROUND_COLOR, LIGHT_SKY_BLUE, 10, 10, project1_playerno_font);

    static const nrf_gfx_font_desc_t * project1_scores_font = &arial_bold_28ptFontInfo;
    char scores[] = "07";

    for(int i = 0; i < 4; i++)
    {
        if(scores[0] == 49 && scores[1] == 55)
        {
            scores[0] = 48;
            scores[1] = 57;
        }
        text_print_fast(scores, BACKGROUND_COLOR, player_colors[i], 26+i*50, 200, project1_scores_font);
        scores[1]+= 5;
        if(scores[1] > 57)
        {
            scores[1] -= 10;
            scores[0]++;
        }
    }

    nrf_gfx_rect_t Connect_rect = NRF_GFX_RECT(80, Connect_y, Connect_w, Connect_h);
    APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Connect_rect, &Connect_yes));

    nrf_gfx_rect_t dot_bar_box = NRF_GFX_RECT(158,16,15,30);
    for(int i = 0; i < 4; i++){
        draw_rectangle(dot_bar_box, BLACK);
        dot_bar_box.x += 18;
    }

    char players[] = "P1";
    static const nrf_gfx_font_desc_t * project1_players_font = &arial_24ptFontInfo;
    for(int i = 0; i < 4; i++)
    {
      text_print_fast(players, BACKGROUND_COLOR, player_colors[i], 30+i*50, 160, project1_players_font);
      players[1]++;
    }

    APP_ERROR_CHECK(nrf_gfx_bmp565_draw_big_endian(p_lcd, &Selector_attack_rect, &Selector_arrow_240x240));

    selector_drawn = true;

    selector_flashing = true;
}

int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    //printf("This a GFX usage example application.\n");

    timer_init();
    gpiote_init();

    gfx_init(true);

    //project2_example();
    project1_example();
    backlight(true);

    nrf_drv_gpiote_in_event_enable(BUTTON_4_PIN, NRF_GPIOTE_POLARITY_TOGGLE);   //enables interrupt on button 4

    while (1)
    {
       
    }
}

void gpiote_init(void)    //initialize GPIOTE
{
    ret_code_t err_code;
  
    err_code = nrf_drv_gpiote_init();   //initializes the GPIOTE for use
    APP_ERROR_CHECK(err_code);

    nrf_gpio_cfg_output(LCD_BL_PIN);
    backlight(true);

    nrf_gpio_cfg_input(BUTTON_4_PIN, NRF_GPIO_PIN_PULLUP);

    nrf_gpio_cfg_input(BUTTON_1_PIN, NRF_GPIO_PIN_PULLUP);

    nrf_drv_gpiote_in_config_t pin_config; //configuration of input pin
    pin_config.sense = NRF_GPIOTE_POLARITY_TOGGLE;      /**< Transition that triggers interrupt. */
    pin_config.pull = NRF_GPIO_PIN_PULLUP;       /**< Pulling mode. */
    pin_config.is_watcher = false; /**< True when the input pin is tracking an output pin. */
    pin_config.hi_accuracy = false;/**< True when high accuracy (IN_EVENT) is used. */

    err_code = nrf_drv_gpiote_in_init(BUTTON_4_PIN, &pin_config, gpiote_handler);
    APP_ERROR_CHECK(err_code);

//    nrf_drv_gpiote_in_event_enable(BUTTON_4_PIN, pin_config.sense);   //enables interrupt on button 4
}

void gpiote_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    button_read = nrf_gpio_pin_read(BUTTON_4_PIN);
}

void backlight(bool on)
{
    if(on){
        nrf_gpio_pin_set(LCD_BL_PIN);
        backlight_state = true;
    }
    else{
        nrf_gpio_pin_clear(LCD_BL_PIN);
        backlight_state = false;
    }
}