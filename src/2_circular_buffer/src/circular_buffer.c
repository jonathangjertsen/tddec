#include <circular_buffer.h>
#include <stdbool.h>

cbuf_t CBUF_Init(int *data, int capacity)
{
    cbuf_t cbuf = {
        .put = 0,
        .get = 0,
        .full = false,
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
    return cbuf->full;
}

int CBUF_Size(cbuf_t *cbuf)
{
    if (cbuf->full)
    {
        return cbuf->capacity;
    }

    return cbuf->put - cbuf->get;
}

int CBUF_RemainingCapacity(cbuf_t *cbuf)
{
    if (cbuf->full)
    {
        return 0;
    }

    return cbuf->capacity - CBUF_Size(cbuf);
}

bool CBUF_Put(cbuf_t *cbuf, int value)
{
    cbuf->data[cbuf->put] = value;

    cbuf->put++;
    if (cbuf->put >= cbuf->capacity)
    {
        cbuf->put = 0;
    }
    if (cbuf->put == cbuf->get)
    {
        cbuf->full = true;
    }

    return true;
}

bool CBUF_Get(cbuf_t *cbuf, int *value)
{
    bool result = CBUF_Peek(cbuf, value);
    if (result)
    {
        cbuf->get++;
    }
    return result;
}

bool CBUF_Peek(cbuf_t *cbuf, int *value)
{
    if (CBUF_IsEmpty(cbuf))
    {
        return false;
    }

    *value = cbuf->data[cbuf->get];
    return true;
}
