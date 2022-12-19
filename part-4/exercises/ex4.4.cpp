#include <iostream>
#include <iomanip>
#include <string>

using std::cout;    using std::endl;
using std::setw;    using std::streamsize;
using std::setprecision;

streamsize calculate_digits(int end, streamsize prec) {
    streamsize digits = 1;

    for (int i = 1; end/i >= 1; i*=10) {
        digits++;
    }
    
    return digits + prec;
}

int main() {
    streamsize prec = 5;
    double start = 5;
    double end = 6;
    double increment = 0.005;

    streamsize digits = calculate_digits(end, prec);
    streamsize result_digits = calculate_digits(end*end, prec);

    for (double i = start; i < end; i+=increment) {
        cout << setw(digits) << setprecision(prec) << i 
            << setw(result_digits) << setprecision(prec) << i * i << endl;
    }

    return 0;
}
