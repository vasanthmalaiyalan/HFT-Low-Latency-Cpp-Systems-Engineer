#include <iostream>

int main() {
    int x = 65;

    char* p = (char*)&x;

    std::cout << "Address: " << (void*)p << "\n";
    std::cout << "First byte as char: " << *p << "\n";
    std::cout << "p: " << p << "\n";
}