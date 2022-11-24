#include <string>
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using std::vector;  using std::string;
using std::sort;    using std::unique;
using std::cout;    using std::cin;
using std::endl;

int main() {
    cout << "Please enter words: ";

    vector<string> words;
    string x;

    while (cin >> x) 
        words.push_back(x);

    if (words.size() == 0) {
        cout << endl << "You must enter words. "
                "Please try again." << endl; 
        return 1;
    }

    sort(words.begin(), words.end());

    vector<string> words_unique;
    vector<int> word_count;
    x = "";

    string::size_type size = words.size();

    for (int i = 0; i < size; ++i) {
        if (x != words[i]) {
            x = words[i];
            words_unique.push_back(words[i]);
            word_count.push_back(1);
        } else {
            word_count[word_count.size() - 1] += 1;
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << words_unique[i] << ": " << word_count[i] << endl;
    }

    return 0;
}
