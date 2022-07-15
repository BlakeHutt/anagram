#include "WordUtils.h"

#include <algorithm>
#include <regex>

namespace word_utils {

void to_lower(std::string* word)
{
  std::regex newline("\n*");
  *word = std::regex_replace(*word, newline, "");
  std::transform(word->begin(), word->end(), word->begin(), ::tolower);
}

bool is_anagram(std::string input_word, std::string candidate_word, bool is_lower)
{
  if (!is_lower)
  {
    to_lower(&input_word);
    to_lower(&candidate_word);
  }

  std::sort(input_word.begin(), input_word.end());
  std::sort(candidate_word.begin(), candidate_word.end());

  return input_word.compare(candidate_word) == 0;
}
}  // namespace word_utils
