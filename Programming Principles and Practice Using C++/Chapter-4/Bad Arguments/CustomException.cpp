#include <iostream>

// --------- Custom exception ------------
class Bad_area {};

// ------------Function -----------------
int area(int length, int width) {

    if (length <= 0 || width <= 0) {
        throw Bad_area{};

     return length * width;   
    }

    int framed_area(int x, int y) {

        constexpr int frame = 2;

        return area(x - frame, y - frame);
    }

    void test(int x, int y, int z) {

        int area1 = area(x , y);
        int area2 = framed_area(1, z);
        int area3 = framed_area(y, z);

        double ratio = double(area1)  area3;

        std::cout << "Ratio = " << ratio << '\n'; 
    }

    // ------------- Main ----------------
    int main() {

        try {

            test(-1, 2, 4); // invaild input
        }
        catch (Bad_area) {

            std::cout << "Oops ! bad arguments to area()\n";
        }

        return 0;
    }
}