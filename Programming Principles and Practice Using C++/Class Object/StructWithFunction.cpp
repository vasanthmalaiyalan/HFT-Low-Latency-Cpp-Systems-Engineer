#include <iostream>

struct Student {
    int id;       // both are default public
    double marks;

    // function inside struct
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
🧠 Explanation (Tamil)

👉 இங்கே:

struct Student → type
show() → function
check_pass() → function

👉 இது class மாதிரி தான் வேலை செய்கிறது ✔️

🟢 2. Output
ID: 101
Marks: 85.5
Pass
🟢 3. Key Point

👉 இது possible because:

C++ struct ≠ C struct

👉 C++ struct:

functions support ✔️
constructors support ✔️
access control support ✔️
🟢 4. Access control difference

👉 struct:

struct A {
    int x;   // public by default ✔️
};

👉 class:

class A {
    int x;   // private by default ❗
};
*/