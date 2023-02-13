#include <string>
#include <vector>
#include <iostream>
#include "utils.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string word;
    string ascenders;
    string descenders;

    typedef string::size_type string_sz;

    cout << "Please enter a word: ";

    cin >> word;

    if (word.size() == 0) {
        cout << "You must enter a valid word. "
            << "Please try again.";
        return 0;
    }

    for (string_sz i = 0; i < word.size(); ++i) {
        if (isAscender(word[i]) && !charExists(word[i], ascenders)) {
            ascenders += word[i];
        }
        if (isDescender(word[i]) && !charExists(word[i], descenders)) {
            descenders += word[i];
        }
    }

    cout << endl;
    if (ascenders.size() != 0) {
        cout << "The word contains the following ascenders: ";
        for (string_sz i = 0; i < ascenders.size(); ++i) {
            cout << ascenders[i] << " ";
        }
    }

    cout << endl;

    if (descenders.size() != 0) {
        cout << "The word contains the following ascenders: ";
        for (string_sz i = 0; i != descenders.size(); ++i) {
            cout << descenders[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
