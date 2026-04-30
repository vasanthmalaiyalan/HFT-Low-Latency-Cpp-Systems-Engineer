// calc2.cpp
// Improved version: supports +, -, *, / and chaining

#include <iostream>

int main() {

    std::cout << "Please enter expression (we can handle +, -, *, /)\n";
    std::cout << "Add an x end expression (e.g., 1+2*3x): ";

    int lval = 0;
    std::cin >> lval; // first number

    if (!std::cin) {
        std::cout << "Error: no first operand\n";
        return 1;
    }

    for (char op; std::cin >> op; ) {

        if (op == 'x') {
            std::cout << "Result: " << lval << '\n';
            return 0;
        }

        int rval = 0;
        std::cin >> rval;

        if (!std::cin) {
            std::cout << "Error: no second operand\n";
            return 1;
        }

        switch (op) {
             case '+':
                 lval += rval;
                 break;

              case '-':
                  lval -= rval;
                  break;
                  
              case '*':
                  lval *= rval;
                  break;
                  
              case '/':
                  lval /= rval;
                  break;
                  
              default:
                  std::cout << "Result: " << lval << '\n';
                  return 0;    
        }
    }

    std::cout << "Error: bad expression\n";
    return 1;
}