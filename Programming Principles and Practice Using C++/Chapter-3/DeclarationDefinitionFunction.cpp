#include <iostream>

// Function declaration
int square(int);

int main() {
    int result = square(5); // call before defination
    std::cout << "Square = " << result << '\n';

    return 0;
}

// Function definition
int square(int x) {
    return x * x;
}