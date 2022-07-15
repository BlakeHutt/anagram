#include "Anagram.h"

#include <fstream>
#include <iostream>

#include "WordUtils.h"

namespace {
const std::string& default_file = "data_files/words_alpha.txt";
}

Anagram::Anagram()
{
}

Anagram::~Anagram()
{
}

bool Anagram::read_file(const std::string &filename) {
  std::fstream file;

  std::cout << "Attempting to read file: " << filename << std::endl;

  file.open(filename, std::ios::in);

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line))
    {
      word_utils::to_lower(&line);

      word_set.insert(line);

      int word_length = line.size();

      if (word_map.find(word_length) == word_map.end()) {
        word_map.insert(std::pair<int, std::set<std::string>>(
            word_length, std::set<std::string>{}));
      }

      word_map[word_length].insert(line);
    }
  } else {
    std::cerr << "Failed to open file." << std::endl;
    return false;
  }

  file.close();

  std::cout << "Amount of words read: " << word_set.size() << std::endl;
  std::cout << "Amount of words, grouped by size: " << word_map.size()
            << std::endl;

  return true;
}

bool Anagram::init(const std::string &filename = "") {

  return filename.empty() ? read_file(default_file) : read_file(filename);
}

std::vector<std::string> Anagram::get_anagrams(const std::string &word) {
  std::vector<std::string> anagram_list;
  std::string passed_word = word;
  word_utils::to_lower(&passed_word);

  const auto &candidate_words = word_map[word.size()];

  std::cout << "Possible anagrams: " << candidate_words.size() << std::endl;

  for (auto itr = candidate_words.begin(); itr != candidate_words.end();
       itr++) {
    std::string possible_candidate = *itr;
    
    /* Anagram of itself isn't really fun */
    if (possible_candidate.compare(passed_word) == 0)
    {
      continue;
    }

    if (word_utils::is_anagram(passed_word, possible_candidate, true)) {
      anagram_list.push_back(possible_candidate);
    }
  }

  return anagram_list;
}
