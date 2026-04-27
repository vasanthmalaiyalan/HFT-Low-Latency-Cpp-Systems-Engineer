#include <iostream>

int main() {

    int a = 10, b = 3;

    std::cout << "Add: " << a + b << '\n';
    std::cout << "Sub: " << a - b << '\n';
    std::cout << "Mul: " << a * b << '\n';
    std::cout << "Div: " << a / b << '\n';
    std::cout << "Mod: " << a % b << '\n';

    ++a;
    std::cout << "a = 10 After ++a: " << a << '\n';
    
    a += 5;
    std::cout << "After +=5: " << a << '\n';

    std::cout << "a > b: " << (a > b) << '\n';
    std::cout << "a == b: " << (a == b) << '\n';
    
    bool cond = (a > 5) && (b > 5);
    std::cout << "Logical AND: " << cond << '\n';

    return 0;
 }

 /*
 Add: 13
Sub: 7
Mul: 30
Div: 3
Mod: 1
a = 10 After ++a: 11
After +=5: 16
a > b: 1
a == b: 0
Logical AND: 0
 */