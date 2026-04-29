#include <iostream>
#include <stdexcept>

int area(int w, int h) {

    if (w <= 0 || h <= 0)
       throw std::runtime_error("Invalid input");

    return w * h;   
}

void test(int w, int h) {

    try {
        int result = area(w , h);
        std::cout << "area(" << w << "," << h << ") = " << result << '\n';
    }
    catch (...) { // this means all exception type
        std::cout << "area(" << w << "," << h << ") = ERROR\n";
    }
}

int main() {

    // Normal
    test(5, 3);

    // Edge
    test(1, 1);

    // Invalid
    test(-2, 4);

    return 0;

}