#include <iostream>

int main() {

    std::cout << "Please enter expression (we can handle + and -): ";

    int lval = 0; // left value
    int rval = 0; // right value
    char op = 0; // operator
    int res = 0; // result

    std::cin >> lval >> op >> rval; // example: 2 + 3
    
    if (op == '+')
       res = lval + rval;
    else if (op == '-')
       res = lval - rval;
       
    std::cout << "Result: " << res << '\n';
    
    return 0;
}