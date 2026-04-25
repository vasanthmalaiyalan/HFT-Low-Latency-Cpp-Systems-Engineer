#include <iostream>
#include <string>

int main() {
    std::string name;
    double age;

    std::cout << "Enter name and age: \n";

    std::cin >> name >> age;

    double months = age * 12;

    std::cout << name << " is " << months << " month old\n";

    return 0; 
}