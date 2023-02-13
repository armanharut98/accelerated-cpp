#include <string>

using std::string;

bool isPalindrome(const string& s) {
    string reverse_s;

    string::const_reverse_iterator iter = s.crbegin();

    while (iter != s.rend()) {
        reverse_s.push_back(*iter);
        ++iter;
    }

    return s == reverse_s;
}
