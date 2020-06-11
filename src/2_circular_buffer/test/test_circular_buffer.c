#include <circular_buffer.h>
#include <unity.h>

void test_emptyAtInit()
{
    cbuf_t cbuf = CBUF_Init();
    TEST_ASSERT_TRUE(CBUF_IsEmpty(&cbuf));
}