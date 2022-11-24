#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <algorithm>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

int main() {
    cout << "Please enter words: ";

    vector<string> words;
    string x;

    while (cin >> x) 
        words.push_back(x);
    
    if (words.size() == 0) {
        cout << endl << "You must enter words. "
                "Please try again." << endl;
    }

    string min_word = words[0];
    string::size_type min = words[0].size();    
    string max_word = words[0];
    string::size_type max = words[0].size();

    for (int i = 0; i < words.size(); ++i) {
        if (words[i].size() < min) {
            min = words[i].size();
            min_word = words[i];
        }
        if (words[i].size() > max) {
            max = words[i].size();
            max_word = words[i];
        }
    }

    cout << min_word << ": " << min << endl
                << max_word << ": " << max << endl;

    return 0;
}
