#include <iostream>
#include <stdexcept>

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

int compute(int a, int b, int c) {

    // Precondition: a > 0 and a < b < c
    
        if(!(a > 0 && a < b && b < c))
            error("Precondition failed: a > 0 and a < b < c");

        return a + b + c;    
}

int main() {

    try {

        std::cout << compute(1, 2, 3) << '\n';
        std::cout << compute(-1, 2, 3) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}