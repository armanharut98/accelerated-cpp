#include <vector>
#include <map>
#include <string>
#include <istream>
#include <algorithm>
#include "split_string.h"

using std::map;
using std::vector;
using std::string;
using std::istream;
using std::find;

bool line_number_added(vector<int> lines, int n) {
    return find(lines.begin(), lines.end(), n) != lines.end();
}

// find all the lines that refer to each word in the input 
map<string, vector<int>> xref(istream& in,
    vector<string> find_words(const string& s) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    // read the next line 
    while (getline(in, line))
    {
        ++line_number;
        // break the input line into words
        vector<string> words = find_words(line);
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator iter = words.begin();
                iter != words.end(); ++iter)
        {
            if (!line_number_added(ret[*iter], line_number))
                ret[*iter].push_back(line_number);
        }
    }
    
    return ret;
}
