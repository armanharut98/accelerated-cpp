#include <algorithm>
#include <string>

using std::equal;
using std::string;

bool is_palindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}
