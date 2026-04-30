#include <iostream>

struct Student {
    int id;
    double marks;
};

int main() {
    Student s1;

    s1.id = 101;
    s1.marks = 85.5;

    std::cout << "ID: " << s1.id << "\n";
    std::cout << "Marks: " << s1.marks << "\n";

    return 0;
}

/*
🧠 Tamil Explanation

👉 இது என்ன?

struct → data container
functions இல்லை
logic outside

👉 Example:

Student = data மட்டும்
🔴 Problem (Why not enough?)

👉 Suppose:

marks update பண்ணணும்
pass/fail check பண்ணணும்

👉 இப்ப எப்படி?

if (s1.marks >= 50) ...

👉 logic separate ஆகும் ❌
*/