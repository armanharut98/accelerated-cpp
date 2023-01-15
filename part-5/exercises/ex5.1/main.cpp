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
    string line;
    getline(cin, line);

    vector<string> rotations = rotate(line);
    sort(rotations.begin(), rotations.end(), compare);

    for (int i = 0; i < rotations.size(); ++i) {
        cout << rotations[i] << endl;
    }

    vector<string> unrotated = unrotate(rotations);

    return 0;
}
