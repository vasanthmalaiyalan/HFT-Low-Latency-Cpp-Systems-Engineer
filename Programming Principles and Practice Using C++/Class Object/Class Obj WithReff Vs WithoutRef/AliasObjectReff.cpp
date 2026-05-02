#include <iostream>

class Box {
    public:
      int value;  // this is compailer layout
};

void change_with(Box& x) { // assign inside main  starting address  store in &x
    std::cout << "Function address (&x): " << &x << "\n";
    x.value = 300; // memory + inside metalayout value offset
}

int main() {
    Box b;
    b.value = 10;

    std::cout << "Main address (&b): " << &b << "\n";
    change_with(b);
}