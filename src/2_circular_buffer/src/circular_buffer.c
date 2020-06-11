#include <circular_buffer.h>
#include <stdbool.h>

void incrementHead(cbuf_t *cbuf)
{
    cbuf->head++;
    if (cbuf->head >= cbuf->capacity)
    {
        cbuf->head = 0;
    }
    if (cbuf->head == cbuf->tail)
    {
        cbuf->full = true;
    }
}

void incrementTail(cbuf_t *cbuf)
{
    cbuf->tail++;
    if (cbuf->tail >= cbuf->capacity)
    {
        cbuf->tail = 0;
    }
    cbuf->full = false;
}

cbuf_t CBUF_Init(cbuf_elem_t *data, int capacity)
{
    return (cbuf_t){
        .head = 0,
        .tail = 0,
        .full = false,
        .capacity = capacity,
        .data = data,
    };
}

bool CBUF_IsFull(cbuf_t *cbuf)
{
    return cbuf->full;
}

bool CBUF_IsEmpty(cbuf_t *cbuf)
{
    return (cbuf->head == cbuf->tail) && !CBUF_IsFull(cbuf);
}

int CBUF_Size(cbuf_t *cbuf)
{
    if (CBUF_IsFull(cbuf))
    {
        return cbuf->capacity;
    }
    else if (cbuf->head >= cbuf->tail)
    {
        return cbuf->head - cbuf->tail;
    }
    else
    {
        return cbuf->capacity - (cbuf->tail - cbuf->head);
    }
}

int CBUF_RemainingCapacity(cbuf_t *cbuf)
{
    return cbuf->capacity - CBUF_Size(cbuf);
}

bool CBUF_Put(cbuf_t *cbuf, cbuf_elem_t value)
{
    if (CBUF_IsFull(cbuf))
    {
        return false;
    }

    cbuf->data[cbuf->head] = value;
    incrementHead(cbuf);
    return true;
}

bool CBUF_Get(cbuf_t *cbuf, cbuf_elem_t *value)
{
    bool result = CBUF_Peek(cbuf, value);
    if (result)
    {
        incrementTail(cbuf);
    }
    return result;
}

bool CBUF_Peek(cbuf_t *cbuf, cbuf_elem_t *value)
{
    if (CBUF_IsEmpty(cbuf))
    {
        return false;
    }

    *value = cbuf->data[cbuf->tail];
    return true;
}
