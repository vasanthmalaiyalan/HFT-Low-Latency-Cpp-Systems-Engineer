#include <iostream>

int main() {
     
    constexpr double cm_per_inch = 2.54;

    double length;
    char unit;

    std::cout << "Enter length and unit (i or c): ";
    std::cin >> length >> unit;

    if (unit == 'i') {
        std::cout << length << " inches = " << length * cm_per_inch <<" cm\n";

    } else if (unit == 'c') {
        std::cout << length << " cm = " << length / cm_per_inch << " inches\n";
    } else {
        std::cout << " Invaild unit: " << unit << '\n';
    }
    return 0;
    
    }