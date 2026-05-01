#include <iostream>

class Box {
    public:
      int value;
      int weight;
};

int main() {
    Box b;  // object create with empy memory space of 8 bytes

    b.value = 10;
    b.weight = 50;

    std::cout << "Value: " << b.value << "\n";
    std::cout << "Weight: " << b.weight << "\n";

    // address of full object
    std::cout << "Address of Full Object: " << &b << "\n";

    // Address of members
    std::cout << "Address of b.value: " << &b.value << "\n";
    std::cout << "Address of b.weight: " << &b.weight << "\n";
}