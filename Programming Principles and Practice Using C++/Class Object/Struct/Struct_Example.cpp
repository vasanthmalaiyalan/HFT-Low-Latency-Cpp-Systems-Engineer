#include <iostream>
#include <string>

// struct = simple data container (data only)
struct Student {
    int id;   // public by default
    std::string name; // public
    double marks;  //public
};

int main() {
    Student s1; // object create

    // direct access (no control)
    s1.id = 101;
    s1.name = "Vasanth";
    s1.marks = 85.5;

    std::cout << "ID: " << s1.id << "\n";
    std::cout << "Name: " << s1.name << "\n";
    std::cout << "Marks: " << s1.marks << "\n";

    // problem: no vaildation
    s1.marks = -100; // logical wrong, but allowed

    std::cout << "After wrong update: " << s1.marks << "\n";

    return 0; 
}

/*
🧠 Key idea
struct → data மட்டும்
no rules ❌
no control ❌
*/