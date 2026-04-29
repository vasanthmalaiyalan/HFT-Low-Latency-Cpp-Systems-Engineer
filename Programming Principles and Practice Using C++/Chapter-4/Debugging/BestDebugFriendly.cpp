#include <iostream>
#include <stdexcept>

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

int area(int w, int h) {

    if (w <= 0 || h <= 0) 
       error("Invalid dimension");

    return w * h;   
}

int main() {

    try {

        int w, h;

        std::cout  << "Enter width & height: ";
        std::cin >> w >> h;

        std::cerr << "Debug: w = " << w << ", h = " << h << '\n';

        int result = area(w, h);

        std::cout << "Area = " << result << '\n';
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
    }
}