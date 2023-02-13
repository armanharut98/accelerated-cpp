#ifndef GUARD_string_concat_h
#define GUARD_string_concat_h

#include <vector>
#include <string>
#include <algorithm>

std::string::size_type width(const std::vector<std::string>);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);

#endif
