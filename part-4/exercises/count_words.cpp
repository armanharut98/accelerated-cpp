#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::string;      using std::vector;
using std::sort;
using std::cout;        using std::endl;

vector<int> count_words(vector<string> words, vector<string>& words_unique) {
    sort(words.begin(), words.end());

    vector<int> result;
    string x;
    for (int i = 0; i < words.size(); ++i) {
        if (x != words[i]) {
            result.push_back(1);
            words_unique.push_back(words[i]);
            x = words[i];
        } else {
            ++result[result.size() - 1];
        }
    }

    return result;
}
