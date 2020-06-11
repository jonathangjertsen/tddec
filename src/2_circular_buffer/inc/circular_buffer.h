#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct cbuf_t {
    // The underlying data store
    int *data;

    // The capacity of the data store
    int capacity;
} cbuf_t;

cbuf_t CBUF_Init(int *data, int capacity);
bool CBUF_IsEmpty(cbuf_t *cbuf);
int CBuf_Size(cbuf_t *cbuf);

#endif