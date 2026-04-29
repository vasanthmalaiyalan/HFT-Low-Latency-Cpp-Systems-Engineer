#include <iostream>

int main() {

    // string literal
    const char* msg = "hello";

    std::cout << "Full string: " << msg << '\n';

    // pointer details
    std::cout << "Address (msg): " << (void*)msg << '\n';
    std::cout << "First char (*msg); " << *msg << '\n';

    // traversal nanually using pointer in cout
    std::cout << "Manual traversal: ";
    const char* p = msg;

    while (*p != '\0') {
        std::cout << *p;
        p++; // move pointer
    }
    std::cout << '\n';

    // pointer shifting 
    std::cout << "msg + 1: " << msg + 1 << '\n';
    std::cout << "msg + 2: " << msg + 2 << '\n';

    return 0;
}