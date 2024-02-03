#ifndef _CH9350_DECODE_H
#define _CH9350_DECODE_H

#include "Decoder/Keyboard/keyboard_decode.h"
#include "Decoder/Mouse/mouse_decode.h"

typedef enum{
    OPCODE_TYPE_KEYBOARD=0X01,
    OPCODE_TYPE_RELATIVE_MOUSE=0X02
}CH9350_02_OPCODE;

void CH9350_get_key_data(const char uart_data[], keyboard_data_t *keydata);
void CH9350_get_mouse_data(const char uart_data[], mouse_data_t *mousedata);
bool is_CH9350_key_data(const char uart_data[]);
bool is_CH9350_mouse_data(const char uart_data[]);

typedef struct __attribute__((packed)) _02_CH9350_DATA
{
    uint8_t headers[2];
    uint8_t opcode;
    union{
        keyboard_data_t keys;
        mouse_data_t mouse;
    };
} CH9350_02_DATA;

#endif