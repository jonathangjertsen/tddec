# Test-driven development for embedded C with Unity and CTest

## Prerequisites

* `cmake`: https://cmake.org/download/
* `ruby`: https://www.ruby-lang.org/en/downloads/
* A build system. `make` is common, I find `ninja` to be the most useful on Windows: https://ninja-build.org/manual.html
* A C compiler (on Windows, the one bundled with ruby should work! It lives in `msys64/mingw64/bin` in the Ruby installation).

## Get started

After installing the prerequisites, this should work for both Windows CMD and bash (only tested on CMD):

```
git clone https://github.com/jonathangjertsen/tddec.git
cd tddec
git submodule init
git submodule update
mkdir build
cd build
cmake .. -G Ninja
ninja ctest

```
