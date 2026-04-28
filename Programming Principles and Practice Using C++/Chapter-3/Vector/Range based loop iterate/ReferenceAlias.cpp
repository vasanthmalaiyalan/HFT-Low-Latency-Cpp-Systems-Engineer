#include <iostream>

int main() {

    int a = 10;
    int& b = a;

    std::cout << &a << '\n';
    std::cout << &b << '\n'; // same address

    b = 20;

    std::cout << a << '\n';
}