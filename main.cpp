#include "Anagram.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

int main() {
  Anagram anagram;

  anagram.init("");

  std::cout << "Enter -1 to exit" << std::endl;
  std::string user_input = "";

  std::cout << "Please enter your word: ";
  std::getline(std::cin, user_input);

  while (std::atoi(user_input.c_str()) != -1)
  {
    std::vector<std::string> anagrams = anagram.get_anagrams(user_input);

    unsigned int i = 0;
    std::cout << "Anagrams found: " << anagrams.size() << std::endl;

    for (const auto& anagram_word : anagrams)
    {
      std::cout << "Anagram " << i << ": " << anagram_word << std::endl;
      ++i;
    }

    std::cout << "Please enter a new word (-1 to exit): ";
    std::getline(std::cin, user_input);
  }

  return 0;
}
