#include <iostream>

int main() {

    // compile-time constants
    constexpr double pi = 3.14159265359;
    constexpr double cm_per_inch = 2.54;

    // run time
    double radius;
    std::cout << "Enter radius: ";
    std::cin >> radius;

    // const (runtime constant)
    const double area = pi * radius * radius;
    const double circumference = 2 * pi * radius;

    std::cout <<  "\n====== Circle Calculation =====\n";
    std::cout << "Area: " << area << '\n';
    std::cout << "Circumference: " << circumference << '\n';

    // conversion example
    double inches;
    std::cout << "\nEnter length in inches: ";
    std::cin >> inches;

    const double cm = inches * cm_per_inch;

    std::cout << "Length in cm: " << cm << '\n';

    return 0;
}