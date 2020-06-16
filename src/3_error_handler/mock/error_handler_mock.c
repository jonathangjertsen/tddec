#include <error_handler.h>

#include <string.h>

#ifndef ERROR_MESSAGE_SIZE
#define ERROR_MESSAGE_SIZE 1000
#endif

#ifndef ERROR_FILENAME_SIZE
#define ERROR_FILENAME_SIZE 1000
#endif

char g_message[ERROR_MESSAGE_SIZE];
char g_file[ERROR_FILENAME_SIZE];
int g_parameter;
int g_line;

int ERROR_ResetMock(void)
{
    g_parameter = -1;
    memset(g_message, 0, ERROR_MESSAGE_SIZE);
    memset(g_file, 0, ERROR_MESSAGE_SIZE);
}

void ERROR_RuntimeError(const char *message, int parameter, const char* file, int line)
{
    strncpy(g_message, message, ERROR_MESSAGE_SIZE);
    strncpy(g_file, file, ERROR_MESSAGE_SIZE);
    g_parameter = parameter;
    g_line = line;
}

int ERROR_LastParameter(void)
{
    return g_parameter;
}
