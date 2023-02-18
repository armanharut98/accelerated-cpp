#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string s;
    map<string, int> counters;   // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it 
    while (cin >> s) {
        ++counters[s];
    }

    // write the words and associated counts
    for (map<string, int>::const_iterator iter = counters.begin();
            iter != counters.end(); ++iter) {
        cout << iter->first << "\t" << iter->second << endl;
    }

    return 0;
}
