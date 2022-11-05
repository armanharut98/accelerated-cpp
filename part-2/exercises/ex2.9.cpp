#include <iostream>

int main() {
    int num1;
    int num2;

    std::cin >> num1;
    std::cin >> num2;

    if (num1 == num2) {
        std::cout << num1 << " equals " << num2 << "!" << std::endl;
        return 0;
    }

    if (num1 > num2) {
        std::cout << num1 << " is larger!" << std::endl;
    } else {
        std::cout << num2 << " is larger!" << std::endl;
    }
    return 0;
}
