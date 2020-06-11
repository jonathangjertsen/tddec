#include <led_driver.h>
#include <unity.h>
#include <stdint.h>

static uint16_t virtualLeds;

void setUp(void)
{
    LED_Create(&virtualLeds);
}

void test_offAfterCreate(void)
{
    virtualLeds = 0xffff;
    LED_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_turnOn(void)
{
    LED_On(0);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);
}

void test_turnOnMultiple(void)
{
    LED_On(1);
    LED_On(4);
    LED_On(15);
    TEST_ASSERT_EQUAL_HEX16(0b1000000000010010, virtualLeds);
}

void test_turnOff(void)
{
    LED_On(1);
    LED_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

void test_turnAllOnAndSomeOff(void)
{
    for (int i = 0; i < 16; i++)
    {
        LED_On(i);
    }
    LED_Off(1);
    LED_Off(4);
    LED_Off(15);

    TEST_ASSERT_EQUAL_HEX16(0b0111111111101101, virtualLeds);
}
