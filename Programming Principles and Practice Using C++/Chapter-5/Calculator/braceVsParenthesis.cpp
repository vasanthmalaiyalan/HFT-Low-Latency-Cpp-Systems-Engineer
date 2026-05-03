#include <iostream>

class Test {
    public:
       char c;

       // constructor
       Test(char x) : c{x} {
            std::cout << "Constructor called with char: " << c << "\n";
       }
};

int main() {

    std::cout << "====== SAFE CASE =======\n";
    Test t1('A');     // () initialization
    Test t2{'A'};     // {} initialization

    std::cout <<  "\n======DANGEROUS VS SAFE======\n";

    // implicit conversion (double -> char)
    Test t3(65.9); // allow -> becomes 'A'
    std::cout << "t3.c = " << t3.c << "\n";
    
    // Narrowing conversation blocked
    // Test t4{65.9}; // Error (uncomment to see compile error)

    std::cout << "\n===== BIG VALUE CASE ========\n";

    Test t5(300); // allowed (overflow -> unexcepted char)
    std::cout << "t5.c = " << t5.c << "\n";

    // prevent bug
    // Test t6{300}; // Error (Safe, block invaild value)

    return 0;
}

/*
 ./a.out 
====== SAFE CASE =======
Constructor called with char: A
Constructor called with char: A

======DANGEROUS VS SAFE======
Constructor called with char: A
t3.c = A

===== BIG VALUE CASE ========
Constructor called with char: ,
t5.c = ,
*/