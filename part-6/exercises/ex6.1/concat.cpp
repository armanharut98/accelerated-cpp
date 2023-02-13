#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include "string_concat.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> v1;
    vector<string> v2;

    string s;
    while (getline(cin, s)) {
        if (s == "end" || s == "END") {
            break;
        }
        v1.push_back(s);
    }

    while (getline(cin, s)) {
        if (s == "end" || s == "END") {
            break;
        }
        v2.push_back(s);
    }

    vector<string> res = hcat(v1, v2);

    vector<string>::const_iterator iter = res.begin();
    while(iter != res.end()) {
       cout << *iter++ << endl;
    }

    return 0;
}
