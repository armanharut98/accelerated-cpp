#include <iomanip>

using std::streamsize;

streamsize getStreamWidth(int n) {
    streamsize width = 1; // Leading space

    if (n < 0) {
        ++width; // Negative sign
        n *= -1;
    }

    while (n != 0) {
        ++width;
        n /= 10;
    }

    return width;
}

streamsize getStreamWidth(int n, streamsize decimalDigits) {
    streamsize width = 2; // Leading space and decimal point

    if (n < 0) {
        ++width; // Negative sign
        n *= -1;
    }

    while (n >= 1) {
        ++width;
        n /= 10;
    }

    return width + decimalDigits;
}
