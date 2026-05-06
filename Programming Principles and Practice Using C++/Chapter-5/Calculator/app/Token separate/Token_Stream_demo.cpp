#include <iostream>
#include <stdexcept>
#include <cctype>

// ============================================
// Token
// ============================================

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

// ==================================================
// Error helper
// ==================================================

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// ================================================
// Token_stream
// ====================================================

class Token_stream {

    public:
       
    Token_stream()
        : full{false}, buffer{'0'}
    {
    }
    
    Token get();   // get next token
    void putback(Token t); // put token back

  private:
     
  bool full; // is buffer occupied
  Token buffer; // stores one token
};

// -----------------------------------------------
// putback()
// -----------------------------------------------

void Token_stream::putback(Token t) {

    if (full)
        error("putback into full buffer");

     buffer = t;
     full = true;   
}

// =================================================
// get()
// =================================================

Token Token_stream::get() {

    // use buffered token first
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch (ch) {

        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case ';':
        case 'q':
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

            return Token{ '8', val};
        }
        
        default:
          error("Bad token");
    }

    return Token{'0'};
}

// ================================================
// Main demo
// ===============================================

int main() {

    try {
        Token_stream ts;

        std::cout << "Enter tokens: \n";

        while (true) {

            Token t = ts.get();

            if (t.kind == 'q')
                break;

            if (t.kind == '8')
                std::cout << "Number: " << t.value << '\n';
            else 
               std::cout << "Token: " << t.kind << '\n';      
        }
    }
    catch (std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
    }
}

/*
▶️ Compile
g++ -std=c++17 -Wall -Wextra -Werror -pedantic token_stream_demo.cpp -o demo
▶️ Run
./demo
🧪 Example

Input:

12+3.5*q

Output:

NUMBER: 12
TOKEN : +
NUMBER: 3.5
TOKEN : *
🧠 6. Why putback() needed?

👉 Example:

Input:

1+2

👉 expression() reads:

1
+

👉 next function may need:

+

👉 so:

ts.putback(t);
💬 Simple Tamil Summary

👉 Token_stream:

✔ characters → tokens
✔ token buffering
✔ putback support

👉 public:

user interface

👉 private:

hidden implementation
🎯 Final Takeaway
Token_stream = smart token input system
🚀 One-line
Parser reads tokens through Token_stream, not directly from cin
*/
