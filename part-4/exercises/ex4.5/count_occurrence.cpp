#include <vector>
#include <string>
#include <iostream>
#include "read_words.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;

int main() {
    vector<string> words;

    cout << "Please enter words: ";
    
    read(cin, words);
    countUniqueWords(words);

    return 0;
}
