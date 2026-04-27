#include <iostream>

// function definition
int square(int x) {
    return x * x;
}

int main() {

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    int result = square(num); // function call

    std::cout << "Square = " << result << '\n';

    return 0;
}