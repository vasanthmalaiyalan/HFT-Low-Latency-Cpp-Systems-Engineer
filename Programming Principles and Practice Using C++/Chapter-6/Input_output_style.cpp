// chapter 6.2 - input and output style calculator loop

#include <iostream>

// --------------------------------------------------
// Token
// --------------------------------------------------

class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0} {}

       Token(char k, double v) : kind{k}, value{v} {}
};

// ---------------------------------------------
// Token_stream (minimal placeholder version)
// --------------------------------------------

class Token_stream {
    public:
       Token get() {

        char ch = 0;
        std::cin >> ch;

        switch (ch) {

            case ';':
            case 'q':
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
               return Token{ch};

            default:
            
               if (std::isdigit(ch) || ch == '.') {
                  std::cin.putback(ch);

                  double value = 0;
                  std::cin >> value;

                  return Token{'8', value};
               }

               std::cerr << "Bad token\n";
               return Token{'q'};
           }
       }

       void putback(Token) {

          // simplified for now
       }
};

// -------------------------------------------------
// Global Token Stream
// -------------------------------------------------

Token_stream ts;

// -------------------------------------------------
// Expression placeholder
// ------------------------------------------------

double expression() {

    Token t = ts.get();

    if (t.kind == '8') {
        return t.value;
    }

    return 0;
}

// -------------------------------------------------
// Main
// -------------------------------------------------

int main() {

    std::cout << "Simple Calculator\n";
    std::cout << "Use ; to print result\n";
    std::cout << "Use q to quit\n\n";

    double val = 0;

    while (std::cin) {

        std::cout << "> ";

        Token t = ts.get();

        if (t.kind == 'q') {
            break;
        }

        if (t.kind == ';') {

            std::cout << "= " << val << '\n';
        }
        else {

            ts.putback(t);

            val = expression();
        }
    }

    return 0;
}