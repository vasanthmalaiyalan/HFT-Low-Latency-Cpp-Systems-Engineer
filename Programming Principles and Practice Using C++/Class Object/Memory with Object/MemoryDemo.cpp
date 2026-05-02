#include <iostream>

class Box {
    public:
      int value;   // 4 byte
};

int main() {
    Box b; // create 4 byte object with empty space

    // uninitialized value (may be garbage)
    std::cout << "Initial value (garbage): " << b.value << "\n";

    // Assign value
    b.value = 10;

    std::cout << "Value: " << b.value << "\n";

    // address of object
    std::cout << "Address of object b: " << &b << "\n";

    // Address of member
    std::cout << "Address of b.value: " << &b.value << "\n";

    //Size of object
    std::cout << "Size of Box: " << sizeof(Box) << " bytes\n";

    //size of object
    std::cout << "Size of Object: " << sizeof(b) << " bytes\n";

    return 0;
}

/*
Initial value (garbage): 29138
Value: 10
Address of object b: 0x7ffc36ccf9a4
Address of b.value: 0x7ffc36ccf9a4
Size of Box: 4 bytes
Size of Object: 4 bytes
*/