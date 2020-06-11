# Test-driven development for embedded C with Unity and CTest

## Prerequisites

* A C compiler 
* `cmake`: https://cmake.org/download/
* A build system. `make` is common, I find `ninja` to be the most useful on Windows: https://ninja-build.org/manual.html

## Get started

```
git clone https://github.com/jonathangjertsen/tddec.git
cd tddec
git submodule init
mkdir build
cd build
cmake .. -G Ninja
ninja ctest
```
