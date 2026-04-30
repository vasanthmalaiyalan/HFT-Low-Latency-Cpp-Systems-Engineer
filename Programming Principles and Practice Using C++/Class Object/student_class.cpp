#include <iostream>

class Student {
    public:
        int id;
        double marks;

        void show() {
            std::cout << "ID: " << id << "\n";
            std::cout << "Marks: " << marks << "\n";
        }

        void check_pass() {
            if (marks >= 50)
               std::cout << "Pass\n";
            else 
               std::cout << "Fail\n";   
        }
};

int main() {
    Student s1;

    s1.id = 101;
    s1.marks = 85.5;

    s1.show();
    s1.check_pass();

    return 0;
}

/*
🧠 Difference Clear ஆகணும் 🔥
Feature	struct (C style)	class (C++)
Data	✔️	✔️
Functions	❌	✔️
Encapsulation	❌	✔️


struct = data box 📦
class = smart object 🤖
*/