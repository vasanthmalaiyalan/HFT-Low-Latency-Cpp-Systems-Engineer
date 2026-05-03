// token_demo.cpp
// Demonstrates Token type (PPP book style, using <iostream>)

#include <iostream>

// -------------------------------------
// Token class (user-defined type)
// -------------------------------------
class Token {
    public:
       char kind; // what kind of token ('+', '-', '*', '/', '8' for number)
       double value; // value (only used if kind == '8)

       // constructor for number tokens
       Token(char k) : kind{k}, value{0.0} {}

       // constructor for number tokens
       Token(char k, double v) : kind{k}, value{v} {}
};

// ----------------------------------
// Main function (demo usage)
// ------------------------------------
int main() {

    // constructor call with object , why because class in side construction is just blueprint not memory so you call constructor you need object memory space
    Token t1 {'+'};

    // number token (using '8' to represent number, as in book)
    Token t2 {'8', 3.14};

    // access members
    std::cout << "t1.kind = " << t1.kind << "\n";
    std::cout << "t2.kind = " << t2.kind << "\n";
    std::cout << "t2.value = " << t2.value << "\n";

    // copy token
    Token t3 = t2;

    std::cout << "t3.value (copied) = " << t3.value << "\n";

    // assignment
    t1 = t2;
    std::cout << "t1.value (after assignment) = " << t1.value << "\n";

    return 0;
}

/*
🧠 Output Example
t1.kind = +
t2.kind = 8
t2.value = 3.14
t3.value (copied) = 3.14
t1.value (after assignment) = 3.14
🧠 What this code shows (Book concepts)
✔ Token = (kind, value)
kind → type (operator / number)
value → numeric value (only for numbers)
✔ '8' usage
Token t2 {'8', 3.14};

👉 '8' = number token indicator (book trick)

✔ Constructors
Token(char k)
Token(char k, double v)

👉 clean initialization
👉 no uninitialized garbage

✔ Member access
t2.value
t1.kind
✔ Copy & Assignment
Token t3 = t2;   // copy
t1 = t2;         // assignment
🎯 Real Understanding

👉 This file is NOT calculator yet

👉 It only proves:

We can represent tokens cleanly
🔥 Important Insight

👉 Without this:

❌ parsing impossible
❌ messy logic

👉 With this:

✔ structured input
✔ easy processing

💬 Simple Tamil Summary

👉 Token class:

kind → என்ன token
value → number value

👉 '8' → number represent

👉 constructor → safe initialization

🚀 Next Step (VERY IMPORTANT)

Now next section:

👉 Token_stream (input → tokens conversion)

That’s where real calculator starts 🔥
*/