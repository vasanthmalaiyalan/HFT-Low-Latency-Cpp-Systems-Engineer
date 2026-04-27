#include <iostream>

int main() {

    // 1. Print number 1 to 5
    std::cout << "Numbers 1 to 5:\n";
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << ' ';
    }

    // 2. Sum of numbers 1 to 5
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        sum += i;
    }
    std::cout << "\nSum = " << sum << '\n';

    // 3. Multiplication table (5)
    std::cout << "\nTable of 5:\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << "5 x " << i << " = " << 5 * i << '\n'; 
    }

    // 4. Even numbers
    std::cout << "\nEven numbers (0-10):\n";
    for (int i = 0; i < 10; i += 2) {
        std::cout << i << ' ';
    }

    // 5. Character + ASCII
    std::cout << "\n\nCharacters:\n";
    for (char c = 'a'; c <= 'e'; ++c) {
        std::cout << c << " = " << int(c) << '\n';
    }

    return 0;
}