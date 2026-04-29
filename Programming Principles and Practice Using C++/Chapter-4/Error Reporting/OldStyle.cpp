#include <iostream>

int area(int length, int width) {

    if (length <= 0 || width <= 0)
        return -1;

    return length * width;    
}

int main() {

    int a = area(5, -2);

    // If you forget this check -> bug
    if (a == -1) 
        std::cout << "Error: invaild input\n";
    else 
         std::cout << "Area = " << a << '\n';
         
    return 0;     
}