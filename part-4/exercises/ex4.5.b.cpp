#include <iostream>
#include <string>
#include <vector>
#include "read_strings.h"
#include "count_words.h"

using std::cin;     using std::cout;
using std::string;  using std::vector;
using std::endl;

int main() {
    cout << "Please enter words: ";

    vector<string> words;
    read_strings(words);

    if (words.size() == 0) {
        cout <<  "You must enter words. "
                "Please try again." << endl;
        return 1;
    }

    vector<string> words_unique;
    vector<int> word_count = count_words(words, words_unique);

    for (int i = 0; i < word_count.size(); ++i) {
        cout << words_unique[i] << ": " << word_count[i] << endl;
    }

    return 0;
}
