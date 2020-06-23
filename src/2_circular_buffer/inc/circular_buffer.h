#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

#ifndef CIRCULAR_BUFFER_DTYPE
#define CIRCULAR_BUFFER_DTYPE int
#endif

typedef CIRCULAR_BUFFER_DTYPE cbuf_elem_t;

typedef struct cbuf_t {
    // The underlying data store
    cbuf_elem_t *data;

    // The capacity of the data store
    int capacity;

    // Whether the buffer is full
    bool full;

    // Where CBUF_Put will put the data
    int head;

    // Where CBUF_Get will get data from
    int tail;
} cbuf_t;

cbuf_t CBUF_Init(cbuf_elem_t *data, int capacity);
bool CBUF_IsEmpty(cbuf_t *cbuf);
bool CBUF_IsFull(cbuf_t *cbuf);
int CBUF_Size(cbuf_t *cbuf);
int CBUF_RemainingCapacity(cbuf_t *cbuf);
bool CBUF_Put(cbuf_t *cbuf, cbuf_elem_t value);
bool CBUF_Get(cbuf_t *cbuf, cbuf_elem_t *value);
bool CBUF_Peek(cbuf_t *cbuf, cbuf_elem_t *value);

#endif
