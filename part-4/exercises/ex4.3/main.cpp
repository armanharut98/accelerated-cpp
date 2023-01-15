#include <iostream>
#include <iomanip>
#include <algorithm>
#include "get_stream_width.h"

using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::streamsize;

int main() {
    const int start = -100;
    const int end = 101;

    streamsize col1Width = max(getStreamWidth(start), getStreamWidth(end));
    streamsize col2Width = max(getStreamWidth(start * start), getStreamWidth(end * end));
    
    for (int i = start; i < end; ++i) {
        cout << setw(col1Width) << i << setw(col2Width) << (i * i) << endl;
    }

    return 0;
}