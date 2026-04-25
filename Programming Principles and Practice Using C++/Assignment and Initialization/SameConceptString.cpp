#include <iostream>
#include <string>

int main() {
    std::string a = "alpha"; // initialization

    a = "beta";  // assignment

    std::string b = a; // copy

    b = a + "gamma"; // concatenate

    a = a + "delta"; // modify a

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';

    return 0;
}