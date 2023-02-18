#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::vector;
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> v;

    string s;
    while(cin >> s) {
        v.push_back(s);
    }

    string result = accumulate(v.begin(), v.end(), std::string(""));

    cout << result << endl;
    return 0;
}
