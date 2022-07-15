cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)

project(Anagram)

add_subdirectory(src)

add_executable(anagram
    main.cpp
)

target_link_libraries(anagram
    PRIVATE
        anagramLib
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data_files/words_alpha.txt
    ${CMAKE_CURRENT_BINARY_DIR}/data_files/words_alpha.txt COPYONLY)
