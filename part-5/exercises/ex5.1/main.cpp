#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "rotate_string.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::sort;

int main() {
    vector<string> input;
    string s;

    while(getline(cin, s)) {
        input.push_back(s);
    };

    vector<string> rotations = rotate(s);
    sort(rotations.begin(), rotations.end(), compare);

    for (int i = 0; i < rotations.size(); ++i) {
        cout << rotations[i] << endl;
    }

    vector<string> unrotated = unrotate(rotations);

    return 0;
}
