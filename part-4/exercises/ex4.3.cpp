#include <iostream>
#include <iomanip>
#include <string>

using std::cout;    using std::endl;
using std::setw;    using std::streamsize;

streamsize calculate_width(int end) {
    streamsize width = 0;

    for (int i = 1; end / i >= 1; i*=10) {
        width += 1;
    }

    return width;
}

int main() {
    int end = 999;
    streamsize width = calculate_width(end);
    streamsize result_width = calculate_width(end * end);
    
    for (int i = 0; i < end; ++i) {
        cout << setw(width + 1) << i << setw(result_width + 1) << i * i << endl;
    }

    return 0;
}
