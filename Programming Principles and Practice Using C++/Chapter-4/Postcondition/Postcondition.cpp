#include <iostream>
#include <stdexcept>

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

void expect(bool cond, const std::string& msg) {

    if (!cond) 
       error(msg);
}

int area(int length, int width) {

    //Precondition: length > 0 && width > 0
    // Postcondition: result > 0
    
        expect(length > 0 && width > 0, "bad arguments");

        int a = length * width;

        expect(a > 0, "bad result"); // postcondition

        return a;
}

    int main() {

        try {
            std::cout << area(5, 3) << '\n';
            std::cout << area(1000000, 1000000) << '\n'; // Overflow case
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
