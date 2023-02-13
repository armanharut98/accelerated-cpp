#include <vector>
#include <string>
#include <iostream>
#include "string_concat.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> v1;
    vector<string> v2;
    vector<string> result;

    string s;

    cout << "Please enter the first picture" << endl;
    while (cin >> s) {
        if (s == "END") {
            break;
        }
        v1.push_back(s);
    }

    cout << "Please enter the second picture" << endl;
    while (cin >> s) {
        if (s == "END") {
            break;
        }
        v2.push_back(s);
    }

    result = hcat(v1, v2);

    vector<string>::const_iterator iter = result.begin();
    while (iter != result.end()) {
        cout << *iter++ << endl;
    }

    return 0;
}
