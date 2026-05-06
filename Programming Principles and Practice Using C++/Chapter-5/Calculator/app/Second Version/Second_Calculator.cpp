#include <iostream>
#include <stdexcept>
#include <cctype>

// ==============================================
// Token 
// ===============================================

class Token {
    public:
      char kind;
      double value;

    Token(char k)
       : kind{k}, value{0}
    {
    }
    
    Token(char k, double v)
       : kind{k}, value{v}
    {
    }
};

// ===============================================
// Error
// ===============================================

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// ================================================
// Token_tream
// ================================================

class Token_stream {
    public:
       Token_stream()
           : full{false}, buffer{'0'}
       {

       }
       
       Token get();
       void putback(Token t);

    private:
       bool full;
       Token buffer;   
};

// ----------------------------------------------

void Token_stream::putback(Token t) {

    if (full)
       error("putback() into full buffer");

    buffer = t;
    full = true;   
}

// ------------------------------------------------

Token Token_stream::get() {

    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch (ch) {

        case ';':
        case 'q':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
          return Token{ch};

        case '.':
        case '0': case '1': case '2':
        case '3': case '4': case '5':
        case '6': case '7': case '8':
        case '9':
        {
            std::cin.putback(ch);

            double val;
            std::cin >> val;

            return Token{'8', val};
        }  

        default:
           error("Bad Token");
    }

    return Token{'0'};
}

// ================================================

Token_stream ts;

double expression();

// ===============================================
// primary
// ================================================

double primary() {

    Token t = ts.get();

    switch (t.kind) {

        case '(': {

            double d = expression();

            t = ts.get();

            if (t.kind != ')')
               error("')' expected");

            return d;   
        }

        case '8':
          return t.value;

        default:
           error("Primary expected");  
    }

    return 0;
}

// ================================================
// term
// ===============================================

double term() {

    double left = primary();

    Token t = ts.get();

    while(true) {

        switch (t.kind) {

            case '*':
               left *= primary();
               t = ts.get();
               break;

            case '/':
             {
                double d = primary();

                if (d == 0)
                   error("divide by zero");

                left /= d;
                t = ts.get();
                break;   
             }  
             
             default:
                ts.putback(t); // default set in (+)
                return left;
        }
    }
}

// =============================================
// expression
// =============================================

double expression() {

    double left = term();

    Token t = ts.get();

    while (true) {

        switch (t.kind) {

            case '+':
               left += term();
               t = ts.get();
               break;

            case '-':
               left -= term();
               t = ts.get();
               break;
               
            default:
               ts.putback(t);
               return left;   
        }
    }
}

// =============================================4
// Main
// ===============================================

int main() 
 try {
    std::cout << "Simple Calculator\n";
    std::cout << "Use ';' to print\n";
    std::cout << "Use 'q' tp quit\n\n";

    double val = 0;

    while (std::cin) {

        Token t = ts.get();

        if (t.kind == 'q')
          break;

        if (t.kind == ';') {
           std::cout << "= " << val << '\n';  
    }
    else {
        ts.putback(t);
        val = expression();
    }
 }

}
catch (std::exception& e) {

    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {

    std::cerr << "Unknow exception\n";
    return 2;
}

/*
▶️ Compile
g++ -std=c++17 -Wall -Wextra -Werror -pedantic calculator_v3.cpp -o calc
▶️ Run
./calc
🧪 Example

Input:

2+3;
3+4*5;
q

Output:

= 5
= 23
🧠 Important Lesson

👉 Programs need:

Clear communication protocol
💥 BIG INSIGHT
Parser correctness alone போதாது ❌
Interactive behaviorவும் important ✔
💬 Simple Tamil Summary

👉 Bug:

parser correct ✔
output delayed ❌

👉 Solution:

';' → print
'q' → quit
🎯 Final Takeaway
Good software = correct logic + good interaction
*/