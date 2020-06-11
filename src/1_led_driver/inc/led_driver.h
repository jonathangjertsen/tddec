#ifndef LED_H
#define LED_H

#include <stdint.h>

void LED_Create(uint16_t *address);
void LED_On(unsigned ledNumber);
void LED_Off(unsigned ledNumber);

#endif
