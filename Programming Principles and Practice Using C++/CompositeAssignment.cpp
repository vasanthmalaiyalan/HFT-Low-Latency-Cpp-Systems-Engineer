#include <iostream>

int main() {

    int a = 10;

    a += 5; // 15
    std::cout << "a = " << a << '\n';

    a -= 3; // 12
    std::cout << "a = " << a << '\n';

    a *= 2; // 24
    std::cout << "a = " << a << '\n';

    a /= 4; // 6
    std::cout << "a = " << a << '\n';

    a %= 4; // 2
    std::cout << "a = " << a << '\n';

    return 0;
}