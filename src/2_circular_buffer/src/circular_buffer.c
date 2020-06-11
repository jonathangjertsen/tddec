#include <circular_buffer.h>
#include <stdbool.h>

cbuf_t CBUF_Init(int *data, int capacity)
{
    cbuf_t cbuf = {
        .put = 0,
        .get = 0,
        .capacity = capacity,
        .data = data,
    };
    return cbuf;
}

bool CBUF_IsEmpty(cbuf_t *cbuf)
{
    return cbuf->put == cbuf->get;
}

bool CBUF_IsFull(cbuf_t *cbuf)
{
    return false;
}

int CBUF_Size(cbuf_t *cbuf)
{
    return cbuf->put - cbuf->get;
}

int CBUF_RemainingCapacity(cbuf_t *cbuf)
{
    return cbuf->capacity - CBUF_Size(cbuf);
}

bool CBUF_Put(cbuf_t *cbuf, int value)
{
    cbuf->data[cbuf->put] = value;
    cbuf->put++;
    return true;
}

bool CBUF_Get(cbuf_t *cbuf, int *value)
{
    if (cbuf->get == cbuf->put)
    {
        return false;
    }

    *value = cbuf->data[cbuf->get];
    cbuf->get++;
    return true;
}

bool CBUF_Peek(cbuf_t *cbuf, int *value)
{
    if (cbuf->get == cbuf->put)
    {
        return false;
    }

    *value = cbuf->data[cbuf->get];
    return true;
}
