#include <iostream>
#include <stdexcept> // for exception

// -------------- Base Function --------------
int area(int length, int width) {

    if (length <= 0 || width <= 0) 
        throw std::invalid_argument("Error: Length and width must be positive");

    return length * width;    
}

// ---------- Higher-level function ---------------
int framed_area(int x, int y) {

    constexpr int frame_width = 2;

    if (x <= frame_width || y <= frame_width)
       throw std::invalid_argument("Error: frame makes area non-positive");

    // reuse safe function
    return area(x - frame_width, y - frame_width);   
}

// ------------- Main (caller) --------------------

int main() {

    try { 

        int x, y;

        std::cout << "Enter width and heigth: ";
        std::cin >> x >> y;

        int result = framed_area(x, y);

        std::cout << "Frame area = " << result << '\n';
    }

    catch (const std::exception& e) {

        std::cout << e.what() << '\n';
    }

    return 0;
}