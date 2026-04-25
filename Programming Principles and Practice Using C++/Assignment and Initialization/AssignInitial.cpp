#include <iostream>

int main() {
    int a = 3;  // initialization
    std::cout << "a = " << a << '\n';

    a = 4;   // assignment
    std::cout << "a = " << a << '\n';

    int b = a;  // copy value
    std::cout << "b = " << b << '\n';

    b = a + 5; // assignment with operation
    std::cout << "b = " << b << '\n';

    a = a + 7; // important
    std::cout << "a = " << a << '\n';

    return 0;
}