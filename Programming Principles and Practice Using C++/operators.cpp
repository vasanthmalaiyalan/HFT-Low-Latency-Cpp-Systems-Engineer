#include <iostream>
#include <string>
#include <cmath> // for sqrt

int main() 
{
    std::cout << "Enter a number: ";

    double n = 0;
    std::cin >> n;

    std::cout << "n = " << n << "\n";
    std::cout << "n + 1 = " << n + 1 << "\n";
    std::cout << "n - 1 = " << n - 1 << "\n";
    std::cout << "3 * n = " << 3 * n << "\n";
    std::cout << "n * n = " << n * n << "\n";
    std::cout << "n / 2 = " << n / 2 << "\n";
    std::cout << "sqrt(n) = " << std::sqrt(n) << "\n";

    return 0;
}