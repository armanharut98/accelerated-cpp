#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "string_frame.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::domain_error;

int main() {
    vector<string> v;
    vector<string> result;
    try {
        result = frame(v);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    for (vector<string>::size_type i = 0; i != result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
