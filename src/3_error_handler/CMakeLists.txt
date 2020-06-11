add_library(error_handler src/error_handler.c)
target_include_directories(error_handler PUBLIC inc)

add_library(error_handler_mock mock/error_handler_mock.c)
target_include_directories(error_handler_mock PUBLIC inc mock)
