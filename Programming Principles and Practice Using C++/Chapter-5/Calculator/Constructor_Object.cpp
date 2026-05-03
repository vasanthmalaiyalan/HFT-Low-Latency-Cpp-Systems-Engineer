// token_full_demo.cpp
// Demonstrates Token construction, memory initialization, and behavior

#include <iostream>

class Token {
    public:
       char kind;
       double value;

       // Constructor for operator
       Token(char k) : kind{k}, value{0.0} {
           std::cout << "[Constructor] this= " 
                     << this << " kind= " 
                     << kind << " value= " 
                     << value << '\n';
       }

       // Constructor for number
       Token(char k, double v) : kind{k}, value{v} {
           std::cout << "[Constructor] this= " 
                     << this << " kind= " 
                     << kind << " value= " 
                     << value << "\n";
       }

       void print() const {
           std::cout << "Object at " << this 
                     << " -> kind: " << kind
                     << ", value: " << value << "\n";
       }
};

int main() {

    std::cout << "Creating t1........\n";
    Token t1 {'+'};   // Token::Token(&t1, '+'); internally

    std::cout << "\nCreating t2...........\n";
    Token t2 {'8', 3.14}; // args pass

    std::cout << "\nPrinting object:\n";
    t1.print();
    t2.print();

    std::cout << "\nAssignment(t1 = t2):\n";
    t1 = t2;         // assignment
    t1.print();

    return 0;
}

/*
./a.out 
Creating t1........
[Constructor] this= 0x7ffeefe96aa0 kind= + value= 0

Creating t2...........
[Constructor] this= 0x7ffeefe96ab0 kind= 8 value= 3.14

Printing object:
Object at 0x7ffeefe96aa0 -> kind: +, value: 0
Object at 0x7ffeefe96ab0 -> kind: 8, value: 3.14

Assignment(t1 = t2):
Object at 0x7ffeefe96aa0 -> kind: 8, value: 3.14
*/