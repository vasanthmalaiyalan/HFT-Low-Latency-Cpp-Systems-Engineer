#include <iostream>

int area(int length, int width) {

    if (length <= 0 || width <= 0)
        return 0;

    return length * width;    
}

int framed_area(int x, int y) {
    return area(x - 2, y - 2);
}

void test(int x, int y, int z) {
    int area1 = area(x, y);
    int area3 = framed_area(y, z);

    if (area3 == 0) {
        std::cout << "Error: division by zero\n";
        return;
    }

    double ratio = double(area1) / area3;
    std::cout << ratio << '\n';
}

int main() {
    test(-1, 2, 3);
}