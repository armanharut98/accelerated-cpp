#ifndef GUARD_read_words_h
#define GUARD_read_words_h

#include <istream>
#include <vector>
#include <string>

std::istream& read(std::istream&, std::vector<std::string>&);
int numberOfWords(const std::vector<std::string>&);
int displayWords(const std::vector<std::string>&);
int countUniqueWords(std::vector<std::string>);

#endif
