#include <istream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::istream;
using std::vector;
using std::string;
using std::sort;
using std::cout;
using std::endl;

istream& read(istream& in, vector<string>& words) {
    if (in) {
        words.clear();
    
        string x;
        while (in >> x) {
            words.push_back(x);
        }
    }
    return in;
}

int displayWords(const vector<string>& words) {
    for (vector<string>::size_type i = 0; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
    return 0;
}

int numberOfWords(const vector<string>& words) {
    return words.size();
}

int countUniqueWords(vector<string> words) {
    vector<string> unique_words;
    vector<int> word_count;

    sort(words.begin(), words.end());

    string x = "";
    for (vector<string>::size_type i = 0; i < words.size(); ++i) {
        if (x != words[i]) {
            x = words[i];
            unique_words.push_back(x);
            word_count.push_back(1);
        } else {
            ++word_count[word_count.size() - 1];
        }
    }

    for (int i = 0; i < unique_words.size(); ++i) {
        cout << unique_words[i] << ": " << word_count[i] << endl;
    }
    return 0;
}
