#include <iostream>

struct Student {
    int id;
    double marks;

    // constructor
    Student(int i, double m) {
        id = i;
        marks = m;
    }

    void show_data() {
        std::cout << "Data: " << id << ", " << marks << "\n";
    }
};

int main() {
    Student s1(101, 41.5); // works same as class
    s1.show_data();
}