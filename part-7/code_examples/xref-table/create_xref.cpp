#include <vector>
#include <map>
#include <string>
#include <istream>
#include "split_string.h"

using std::map;
using std::vector;
using std::string;
using std::istream;

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
            ret[*iter].push_back(line_number);
        }
    }
    return ret;
}
