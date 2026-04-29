#include <iostream>
#include <stdexcept>

int divide(int a, int b) {

    if (b == 0) 
       throw std::runtime_error("Cannot divide by zero");

    return a / b;   
}

int main() {

    try {

        int result = divide(10, 0);
        std::cout << result << '\n';
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}