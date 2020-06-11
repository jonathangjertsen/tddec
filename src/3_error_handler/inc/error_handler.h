#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#define ERROR(desc, param) ERROR_RuntimeError(desc, param, __FILE__, __LINE__)
void ERROR_RuntimeError(const char *message, int parameter, const char* file, int line);

#endif