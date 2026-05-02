#include <iostream>

class Box {
    public:
       int value;
};

// -------- WITHOUT & (copy) -----------------
void change_without(Box b) { // sperate obj create with copy value (b vail is inside function)
    std::cout << "\n[WITHOUT &]\n";
    std::cout << "Function b address: " << &b << "\n";

    b.value = 100;
    std::cout << "Function b value: " << b.value << "\n";
}

// ---------- WITH & (reference) ------------------
void change_with(Box& b) {  // ref as main b first address store inside b
    std::cout << "\n[WITH &]\n";
    std::cout << "Function b address: " << &b << "\n";

    b.value = 200;
    std::cout << "Function b value: " << b.value << '\n';
}

// ------------- MAIN -------------------
int main() {
    Box b;
    b.value = 10; // empty memory sapce with offset store in value 50 (address + offset)

    std::cout << "Main b address: " << &b << "\n";
    std::cout << "Main b value: " << b.value << "\n";

    // WITHOUT &
    change_without(b); // obj value only copy to function separate obj
    std::cout << "After change_without, main b value: " << b.value << "\n";

    // WITH &
    change_with(b);
    std::cout << "After change_with, main b value: " << b.value << "\n";

    return 0;



}