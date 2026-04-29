#include <iostream>
#include <stdexcept>

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

int main() {

    try {
        error("Something went wrong");
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what() << '\n'; // what is return and e is variable of throwing error
    }
}