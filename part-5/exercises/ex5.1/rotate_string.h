#ifndef GUARD_rotate_string_h
#define GUARD_rotate_string_h

#include <vector>
#include <string>

bool compare(const std::string&, const std::string&);
std::vector<std::string> split(const std::string&);
std::vector<std::string> rotate(const std::string&);
std::vector<std::string> unrotate(const std::vector<std::string>&);

#endif
