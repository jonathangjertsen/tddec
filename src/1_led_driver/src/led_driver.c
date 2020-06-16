#include <led_driver.h>
#include <error_handler.h>

#include <stdint.h>
#include <stdbool.h>

const int LED_MIN = 0;
const int LED_MAX = 16;

static uint16_t *g_address;
static uint16_t g_image = 0;

static bool isValidLed(unsigned ledNumber)
{
    return (ledNumber >= 0) && (ledNumber < 16);
}

void LED_Create(uint16_t *address)
{
    g_image = 0;
    g_address = address;
    *g_address = g_image;
}

void LED_On(unsigned ledNumber)
{
    if (isValidLed(ledNumber))
    {
        g_image |= (1 << ledNumber);
    }
    else
    {
        ERROR("LED out of bounds", ledNumber);
    }
    *g_address = g_image;
}

void LED_Off(unsigned ledNumber)
{
    if (isValidLed(ledNumber))
    {
        g_image &=~ (1 << ledNumber);
    }
    else
    {
        ERROR("LED out of bounds", ledNumber);
    }
    *g_address = g_image;
}

bool LED_IsOn(unsigned ledNumber)
{
    if (isValidLed(ledNumber))
    {
        return g_image & (1 << ledNumber);
    }
    else
    {
        ERROR("LED out of bounds", ledNumber);
        return false;
    }
}
