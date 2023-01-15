#include <iostream>
#include <vector>
#include "average.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
    vector<double> numbers;

    cout << "Please enter numbers: ";

    double n;
    while (cin >> n) {
        numbers.push_back(n);
    }

    if (numbers.size() == 0) {
        cout << "You must enter valid numbers. "
            "Please try again." << endl;
        return 1;
    }

    cout << "The average is " << average(numbers) << endl;

    return 0;
}
