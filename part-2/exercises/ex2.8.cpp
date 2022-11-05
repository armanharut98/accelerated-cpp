#include <iostream>

// Program to generate the product of the numbers in the range [1, 10)
int main() {
    int i = 1;
    int product = 1;
    while (i < 10) {
        product *= i;
        ++i;
    }
    std::cout << product << std::endl;
    return 0;
}
