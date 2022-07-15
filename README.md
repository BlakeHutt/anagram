# Anagrams

A basic anagram checker for words

## Getting Started

1. Clone the repo.
2. Untar the word file in data_files
3. Run CMake in the directory or create a build folder.
4. Run make then run the application.

ie
```
tar -xvf words_list.tar.gz

mkdir build-anagram && cd build-anagram
cmake ../anagrams

make all

./anagram
```

## Help

Q: The provided word file ins't being read properly.
A: The file has unix LF, so Windows may have trouble reading.
