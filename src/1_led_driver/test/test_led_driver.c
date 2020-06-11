#include <led_driver.h>
#include <unity.h>
#include <stdint.h>

void test_offAfterCreate(void)
{
    uint16_t virtualLeds = 0xffff;
    LED_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
