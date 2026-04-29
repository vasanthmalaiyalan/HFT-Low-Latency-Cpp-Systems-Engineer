#include <iostream>
#include <stdexcept> // for runtime_error

// function 
double divide(int a, int b) { 

    if (b == 0) {
        throw std::runtime_error("Cannot divide by zero"); // throw
    }
    return (double)a / b;
}

int main() {

    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    try {
        double result = divide(x, y); // risky call
        std::cout << "Result = " << result << '\n';
    }

    catch (std::runtime_error& e) { // catch
        std::cout << "Error: " << e.what() << '\n';
    }

    std::cout << "Program continues......\n";
    return 0;
} 