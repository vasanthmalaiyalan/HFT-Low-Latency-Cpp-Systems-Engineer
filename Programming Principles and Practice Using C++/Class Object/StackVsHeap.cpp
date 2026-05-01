#include <iostream>

class Point {
    public:
       double x, y;

       Point(double a, double b) : x(a), y(b) {}

       double distanceFromOrigin() {
        return x * y * + y * y; 
       }
};

int main() {
    // Stack - fast , auto cleanup
    Point p1(3.0, 4.0);
    std::cout << "Stack Point distance: " << p1.distanceFromOrigin() << "\n";

    // Heap - flexible, manual cleanup
    Point* p2 = new Point(6.0, 8.0);
    std::cout << "Heap Point distance: " << p2->distanceFromOrigin() << "\n";

    delete p2;

    // Modern c++ - smart pointer (auto delete)
    // #include <memory> 
    // std::unique_ptr<Point> p3 = std::make_unique<Point>(1.0, 2.0);
    // delete - auto cleanup!

    return 0;
}

/*
Stack Object (Point p1):
────────────────────────
p1.x → [3.0]   offset 0
p1.y → [4.0]   offset 8
auto destroy ✅

Heap Object (Point* p2):
────────────────────────
Stack: p2 → [0x5500]  ← pointer மட்டும்
              ↓
Heap:  [6.0][8.0]     ← actual data
manual delete ❌ (forget பண்ணா leak!)
*/