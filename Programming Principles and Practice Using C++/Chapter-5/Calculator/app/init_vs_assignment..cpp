#include <iostream>

class Token {
    public: 
      char kind;
      double value;
};

int main() {

    // ----------------------------------
    // 1. Initialization
    // ----------------------------------
    Token t1{'+', 3.14}; // create + set values

    std::cout << "Initialization:\n";
    std::cout << "t1.kind = " << t1.kind << "\n";
    std::cout << "t1.value = " << t1.value << "\n\n";

    // -----------------------------------
    // 2.Assignment
    // -----------------------------------
    Token t2; // object create (value undefined)

    t2.kind = '*'; // assign
    t2.value = 10.5; // assign

    std::cout << "Assignment:\n";
    std::cout << "t2.kind = " << t2.kind << '\n';
    std::cout << "t2.value = " << t2.value << '\n';

    return 0;
}