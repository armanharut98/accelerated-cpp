#include <string>
#include <vector>
#include <cctype>

using std::vector;
using std::string;
using std::isspace;
using std::islower;

#include <iostream>

vector<string> split(string line) {
    vector<string> ret;

    typedef string::size_type string_sz;

    string_sz i = 0;
    while (i != line.size()) {
        string s;

        while (i != line.size() && isspace(line[i]))
            ++i;

        string_sz j = i;

        while (j != line.size() && !isspace(line[j]))
            ++j;

        if (i != j) {
            ret.push_back(line.substr(i, j - i));
        }

        i = j;
    }

    return ret;
}

vector<string> extract_lowercase(vector<string>& words) {
    vector<string> lowercase_words;
    vector<string>::iterator iter = words.begin();

    while (iter != words.end()) {
        if (islower((*iter)[0])) {
            lowercase_words.push_back(*iter);
            iter = words.erase(iter);
        } else {
            ++iter;
        }
    }

    return lowercase_words;
}
