#include <iostream>
#include <stdexcept> // for run_time

// simple error function
void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// library-like function (we assume we cannot modify this)
int area(int length, int width) {

    return length * width;
}

// helper function
int framed_area(int x, int y) {

    constexpr int frame_width = 2; // "Compile time-லயே calculate பண்ணிடு" என்று compiler-க்கு சொல்வது.
    return area(x - frame_width, y - frame_width);
}

int main() {

    try { // try function control the block if error stop the block run catch
        int x = -1;
        int y = 2;
        int z = 3;

        // caller check before calling area()
        if (x <= 0 || y <= 0)
            error("Invaild arguments for area()");

        int area1 = area(x, y);

        // Caller checks before calling  framed_area()
        constexpr int frame_width = 2;

        if (1 - frame_width <= 0 || z - frame_width <= 0)
             error("Invaild arguments for framed_area(1, z)");

        int area2 = framed_area(1, z);
        
        if (y - frame_width <= 0 || z - frame_width <= 0)
            error("Invalid arguments for framed_area(y, z)");

        int area3 = framed_area(y, z);
        
        // prevent divide by zero
        if (area3 == 0)
               error("Division by zero");

        double ratio = double(area1) / area3;  
        
        std::cout << "ratio" << ratio << '\n';
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}