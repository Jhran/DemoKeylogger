#ifndef _KEYBOARD_DECODE_H
#define _KEYBOARD_DECODE_H

#include "Decoder/hid_queue/hid_queue.h"
#include "configKeylogger.h"

typedef struct __attribute__((packed)) _keyboard_data_t
{
    char modifier[2];
    char key[6];
} keyboard_data_t;

void keyboard_send_modifter_key_state(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata);
void keyboard_send_normal_key_state(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata);
void keyboard_send_all_key_state(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata);
keylogger_err_t keyboard_key_code_to_ascii(char key_code, int key_type, char *out_key_name, int length);

#endif