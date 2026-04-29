#include <iostream>
#include <stdexcept>

// ----------- Error helper -----------------
void error (const std::string& msg) {

    throw std::runtime_error(msg);
}

// ---------- Safe division -----------------
double divide(double a, double b) {

    if (b == 0) 
       error("Division by zero");

    return a / b;   
}

// ------------- Read input safely ----------------
double read_number() {

    double x;

    std::cin >> x;

    if (!std::cin)
        error("Invalid number input");

     return x;   
}

//---------- Main --------------------

int main() {

    try {

        std::cout << "Enter two numbers: ";

        double a = read_number();
        double b = read_number();

        std::cout << "Debug: a = " << a << ", b = " << b << '\n'; // debug print

        double result = divide(a, b);

        std::cout << "Result = " << result << '\n';
    }
    catch (const std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}