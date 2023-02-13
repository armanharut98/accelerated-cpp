#include <iostream>
#include <string>
#include <iostream>
#include "extract_lowercase.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string line; 
    while (getline(cin, line)) {
        vector<string> words = split(line);
        vector<string> lower = extract_lowercase(words);

        vector<string>::size_type i = 0, j = 0;
        while (i != lower.size()) {
            cout << lower[i] << endl;
            ++i;
        }

        while (j != words.size()) {
            cout << words[j] << endl;
            ++j;
        }
    }

    return 0;
}
