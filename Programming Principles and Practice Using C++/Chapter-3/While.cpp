#include <iostream>

int main() {

    int number;
    int sum = 0;

    std::cout << "Enter numbers (0 to stop): \n";

    std::cin >> number;

    while (number != 0) // loop until user enter 0
    {
        sum += number; // add to sum

        std::cin >> number; // next input
    }

    std::cout << "Total sum = " << sum << '\n';

    return 0;

}