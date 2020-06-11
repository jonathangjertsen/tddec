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

void test_notFullAtInit(void)
{
    TEST_ASSERT_FALSE(CBUF_IsFull(&g_cbuf));
}

void test_sizeIsZeroAtInit(void)
{
    TEST_ASSERT_EQUAL(0, CBUF_Size(&g_cbuf));
}

void test_remainingCapacityIsCorrectAtInit(void)
{
    TEST_ASSERT_EQUAL(DATA_SIZE, CBUF_RemainingCapacity(&g_cbuf));
}

void test_putInEmptyBufferResultsInTrueResult(void)
{
    bool putResult = CBUF_Put(&g_cbuf, 1);
    TEST_ASSERT_EQUAL(true, putResult);
}

void test_getFromEmptyBufferResultsInFalseResultAndValueIsNotOverwritten(void)
{
    int value = -192;
    bool putResult = CBUF_Get(&g_cbuf, &value);

    TEST_ASSERT_FALSE(putResult);
    TEST_ASSERT_EQUAL(value, -192);
}

void test_peekFromEmptyBufferResultsInFalseResultAndValueIsNotOverwritten(void)
{
    int value = -192;
    bool putResult = CBUF_Peek(&g_cbuf, &value);

    TEST_ASSERT_FALSE(putResult);
    TEST_ASSERT_EQUAL(value, -192);
}

void test_getReturnsResultFromPut(void)
{
    CBUF_Put(&g_cbuf, 1337);

    int value = 0;
    CBUF_Get(&g_cbuf, &value);
    TEST_ASSERT_EQUAL(value, 1337);
}

void test_putIncrementsSize(void)
{
    CBUF_Put(&g_cbuf, 1337);
    TEST_ASSERT_EQUAL(1, CBUF_Size(&g_cbuf));
}

void test_putDecrementsCapacity(void)
{
    CBUF_Put(&g_cbuf, 1337);
    TEST_ASSERT_EQUAL(DATA_SIZE - 1, CBUF_RemainingCapacity(&g_cbuf));
}

void test_putFalsifiesIsEmpty(void)
{
    CBUF_Put(&g_cbuf, 1337);
    TEST_ASSERT_FALSE(CBUF_IsEmpty(&g_cbuf));
}

void test_getDecrementsSize(void)
{
    CBUF_Put(&g_cbuf, 1337);
    int dummy;
    CBUF_Get(&g_cbuf, &dummy);

    TEST_ASSERT_EQUAL(0, CBUF_Size(&g_cbuf));
}

void test_getIncrementsCapacity(void)
{
    CBUF_Put(&g_cbuf, 1337);
    int dummy;
    CBUF_Get(&g_cbuf, &dummy);

    TEST_ASSERT_EQUAL(DATA_SIZE, CBUF_RemainingCapacity(&g_cbuf));
}

void test_getDoesNotDecrementSizeIfEmpty(void)
{
    int dummy;
    CBUF_Get(&g_cbuf, &dummy);

    TEST_ASSERT_EQUAL(0, CBUF_Size(&g_cbuf));
}

void test_getDoesNotIncrementCapacityIfEmpty(void)
{
    int dummy;
    CBUF_Get(&g_cbuf, &dummy);

    TEST_ASSERT_EQUAL(DATA_SIZE, CBUF_RemainingCapacity(&g_cbuf));
}

void test_peekReturnsResultFromPut(void)
{
    CBUF_Put(&g_cbuf, 1337);

    int value = 0;
    CBUF_Peek(&g_cbuf, &value);
    TEST_ASSERT_EQUAL(value, 1337);
}

void test_peekIsIdempotent(void)
{
    CBUF_Put(&g_cbuf, 1337);

    int value = 0;
    CBUF_Peek(&g_cbuf, &value);
    value = 0;
    CBUF_Peek(&g_cbuf, &value);
    TEST_ASSERT_EQUAL(value, 1337);
}

void test_peekDoesNotChangeSizeOrCapacity(void)
{
    CBUF_Put(&g_cbuf, 1337);

    int value = 0;
    CBUF_Peek(&g_cbuf, &value);
    TEST_ASSERT_EQUAL(1, CBUF_Size(&g_cbuf));
    TEST_ASSERT_EQUAL(DATA_SIZE - 1, CBUF_RemainingCapacity(&g_cbuf));
}

