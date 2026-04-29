#include <iostream>
#include <stdexcept>

void func2() {

    std::string s = "inside func2";
    throw std::runtime_error("Error in func2");
}

void func1() {

    std::string s = "inside func1";
    func2();
}

int main() {

    try {
        func1();
    }
    catch (std::runtime_error& e) {

        std::cout << e.what();
    }
}