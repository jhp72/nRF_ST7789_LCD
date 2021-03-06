// Generated by  : ImageConverter 565 v2.2
// Date generated: 9/27/2018
//Downloaded from: https://www.14core.com/c-array-generator/ 
//Byte order: Big Endian

#ifndef SYMBOLS_H__
#define SYMBOLS_H__

#include "nrf_gfx.h"

#define Battery_x   94
#define Battery_y   8
#define Battery_h   15
#define Battery_w   32

#define Connect_x   6
#define Connect_y   6
#define Connect_h   22
#define Connect_w   32

#define Speaker_x   55
#define Speaker_y   4
#define Speaker_h   26
#define Speaker_w   22

nrf_gfx_rect_t Battery_rect = NRF_GFX_RECT(Battery_x, Battery_y, Battery_w, Battery_h);
nrf_gfx_rect_t Connect_rect = NRF_GFX_RECT(Connect_x, Connect_y, Connect_w, Connect_h);
nrf_gfx_rect_t Speaker_rect = NRF_GFX_RECT(Speaker_x, Speaker_y, Speaker_w, Speaker_h);

#define Battery_full_height 15
#define Battery_full_width  32

const uint16_t Battery_full[] = {
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0010 (16)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0020 (32)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0030 (48)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0040 (64)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0050 (80)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0060 (96)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0070 (112)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0080 (128)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0090 (144)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00A0 (160)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x00B0 (176)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00C0 (192)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x00D0 (208)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00E0 (224)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x00F0 (240)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0100 (256)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0110 (272)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0120 (288)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0130 (304)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0140 (320)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0150 (336)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0160 (352)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0170 (368)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0180 (384)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0190 (400)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01A0 (416)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01C0 (448)
    
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01D0 (464)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01E0 (480)
};

#define Battery_mid_height  15
#define Battery_mid_width   32

const uint16_t Battery_mid[] ={
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0010 (16)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0020 (32)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0030 (48)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0040 (64)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA,   // 0x0050 (80)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0060 (96)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA,   // 0x0070 (112)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0080 (128)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4,   // 0x0090 (144)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00A0 (160)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4,   // 0x00B0 (176)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00C0 (192)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4,   // 0x00D0 (208)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00E0 (224)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x20E4,   // 0x00F0 (240)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0100 (256)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x20E4,   // 0x0110 (272)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0120 (288)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x20E4, 0x20E4,   // 0x0130 (304)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0140 (320)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4,   // 0x0150 (336)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0160 (352)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0170 (368)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0180 (384)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0190 (400)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01A0 (416)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01C0 (448)
    
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01D0 (464)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01E0 (480)
};

#define Battery_low_height  15
#define Battery_low_width   32

const uint16_t Battery_low[] ={
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0010 (16)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0020 (32)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0030 (48)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0040 (64)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA,   // 0x0050 (80)
    0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0060 (96)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0080 (128)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0090 (144)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00A0 (160)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00C0 (192)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00D0 (208)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x00E0 (224)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0100 (256)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0110 (272)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0120 (288)
    
    0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0130 (304)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0140 (320)
    
    0x9471, 0x9471, 0x9471, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0150 (336)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0160 (352)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638, 0xC638,   // 0x0170 (368)
    0xC638, 0xC638, 0xC638, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x0180 (384)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0190 (400)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01A0 (416)
    
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9471,   // 0x01C0 (448)
    
    0xFFFF, 0xFFFF, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01D0 (464)
    0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x01E0 (480)
};

#define Connect_yes_height  22
#define Connect_yes_width   32

const uint16_t Connect_yes[] ={
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x9CF3, 0x9CF3, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48)
    0xD6BA, 0xC638, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x20E4, 0x20E4, 0x20E4, 0x2965, 0x9471, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471,   // 0x0050 (80)
    0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x2965, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x39C7, 0xBDD7, 0xFFFF, 0xFFFF, 0x9471, 0x20E4,   // 0x0070 (112)
    0x20E4, 0x2965, 0x20E4, 0x20E4, 0x20E4, 0x8410, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0x738E, 0x20E4, 0x20E4, 0xD6BA, 0xF79E, 0x738E, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xC638, 0x20E4, 0x20E4,   // 0x0090 (144)
    0x632C, 0xFFFF, 0xAD55, 0x39C7, 0x20E4, 0x20E4, 0x2965, 0x9CF3, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00A0 (160)
    
    0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x9471, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x2965,   // 0x00B0 (176)
    0xF79E, 0xFFFF, 0xFFFF, 0xF79E, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x4A49, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00C0 (192)
    
    0xFFFF, 0xFFFF, 0x4A49, 0x20E4, 0x39C7, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x2965, 0x20E4, 0x20E4, 0x2965,   // 0x00D0 (208)
    0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x632C, 0x20E4, 0x20E4, 0x20E4, 0x632C, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224)
    
    0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x39C7, 0x20E4, 0x20E4, 0x20E4,   // 0x00F0 (240)
    0x20E4, 0x4A49, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x39C7, 0x20E4, 0x20E4, 0x2965, 0x9471, 0xF79E, 0xFFFF, 0xFFFF,   // 0x0100 (256)
    
    0xE71C, 0x2965, 0x20E4, 0x632C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xAD55, 0x5AAA,   // 0x0110 (272)
    0x20E4, 0x20E4, 0x20E4, 0x8410, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x2965, 0x20E4, 0x20E4, 0x39C7, 0xBDD7, 0xFFFF,   // 0x0120 (288)
    
    0xC638, 0x20E4, 0x2965, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x738E, 0xFFFF, 0xFFFF,   // 0x0130 (304)
    0xBDD7, 0x39C7, 0x20E4, 0x20E4, 0x9471, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x738E, 0x20E4, 0x20E4, 0x20E4, 0xC638,   // 0x0140 (320)
    
    0x9CF3, 0x20E4, 0x39C7, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x2965, 0x20E4, 0x9CF3, 0xFFFF, 0xFFFF,   // 0x0150 (336)
    0xFFFF, 0xFFFF, 0x738E, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x2965, 0x20E4, 0x738E,   // 0x0160 (352)
    
    0xD6BA, 0x2965, 0x20E4, 0x39C7, 0xBDD7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x738E, 0x20E4, 0x20E4, 0x8410, 0xF79E,   // 0x0170 (368)
    0xFFFF, 0xFFFF, 0xBDD7, 0x20E4, 0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4A49, 0x20E4, 0x5AAA,   // 0x0180 (384)
    
    0xFFFF, 0xAD55, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x4A49, 0x20E4, 0x20E4, 0x2965,   // 0x0190 (400)
    0x9CF3, 0xFFFF, 0x4A49, 0x20E4, 0x5AAA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xBDD7, 0x20E4, 0x20E4, 0xAD55,   // 0x01A0 (416)
    
    0xFFFF, 0xFFFF, 0xC638, 0x4A49, 0x20E4, 0x20E4, 0x20E4, 0x8410, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x9471, 0x20E4, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0x2965, 0x20E4, 0x20E4, 0xBDD7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x39C7, 0x20E4, 0x4A49, 0xFFFF,   // 0x01C0 (448)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x2965, 0x20E4, 0x20E4, 0x2965, 0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x5AAA,   // 0x01D0 (464)
    0x20E4, 0x20E4, 0x20E4, 0x2965, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0xC638, 0xFFFF,   // 0x01E0 (480)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x8410, 0x20E4, 0x20E4, 0x20E4, 0x4A49, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01F0 (496)
    0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x2965, 0x9471, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x20E4, 0x20E4, 0x738E, 0xFFFF, 0xFFFF,   // 0x0200 (512)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x738E, 0xF79E, 0xFFFF, 0xC638,   // 0x0210 (528)
    0x20E4, 0x20E4, 0x5AAA, 0x2965, 0x20E4, 0x20E4, 0x39C7, 0xBDD7, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x2965, 0xF79E, 0xFFFF, 0xFFFF,   // 0x0220 (544)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xBDD7, 0x39C7, 0x20E4, 0x20E4, 0x2965, 0x5AAA, 0x2965,   // 0x0230 (560)
    0x20E4, 0x39C7, 0xFFFF, 0xF79E, 0x738E, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0x738E, 0x20E4, 0x20E4, 0x9CF3, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0240 (576)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x2965, 0x20E4, 0x20E4, 0x20E4,   // 0x0250 (592)
    0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x738E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0260 (608)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x9471, 0x5AAA, 0x632C,   // 0x0270 (624)
    0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x632C, 0x5AAA, 0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0280 (640)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0290 (656)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02A0 (672)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02B0 (688)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02C0 (704)
};

#define Connect_no_height  22
#define Connect_no_width   32

const uint16_t Connect_no[] ={
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0010 (16)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x632C, 0x738E, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0030 (48)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8410, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0050 (80)
    0x20E4, 0xFFFF, 0xFFFF, 0xF79E, 0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xD6BA, 0x20E4, 0x20E4, 0x39C7, 0x39C7, 0x20E4, 0x20E4, 0x20E4, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0070 (112)
    0x20E4, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x4A49, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0080 (128)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x2965, 0xF79E, 0xFFFF, 0xAD55, 0x2965, 0x738E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0090 (144)
    0x20E4, 0xFFFF, 0xF79E, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x738E, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00A0 (160)
    
    0xFFFF, 0xFFFF, 0xAD55, 0x20E4, 0x20E4, 0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x00B0 (176)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x39C7, 0x20E4, 0x20E4, 0x2965, 0x9471, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00C0 (192)
    
    0xFFFF, 0xF79E, 0x2965, 0x20E4, 0x5AAA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x00D0 (208)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x2965, 0x20E4, 0x20E4, 0x39C7, 0xBDD7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00E0 (224)
    
    0xFFFF, 0x8410, 0x20E4, 0x20E4, 0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x00F0 (240)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x738E, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xE71C, 0xFFFF, 0xFFFF,   // 0x0100 (256)
    
    0xE71C, 0x20E4, 0x20E4, 0x9471, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0110 (272)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x4A49, 0x20E4, 0x20E4, 0x20E4, 0x8410, 0xFFFF,   // 0x0120 (288)
    
    0xC638, 0x20E4, 0x39C7, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0130 (304)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x2965, 0x20E4, 0x20E4, 0xAD55,   // 0x0140 (320)
    
    0x9471, 0x20E4, 0x2965, 0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0150 (336)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x39C7, 0x20E4, 0x632C,   // 0x0160 (352)
    
    0xF79E, 0x39C7, 0x20E4, 0x20E4, 0x9471, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0170 (368)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x39C7, 0x20E4, 0x632C,   // 0x0180 (384)
    
    0xFFFF, 0xD6BA, 0x2965, 0x20E4, 0x20E4, 0x2965, 0xAD55, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0190 (400)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9CF3, 0x20E4, 0x20E4, 0xC638,   // 0x01A0 (416)
    
    0xFFFF, 0xFFFF, 0xF79E, 0x8410, 0x20E4, 0x20E4, 0x20E4, 0x5AAA, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x2965, 0x20E4, 0x632C, 0xFFFF,   // 0x01C0 (448)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x738E, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x01D0 (464)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x632C, 0x20E4, 0x2965, 0xE71C, 0xFFFF,   // 0x01E0 (480)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xBDD7, 0x39C7, 0x20E4, 0x20E4, 0x2965, 0x9471, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x01F0 (496)
    0x20E4, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x5AAA, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 0x9471, 0xFFFF, 0xFFFF,   // 0x0200 (512)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x9471, 0x2965, 0x20E4, 0x2965, 0xF79E, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0210 (528)
    0x20E4, 0xFFFF, 0xFFFF, 0x632C, 0x20E4, 0x20E4, 0x20E4, 0x8410, 0xF79E, 0xFFFF, 0x39C7, 0x20E4, 0x39C7, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0220 (544)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x632C, 0x9CF3, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0230 (560)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x2965, 0x20E4, 0x20E4, 0x2965, 0x39C7, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0240 (576)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0250 (592)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x8410, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x9CF3, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0260 (608)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0270 (624)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x9CF3, 0x9471, 0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0280 (640)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0290 (656)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02A0 (672)
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x02B0 (688)
    0x20E4, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x02C0 (704)
};

#define Speaker_on_height 26
#define Speaker_on_width  22

const uint16_t Speaker_on[] ={
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16)
    0xFFFF, 0xFFFF, 0xAD55, 0x5AAA, 0xD6BA, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x632C, 0x20E4, 0x4A49, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48)
    0xFFFF, 0xFFFF, 0xD6BA, 0x39C7, 0x5AAA, 0x5AAA, 
    
    0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x39C7, 0x20E4, 0x8410, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x4A49, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0050 (80)
    0x9471, 0x20E4, 0x2965, 0xC638, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x632C, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xE71C, 0x4A49, 0x20E4, 0x632C, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112)
    0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 
    
    0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xC638, 0x2965, 0x9CF3, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xD6BA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF,   // 0x0090 (144)
    0xE71C, 0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176)
    0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 
    
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x00D0 (208)
    0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240)
    0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 
    
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0110 (272)
    0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xC638, 0x20E4, 
    
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x2965, 0xE71C, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xE71C, 0x9471, 0x9471, 0x9471, 0x9471, 0x9471,   // 0x0130 (304)
    0x9471, 0x9471, 0x9CF3, 0xFFFF, 0x20E4, 0x20E4, 
    
    0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4,   // 0x0150 (336)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0170 (368)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x9471, 0xC638, 0xE71C,   // 0x0190 (400)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 
    
    0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xC638, 0x632C,   // 0x01B0 (432)
    0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x39C7, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xD6BA, 0x20E4, 0x2965, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01D0 (464)
    0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x20E4, 0x20E4, 
    
    0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xC638, 0x39C7, 0x20E4, 0x8410, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8410, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF,   // 0x01F0 (496)
    0xFFFF, 0xFFFF, 0xF79E, 0x738E, 0x20E4, 0x4A49, 
    
    0xD6BA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0xC638, 0xC638, 0xC638, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xBDD7, 0x2965, 0x20E4, 0x9CF3, 0xFFFF, 0xFFFF,   // 0x0210 (528)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE71C, 0x5AAA, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0230 (560)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    
    0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0xF79E, 0xFFFF
};

#define Speaker_off_height  26
#define Speaker_off_width   22

const uint16_t Speaker_off[] ={
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0010 (16)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0020 (32)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0030 (48)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xD6BA, 0xC638, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0040 (64)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x20E4, 0x20E4,   // 0x0050 (80)
    0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0060 (96)
    0xFFFF, 0xFFFF, 0xD6BA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0070 (112)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x2965, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF,   // 0x0080 (128)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x4A49, 0x20E4, 0x20E4,   // 0x0090 (144)
    0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9471,   // 0x00A0 (160)
    0x9471, 0xC638, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00B0 (176)
    0x632C, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638,   // 0x00C0 (192)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x5AAA, 0x20E4, 0x5AAA, 0xC638, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4,   // 0x00D0 (208)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x5AAA, 0x20E4,   // 0x00E0 (224)
    0x5AAA, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x00F0 (240)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0x39C7, 0x20E4, 0x20E4, 0x8410, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0100 (256)
    0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x20E4,   // 0x0110 (272)
    0x5AAA, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0120 (288)
    0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x5AAA, 0x39C7, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF,   // 0x0130 (304)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4,   // 0x0140 (320)
    0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4,   // 0x0150 (336)
    0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xBDD7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0160 (352)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x0170 (368)
    0x738E, 0xE71C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4,   // 0x0180 (384)
    0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x632C, 0x2965, 0x2965, 0x9471, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0190 (400)
    0xFFFF, 0x20E4, 0x20E4, 0x9471, 0xC638, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xF79E, 0x9471, 0x2965, 0x2965,   // 0x01A0 (416)
    0x9471, 0xF79E, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC638, 0xC638, 0xE71C, 0xF79E, 0x2965, 0x20E4, 0x20E4, 0x20E4, 0x20E4,   // 0x01B0 (432)
    0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xF79E, 0x9471, 0x2965, 0x5AAA, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x01C0 (448)
    0xFFFF, 0xBDD7, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0xE71C, 0xFFFF, 0xFFFF,   // 0x01D0 (464)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x632C, 0x20E4, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF,   // 0x01E0 (480)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF79E, 0x2965,   // 0x01F0 (496)
    0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0200 (512)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAD55, 0x20E4, 0x20E4, 0x20E4, 0xC638, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0210 (528)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0220 (544)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,   // 0x0230 (560)
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
};

#endif