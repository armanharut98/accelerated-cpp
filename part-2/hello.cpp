#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your name: ";

    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    
    return 0;
}
