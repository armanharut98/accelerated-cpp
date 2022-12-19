#include <vector>
#include <iostream>

using std::cin;     using std::cout;
using std::vector;  using std::endl;

int main() {
    cout << "Please enter numbers: ";

    vector<double> numbers;

    double x;
    while (cin >> x) {
        numbers.push_back(x);
    }

    if (numbers.size() == 0) {
        cout << "You must enter valid numbers. "
            "Please try again." << endl;
        return 1;
    }

    double sum = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }

    double average = sum / numbers.size();
    
    cout << "The average is " <<  average  << "!" << endl;

    return 0;
}
