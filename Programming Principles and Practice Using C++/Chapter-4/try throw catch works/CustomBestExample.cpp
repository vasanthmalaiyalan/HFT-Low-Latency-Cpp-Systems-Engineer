#include <iostream>

// function
void check_age(int age) {

    if (age < 0)
       throw "Age cannot be negative"; // custom throw (const char*) that throw internally which one waiting for receive string type or char so throw it

    if (age > 120)
       throw "Age seems unrealistic";  // another custom error   
}

int main() {

    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    try {
        check_age(age);   // risky call
        std::cout << "Valid age entered \n";
    }

    catch (const char* msg) {        // catch custom type waiting for string
        std::cout << "Error: " << msg << '\n';
    }

    std::cout << "Program continues.....\n";
    return 0;
}