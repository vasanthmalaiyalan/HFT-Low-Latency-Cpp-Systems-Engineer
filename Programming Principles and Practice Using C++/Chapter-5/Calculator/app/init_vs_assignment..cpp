#include <iostream>

class Token {
    public: 
      char kind;
      double value;
};

int main() {

    // ----------------------------------
    // 1. Initialization
    // ----------------------------------
    Token t1{'+', 3.14}; // create + set values

    std::cout << "Initialization:\n";
    std::cout << "t1.kind = " << t1.kind << "\n";
    std::cout << "t1.value = " << t1.value << "\n\n";

    // -----------------------------------
    // 2.Assignment
    // -----------------------------------
    Token t2; // object create (value undefined)

    t2.kind = '*'; // assign
    t2.value = 10.5; // assign

    std::cout << "Assignment:\n";
    std::cout << "t2.kind = " << t2.kind << '\n';
    std::cout << "t2.value = " << t2.value << '\n';

    return 0;
}


/*
🧠 Output
Initialization:t1.kind  = +t1.value = 3.14Assignment:t2.kind  = *t2.value = 10.5

🧠 Breakdown
🟢 Initialization
Token t1{'+', 3.14};
👉 one step:
object create + values set ✔

🟢 Assignment
Token t2;t2.kind = '*';t2.value = 10.5;
👉 two steps:
1. object create2. later values assign

🔥 Important difference (memory view)
Initialization
[create t1] → fill kind + value immediately

Assignment
[create t2] → empty/garbagethen → fill values

⚠️ Important note
Token t2;
👉 t2.value initially:
undefined (garbage value) ❗

🎯 Final Summary
TypeCodeMeaningInitializationToken t{'+',3.14};create + setAssignmentt.kind='+';change existing

🚀 One-line
Initialization = born with valueAssignment     = value changed later

If you want next 🔥
👉 copy vs move vs assignment operator
👉 constructor call trace (with print)
Just tell 👍

*/