#include <circular_buffer.h>
#include <stdbool.h>

cbuf_t CBUF_Init(int *data, int capacity)
{
    cbuf_t cbuf;
    return cbuf;
}

bool CBUF_IsEmpty(cbuf_t *cbuf)
{
    return true;
}

bool CBUF_IsFull(cbuf_t *cbuf)
{
    return false;
}

int CBUF_Size(cbuf_t *cbuf)
{
    return 0;
}

bool CBUF_Put(cbuf_t *cbuf, int value)
{
    return true;
}

bool CBUF_Get(cbuf_t *cbuf, int *value)
{
    return false;
}

bool CBUF_Peek(cbuf_t *cbuf, int *value)
{
    return false;
}
