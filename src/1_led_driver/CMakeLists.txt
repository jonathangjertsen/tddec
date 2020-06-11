# Add target for the library
add_library(led_driver src/led_driver.c)
target_include_directories(led_driver PUBLIC inc)
target_link_libraries(led_driver error_handler)

# Add the unit test
add_unit_test(
    TARGET_NAME
        test_led_driver
    SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/test_led_driver.c
)
target_link_libraries(test_led_driver PUBLIC led_driver error_handler_mock)
