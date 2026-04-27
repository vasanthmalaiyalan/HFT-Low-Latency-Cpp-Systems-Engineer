#include <iostream>

int main() {

    constexpr double cm_per_inch = 2.54;

    double length;
    char unit;

    std::cout << "Enter length and unit (i or c): ";
    std::cin >> length >> unit;

    switch (unit) {
        case 'i':
             std::cout << length << " in = " << length * cm_per_inch << " cm\n";
             break;
            
        case 'c':
             std::cout << length << " cm = " << length / cm_per_inch << " in\n";
             break;
             
        default:
             std::cout << " Unknow unit; " << unit << '\n';
             break;      
    }

    return 0;
}