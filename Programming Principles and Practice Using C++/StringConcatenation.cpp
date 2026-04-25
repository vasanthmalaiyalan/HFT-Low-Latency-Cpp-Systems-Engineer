#include <iostream>
#include <string>

int main() {
    std::cout << "Enter first and second name:\n";

    std::string first;
    std::string second;

    std::cin >> first >> second;

    std::string name = first + ' ' + second;

    std::cout << "Hello, " << name << "\n";

    return 0;
}