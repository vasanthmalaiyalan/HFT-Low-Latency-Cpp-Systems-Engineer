#include <iostream>
#include <stdexcept>

int main() {

    try {
        std::cout << "Start\n";
        throw std::runtime_error("Error!\n");
        std::cout << "End!\n"; // if throw success next End block didn't run 
    }
    catch (std::runtime_error& e) {
        std::cout << "Caught: " << e.what();
    }
}