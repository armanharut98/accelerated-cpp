#include <iostream>

int main() {
    int k = 0;
    while (k != 0) {
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl; // std:: is required here
    return 0;
}
