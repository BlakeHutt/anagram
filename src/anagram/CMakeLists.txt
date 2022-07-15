cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(utils)

add_library(anagramLib)

target_sources(anagramLib
    PRIVATE Anagram.cpp
)

target_link_libraries(anagramLib
    PRIVATE WordUtils
)

# Is there a better way to do this?
# To get the 'anagram.h' header file available to main
# rather than making while directory public
target_include_directories(anagramLib
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)


