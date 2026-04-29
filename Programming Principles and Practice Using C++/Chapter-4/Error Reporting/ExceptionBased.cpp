#include <iostream>
#include <stdexcept>

// -------- Safe function --------------
int area(int length, int width) {

    if (length <= 0 || width <= 0) 
        throw std::invalid_argument("Error: length and width must be positive");

    return length * width;    
}

// ----------- Another function --------------
int framed_area(int x, int y) {

    constexpr int frame = 2;

    if (x <= frame || y <= frame)
        throw std::invalid_argument("Error: frame too large");

    return area(x - frame, y - frame);    
}

// --------- Main ---------------

int main() {

    try {

        int x, y;

        std::cout << "Enter width and height: ";
        std::cin >> x >> y;

        int result = framed_area(x, y);

        std::cout << "Framed area = " << result << '\n';
    }
    catch (const std::exception& e) {

        std::cout << e.what() << '\n';
    }

    return 0;
}