#include <iostream>

class Box {
    public:
      int value;
};

int main() {
    Box b;
    b.value = 50;

    // --------Reference declaration -------------
    Box& ref = b; // ref is alias for b (ref inside first address assign)

    std::cout << "Original b value: " << b.value << "\n";
    std::cout << "Reference ref value: " << ref.value << "\n";

    // ---------- Address-of operator ---------------
    std::cout << "\nAddress of b (&b): " << &b << "\n";
    std::cout << "Address of ref (&ref): " << &ref << "\n";

    // ------- Modify using reference -------------
    ref.value = 100;

    std::cout << "\nAfter modify ref:\n";
    std::cout << "b.value: " << b.value << "\n";
    std::cout << "ref.value: " << ref.value << "\n";

}