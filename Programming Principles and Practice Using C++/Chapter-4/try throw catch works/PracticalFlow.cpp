#include <iostream>
#include <stdexcept>

int divide(int a, int b) {

    if (b == 0) 
         throw std::runtime_error("Division by zero\n");

     return a / b;    
}

int main() {

    try {
        std::cout << divide(10, 0);
    }
    catch (std::runtime_error& e) {

        std::cout << "Error: " << e.what();
    }
}