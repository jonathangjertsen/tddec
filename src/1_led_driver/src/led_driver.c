#include <led_driver.h>

#include <stdint.h>

static uint16_t *g_address;

void LED_Create(uint16_t *address)
{
    g_address = address;
    *g_address = 0;
}

void LED_On(unsigned ledNumber)
{
    *g_address |= (1 << ledNumber);
}

void LED_Off(unsigned ledNumber)
{
    *g_address &=~ (1 << ledNumber);
}
