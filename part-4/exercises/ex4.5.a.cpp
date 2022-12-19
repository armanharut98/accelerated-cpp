#include <iostream>
#include <string>
#include <vector>
#include "read_strings.h"

using std::cin;     using std::cout;
using std::string;  using std::vector;
using std::endl;

int main() {
    cout << "Please enter words: ";

    vector<string> words;
    read_strings(words);

    if (words.size() == 0) {
        cout << "You must enter words. "
            "Please try again." << endl;
        return 1;
    }

    cout << "You have entered " << words.size() 
          << " words!" << endl;

    return 0;
}
