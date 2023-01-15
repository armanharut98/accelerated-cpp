#include <vector>
#include <string>
#include <iostream>
#include "read_words.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> words;

    cout << "Please enter words: ";
    
    read(cin, words);
    displayWords(words);
    cout << "There are " << numberOfWords(words) << " words." << endl;

    return 0;
}
