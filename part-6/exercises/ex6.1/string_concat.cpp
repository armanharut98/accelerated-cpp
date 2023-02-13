#include <string>
#include <vector>
#include "get_max_length.h"

using std::string;
using std::vector;

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
    vector<string> ret;

    string::size_type maxLenLeft = getMaxLength(left);

    vector<string>::const_iterator left_iter = left.begin();
    vector<string>::const_iterator right_iter = right.begin();

    while (left_iter != left.end() || right_iter != right.end()) {
        string x;

        if (left_iter != left.end()) {
            x += *left_iter++;
        }

        x += string(maxLenLeft - x.size(), ' ');

        if (right_iter != right.end()) {
            x += *right_iter++;
        }

        ret.push_back(x);
        
    }

    return ret;
}
