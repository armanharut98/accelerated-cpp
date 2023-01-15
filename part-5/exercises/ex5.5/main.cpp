#include <vector>
#include <string>
#include <iostream>
#include "center.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main() {
    vector<string> picture;

    string x;
    while (getline(cin, x)) {
        picture.push_back(x);
    }

    vector<string> centered = center(picture);

    for (vector<string>::size_type i = 0; i != centered.size(); ++i) {
        cout << centered[i] << endl;
    }

    return 0;
}
