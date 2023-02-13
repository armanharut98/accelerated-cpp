#include <vector>
#include <string>
#include <iostream>
#include "string_frame.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> v;
    
    string s;
    while (getline(cin, s)) {
        v.push_back(s);
    }

    vector<string> fv = frame(v);

    vector<string>::const_iterator iter = fv.begin();
    while (iter != fv.end()) {
        cout << *iter << endl;
        ++iter;
    }

    return 0;
}
