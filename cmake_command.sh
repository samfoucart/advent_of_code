#!/bin/bash

cmake -S . -B build -D CMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Debug
