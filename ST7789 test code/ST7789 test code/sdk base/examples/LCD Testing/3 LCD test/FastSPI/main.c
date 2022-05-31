/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
* @brief Example template project.
* @defgroup nrf_templates_example Example Template
*
*/

#include <stdint.h>
#include <stdbool.h>
#include "boards.h"
#include "nrf_gpio.h"
#include "spi_master_fast.h"
#include "nrf_delay.h"

#define SPI_PACKET_LENGTH 16

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Set up TX and RX buffers
    uint8_t tx_buf[SPI_PACKET_LENGTH];
    uint8_t rx_buf[SPI_PACKET_LENGTH];
    
    // Put an incrementing value in the TX buffer (0, 1, 2, ....., N-1)
    for(int i = 0; i < SPI_PACKET_LENGTH; i++) tx_buf[i] = i;
    
    // Use LED_1 as a status LED
    nrf_gpio_cfg_output(LED_1);
    
    // Set up the SPI configuration parameters
    SPI_config_t spi_config =  {.pin_SCK                 = 1, 
                                .pin_MOSI                = 2, 
                                .pin_MISO                = 3, 
                                .pin_CSN                 = 4,  
                                .frequency               = SPI_FREQ_4MBPS, 
                                .config.fields.mode      = 0, 
                                .config.fields.bit_order = SPI_BITORDER_MSB_LSB};
    
    // Initialize the SPI
    spi_master_init(SPI0, &spi_config);
    
    while (true)
    {
        // Run a single, blocking SPI transaction 
        spi_master_tx_rx(SPI0, SPI_PACKET_LENGTH, tx_buf, rx_buf);
        
        nrf_gpio_pin_toggle(LED_1);
        nrf_delay_ms(100);
    }
}
/** @} */
