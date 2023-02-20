#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::map;
using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;

bool compare(const std::pair<string, int>& p1, const std::pair<string, int>& p2) {
    return p1.second < p2.second;
}

int main() {
    string s;
    map<string, int> counters;   // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it 
    while (cin >> s) {
        ++counters[s];
    }

    // copy map elements into a vector
    vector<std::pair<string, int>> counters_v;
    for (map<string, int>::const_iterator iter = counters.begin();
            iter != counters.end(); ++iter)
    {
        counters_v.push_back(*iter);
    }

    // sort the vector
    sort(counters_v.begin(), counters_v.end(), compare);

    // write the words and associated counts
    for (vector<std::pair<string, int>>::const_iterator iter = counters_v.begin();
            iter != counters_v.end(); ++iter) {
        cout << iter->first << "\t" << iter->second << endl;
    }

    return 0;
}
