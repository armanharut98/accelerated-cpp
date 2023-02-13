#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "utils.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;

int main() {
    vector<string> words;
    string::size_type maxlen = 0;
    string longest_word;

    string s;
    while (cin >> s) {
        words.push_back(s);
    }

    vector<string>::size_type i = 0;
    while (i != words.size()) {
        bool hasAscOrDesc = false;
        for (string::size_type j = 0; j != words[i].size(); ++j) {
            if (isAscender(words[i][j]) || isDescender(words[i][j])) {
                hasAscOrDesc = true;
                break;
            }
        }
        if (!hasAscOrDesc && words[i].size() > maxlen) {
            maxlen = words[i].size();
            longest_word = words[i];
        }
        ++i;
    }

    if (longest_word != "") {
        cout << "The longest word that has no ascenders or descenders is '" << longest_word << "'" << endl;
    } else {
        cout << "All the words have ascenders or descenders" << endl;
    }

    return 0;
}
