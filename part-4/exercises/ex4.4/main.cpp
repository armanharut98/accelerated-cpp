#include <iostream>
#include <iomanip>
#include <algorithm>
#include "get_stream_width.h"

using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::streamsize;
using std::setprecision;

int main() {
    const double start = 5.;
    const double end = 6.;
    const double increment = 0.1;
    const streamsize d = 4;

    streamsize col1Width = max(getStreamWidth(start, d), getStreamWidth(end, d));
    streamsize col2Width = max(getStreamWidth(start * start, d), getStreamWidth(end * end, d));

    int gap;
    if (start < 0 || end < 0) {
        gap = 3;
    } else {
        gap = 2;
    }

    streamsize col1Precision = col1Width - gap;
    streamsize col2Precision = col2Width - gap;
    streamsize prec = cout.precision();
    
    double i = start;
    while (i < end) {
        cout << setw(col1Width) << setprecision(col1Precision) << i 
            << setw(col2Width) << setprecision(col2Precision) << (i * i)
            << setprecision(prec) << endl;

        i += increment;
    }

    return 0;
}