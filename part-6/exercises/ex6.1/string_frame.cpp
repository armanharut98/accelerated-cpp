#include <string>
#include <vector>
#include <algorithm>
#include "get_max_length.h"

using std::string;
using std::vector;
using std::max;

vector<string> frame(const vector<string>& v) {
    vector<string> ret;

    string::size_type maxlen = getMaxLength(v);

    string border(maxlen + 4, '*');
    ret.push_back(border);

    vector<string>::const_iterator iter = v.begin();
    while(iter != v.end()) {
        ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
        ++iter;
    }

    ret.push_back(border);
    return ret;
}
