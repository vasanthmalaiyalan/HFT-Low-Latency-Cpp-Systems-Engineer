#include <iostream>

int area(int length, int width); // declaration

int main() {

    int x = area(2, 3);
    std::cout << x << '\n';
}

// definition
int area(int x, int y) {
    return x * y;
}