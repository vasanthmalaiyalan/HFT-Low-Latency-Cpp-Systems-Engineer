#include <iostream>
#include <stdexcept>

int main() {

    try {
        throw std::runtime_error("Something went wrong");
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}