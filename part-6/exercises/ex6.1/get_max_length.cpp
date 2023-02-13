#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

string::size_type getMaxLength(const vector<string>& v) {
    string::size_type maxlen = 0;

    vector<string>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        maxlen = max(iter->size(), maxlen);
        ++iter;
    }

    return maxlen;
}
