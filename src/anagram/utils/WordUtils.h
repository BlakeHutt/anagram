#pragma once

#include <string>

namespace word_utils 
{

/* Returns true if the candidate word is an anagram of the input word */
bool is_anagram(std::string input_word, std::string candidate_word, bool is_lower = false);

/* Converts the passed string to lower case*/
void to_lower(std::string* word);
}  // namespace word_utils
