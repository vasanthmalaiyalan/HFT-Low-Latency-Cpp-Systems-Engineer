#include <iostream>
#include <stdexcept>

void error(std::string s) {

    throw std::runtime_error{s};
}

double read_number() {

    double d = 0;
    
    std::cin >> d;

    if (!std::cin)
         error("Couldn't read a double");

    return d;     
}

int main() {

    try {

        std::cout  << "Enter a number: ";
        double x = read_number();

        std::cout << "You entered: " << x << '\n';
        return 0;
    }
    catch (std::runtime_error& e) {

        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }
}