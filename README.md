# Test-driven development for embedded C with Unity and CTest

[![Build Status](https://travis-ci.com/jonathangjertsen/tddec.svg?branch=master)](https://travis-ci.com/jonathangjertsen/tddec)

## Note

This is being written as part of the book club in the Slack channel for Patreons of
[Embedded FM](https://embedded.fm/), where we are reading
*Test-Driven Development for Embedded C* by James Grenning.

We are currently on Week 2 which covers chapters 4.

## Prerequisites

On Mac OSX, you should only need to install:

* `cmake`: https://cmake.org/download/

On Windows (and Linux, depending on your distribution), you also need:

* `ruby`: https://www.ruby-lang.org/en/downloads/
* A build system. `make` is common, I find `ninja` to be the most useful on Windows: https://ninja-build.org/manual.html
* A C compiler (on Windows, the gcc bundled with ruby should work! It lives in `msys64/mingw64/bin` in the Ruby installation).

## Get started

### Windows/ninja

After installing the prerequisites, this should work for both Windows CMD and bash:

```
git clone --recurse-submodules https://github.com/jonathangjertsen/tddec.git
cd tddec
mkdir build
cd build
cmake .. -G Ninja
ninja ctest
```


After running `ninja ctest` (or `make ctest`, you should see something like:

```
test 1
    Start 1: test_minimal

1: Test command: [home]\tddec\build\src\0_minimal\test_minimal.exe
1: Test timeout computed to be: 10000000
1: [home]/tddec/src/0_minimal/test/test_minimal.c:5:test_minimal:IGNORE: It works! Try changing this message to see if it gets updated when running the ctest target.
1:
1: -----------------------
1: 1 Tests 0 Failures 1 Ignored
1: OK
1/2 Test #1: test_minimal .....................   Passed    0.01 sec
test 2
    Start 2: test_led_driver

2: Test command: [home]\tddec\build\src\1_led_driver\test_led_driver.exe
2: Test timeout computed to be: 10000000
2: [home]/tddec/src/1_led_driver/test/test_led_driver.c:5:test_offAfterCreate:PASS
2:
2: -----------------------
2: 1 Tests 0 Failures 0 Ignored
2: OK
2/2 Test #2: test_led_driver ..................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.02 sec
```

### Mac OSX

```
git clone --recurse-submodules https://github.com/jonathangjertsen/tddec.git
cd tddec
mkdir build
cd build
cmake ..
make ctest
```
