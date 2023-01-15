#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

vector<string> center(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = v[0].size();

    vector<string>::size_type i = 0;
    while (i != v.size()) {
        maxlen = max(maxlen, v[i].size());
        ++i;
    }

    string border(maxlen + 4, '*');
    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        int diff = maxlen - v[i].size();
        int leftPad = diff / 2;
        int rightPad = maxlen - leftPad - v[i].size();

        /*
        int leftPad = diff / 2;
        int rightPad = diff % 2 == 1 ? diff / 2 + 1 : diff / 2;
        */

        string x = "* " + string(leftPad, ' ') + v[i] + string(rightPad, ' ') + " *";
        ret.push_back(x);
    }

    ret.push_back(border);
    return ret;
}
