#ifndef _MOUSE_DECODE_H
#define _MOUSE_DECODE_H

#include <stdio.h>

typedef struct __attribute__((packed)) _mouse_data_t
{
    char button;
    char x;
    char y;
    char wheel;
} mouse_data_t;

#endif