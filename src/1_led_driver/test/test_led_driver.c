#include <led_driver.h>
#include <error_handler_mock.h>
#include <unity.h>
#include <stdint.h>

static uint16_t virtualLeds;

void setUp(void)
{
    ERROR_ResetMock();

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

void test_turnOnOobValue(void)
{
    LED_On(1);
    LED_On(4);
    LED_On(15);
    LED_On(999);
    TEST_ASSERT_EQUAL_HEX16(0b1000000000010010, virtualLeds);
    TEST_ASSERT_EQUAL(999, ERROR_LastParameter());
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

void test_turnOffOutOfBoundsValue(void)
{
    for (int i = 0; i < 16; i++)
    {
        LED_On(i);
    }
    LED_Off(1337);

    TEST_ASSERT_EQUAL_HEX16(0b1111111111111111, virtualLeds);
    TEST_ASSERT_EQUAL(1337, ERROR_LastParameter());
}

void test_noReadFromAddress(void)
{
    virtualLeds = 0xffff;
    LED_On(4);
    LED_Off(7);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, virtualLeds);
}

