#include <iostream>

// function 1: calculate square
int square(int x) {
    return x * x;
}

// function 2: print result
void print_square(int x) {
    std::cout << x << '\t' << square(x) << '\n';
}

int main() {
    for (int i = 0; i < 5; ++i) {
        print_square(i);
    }

    return 0;
}