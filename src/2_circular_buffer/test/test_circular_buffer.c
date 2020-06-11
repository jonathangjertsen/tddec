#include <circular_buffer.h>
#include <unity.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SIZE 800

int g_data[DATA_SIZE];
static cbuf_t g_cbuf;

void setUp(void)
{
    g_cbuf = CBUF_Init(g_data, DATA_SIZE);
}

void test_emptyAtInit(void)
{
    TEST_ASSERT_TRUE(CBUF_IsEmpty(&g_cbuf));
}

void test_sizeIsZeroAtInit(void)
{
    TEST_ASSERT_EQUAL(0, CBuf_Size(&g_cbuf));
}

void test_putInEmptyBufferResultsInTrueResult(void)
{
    bool putResult = CBUF_Put(&g_cbuf, 1);
    TEST_ASSERT_EQUAL(true, putResult);
}
