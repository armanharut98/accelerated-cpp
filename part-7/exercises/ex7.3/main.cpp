#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "create_xref.h"

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    // call xref using split by default
    map<string, vector<int>> ret = xref(cin);

    // write the results
    for(map<string, vector<int>>::const_iterator iter = ret.begin();
            iter != ret.end(); ++iter)
    {
        // write the word
        cout << iter->first << " occurs on line(s): ";

        // followed by one or more line numbers
        vector<int>::const_iterator line_iter = iter->second.begin();
        cout << *line_iter;

        ++line_iter;
        // write the rest of the line numbers, if any
        while(line_iter != iter->second.end())
        {
            cout << ", " << *line_iter;
            ++line_iter;
        }
        // write a new line to separate each word from the next
        cout << endl;
    }

    return 0;
}
