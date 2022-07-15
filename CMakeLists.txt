cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)

project(Anagram)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/anagram)

add_executable(anagram
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(anagram
    PRIVATE
        anagramLib
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data_files/words_alpha.txt
    ${CMAKE_CURRENT_BINARY_DIR}/data_files/words_alpha.txt COPYONLY)
