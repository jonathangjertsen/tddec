#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct cbuf_t {
    // The underlying data store
    int *data;

    // The capacity of the data store
    int capacity;

    // Where CBUF_Put will put the data
    int put;

    // Where CBUF_Get will get data from
    int get;
} cbuf_t;

cbuf_t CBUF_Init(int *data, int capacity);
bool CBUF_IsEmpty(cbuf_t *cbuf);
bool CBUF_IsFull(cbuf_t *cbuf);
int CBUF_Size(cbuf_t *cbuf);
int CBUF_RemainingCapacity(cbuf_t *cbuf);
bool CBUF_Put(cbuf_t *cbuf, int value);
bool CBUF_Get(cbuf_t *cbuf, int *value);
bool CBUF_Peek(cbuf_t *cbuf, int *value);

#endif
