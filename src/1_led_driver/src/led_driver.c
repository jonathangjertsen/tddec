#include <led_driver.h>

#include <stdint.h>

static uint16_t *g_address;
static uint16_t g_image = 0;

void LED_Create(uint16_t *address)
{
    g_image = 0;
    g_address = address;
    *g_address = g_image;
}

void LED_On(unsigned ledNumber)
{
    g_image |= (1 << ledNumber);
    *g_address = g_image;
}

void LED_Off(unsigned ledNumber)
{
    g_image &=~ (1 << ledNumber);
    *g_address = g_image;
}
