#include <iostream>
#include <string>
#include <vector>

using std::string;  using std::vector;
using std::cin;     using std::cout;
using std::endl;

void read_strings(vector<string>& words) {
    string x;
    while (cin >> x)
        words.push_back(x);
}
