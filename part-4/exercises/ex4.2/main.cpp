#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::streamsize;
using std::setw;

int main() {
    int start = 0;
    int end = 101;

    for (int i = start; i < end; i++) {
        cout << setw(3) << i << setw(6) << (i * i) << endl;
    }

    return 0;
}