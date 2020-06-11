#include <led_driver.h>
#include <unity.h>
#include <stdint.h>

void test_offAfterCreate(void)
{
    uint16_t virtualLeds = 0xffff;
    LED_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_turnOn(void)
{
    uint16_t virtualLeds;
    LED_Create(&virtualLeds);
    LED_On(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);
}

void test_turnOff(void)
{
    uint16_t virtualLeds;
    LED_Create(&virtualLeds);
    LED_On(1);
    LED_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}
