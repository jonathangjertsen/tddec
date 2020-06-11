#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct cbuf_t {

} cbuf_t;

cbuf_t CBUF_Init(void);
bool CBUF_IsEmpty(cbuf_t *cbuf);

#endif