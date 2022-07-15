cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)

add_library(WordUtils STATIC)

target_sources(WordUtils
    PRIVATE WordUtils.cpp
)
