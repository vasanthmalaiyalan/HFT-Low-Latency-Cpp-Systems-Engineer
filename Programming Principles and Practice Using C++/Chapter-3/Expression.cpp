#include <iostream>

int main() {

    // Literals + Initialization
    int length = 10;
    int width = 5;

    std::cout << "Length: " << length << '\n';
    std::cout << "Width: " << width << '\n';

    // Expression (area)
    int area = length * width;
    std::cout << "Area = length * width = " << area << '\n';

    // Assignment (lvalue / rvalue)
    length = 20; // lvalue = rvalue
    std::cout << "New length = " << length << '\n';

    // Operator precedence
    int wrong_perimeter = length + width * 2;
    std::cout << "Wrong perimeter (no brackets): " << wrong_perimeter << '\n';

    // Correct using parentheses
    int correct_perimeter = (length + width) * 2;
    std::cout << "Correct perimeter: " << correct_perimeter << '\n';

    // Complex expression (but readable)
    int sum = length + width;
    int doubled = sum * 2;
    
    std::cout << "Step-by-step perimeter: " << doubled << '\n';

    return 0;
}