#include <vector>
#include <string>
#include <iostream>
#include "palindrome.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> words;

    string s;
    while (cin >> s)
        words.push_back(s);

    vector<string>::const_iterator iter = words.begin();
    while (iter != words.end()) {
        if (is_palindrome(*iter)) {
            cout << *iter << " is palindrome.";
        } else {
            cout << *iter << " is not palindrome.";
        }
        cout << endl;
        ++iter;
    }

    return 0;
}
