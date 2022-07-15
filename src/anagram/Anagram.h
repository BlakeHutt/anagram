#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

class Anagram {
public:

  Anagram();
  ~Anagram();
  /**
   * Attempts to initialise the Anagram class
   * with the passed word list
   */
  bool init(const std::string &filename);

  /**
   * Returns a list of words that are anagrams
   */
  std::vector<std::string> get_anagrams(const std::string &word);

private:
  /**
   * Reads file and populates the word set and word map
   */
  bool read_file(const std::string &filename);

  std::set<std::string> word_set;
  std::map<int, std::set<std::string>> word_map;
};
