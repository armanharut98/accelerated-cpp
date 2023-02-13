#include <vector>
#include <algorithm>
#include <iterator>    
#include <iostream>

using std::vector;
using std::copy;
using std::back_inserter;
using std::cout;
using std::endl;

int main() {
    vector<int> u(10, 100);

    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    cout << "u: ";
    vector<int>::const_iterator u_iter = u.begin();
    while(u_iter != u.end()) {
        cout << *u_iter++ << " ";
    }
    cout << endl;
    
    cout << "v: ";
    vector<int>::const_iterator v_iter = v.begin();
    while(v_iter != v.end()) {
        cout << *v_iter++ << " ";
    }
    cout << endl;

    return 0;
}
