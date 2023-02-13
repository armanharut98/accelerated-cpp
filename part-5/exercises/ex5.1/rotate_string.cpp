#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include "rotate_string.h"

using std::string;
using std::vector;
using std::tolower;
using std::streamsize;
using std::max;

bool compare(const string& a, const string& b) {
    return tolower(a[0]) < tolower(b[0]);
}

string_sz getMaxLength(const vector<string>& v) {
    string_sz maxlen = 0;

    vector<string>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        maxlen = max(maxlen, iter->size());
        iter++;
    }

    return maxlen;
}

streamsize getWidth(const string& s, string) {
    streamsize width;


}

vector<string> split(const string& s) {
    vector<string> ret;

    string_sz i = 0;
    while (i != s.size()) {
        string x;

        while (i != s.size() && isspace(s[i])) {
            ++i;
        }

        string_sz j = i;
        while (j != s.size() && !isspace(s[j])) {
            ++j;
        }

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

vector<string> rotate(const string& s) {
    vector<string> ret;
    ret.push_back(s);

    vector<string> words = split(s);

    typedef vector<string>::size_type vec_sz;

    for (vec_sz i = 1; i != words.size(); ++i) {
        string x;

        vec_sz j = i;
        while (j != words.size()) {
            x += words[j];
            if (j == words.size() - 1) {
                x += "|";
            } else {
                x += " ";
            }
            ++j;
        }

        j = 0;
        while (j != i) {
            x += words[j] + " ";
            ++j;
        }

        ret.push_back(x);
    }
    
    return ret;
}

vector<string> unrotate(const vector<string>& v) {
    vector<string> ret;

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        string x;

        string line = v[i];
        string::size_type j = 0;
        while (j != line.size() && line[j] != '|') {
            ++j;
        }

        if (line[j] == '|') {
            x += line.substr(j + 1, line.size() - j);
            x += line.substr(0, j);
        } else {
            x = line;
        }

        ret.push_back(x);
    }

    return ret;
}