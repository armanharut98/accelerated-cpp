#include <iostream>

int main() {
    int k = 0;
    while (k != 0) {
        using std::cout;
        cout << "*"; // std:: is not required here because of the using statement above
        ++k;
    }
    std::cout << std::endl; // std:: is required here
    return 0;
}
