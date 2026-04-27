#include <iostream>

int main() {

    int a = 10;
    int b = 5;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    std::cout << "a = " << a << ", b = " << b << '\n';

    return 0;
}