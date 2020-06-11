#include <circular_buffer.h>
#include <unity.h>

void test_emptyAtInit()
{
    int data[800];

    cbuf_t cbuf = CBUF_Init(data, 800);
    TEST_ASSERT_TRUE(CBUF_IsEmpty(&cbuf));
}
