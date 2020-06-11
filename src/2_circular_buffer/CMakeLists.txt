# Add target for the library
add_library(circular_buffer src/circular_buffer.c)
target_include_directories(circular_buffer PUBLIC inc)

# Add the unit test
add_unit_test(
    TARGET_NAME
        test_circular_buffer
    SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/test_circular_buffer.c
)
target_link_libraries(test_circular_buffer PUBLIC circular_buffer)
