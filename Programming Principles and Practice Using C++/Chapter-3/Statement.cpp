#include <iostream>

int main() {

    // Declaration + Initialization
    int a = 5;
    int b = 10;

    // Expression statement (assignment) 
    a = b; // a becomes 10

    // Increment 
    ++a; // a becomes 11

    // Output statement
    std::cout << "Value of a: " << a << '\n';

    // Execution order demo
    int x = 1;
    x = x + 2; // 3
    x = x * 2; // 6
    std::cout << "x = " << x << '\n';

    // Correct mistake (empty statement)
    if (a == 11)  {
        std::cout << "a is 11\n";
    }

    // Common mistake (empty statement)
    /*if (a == 100); // <---- wrong 
    {
        std::cout << "This will ALWAYS run (bugs!)\n";
    }*/
    return 0;



}