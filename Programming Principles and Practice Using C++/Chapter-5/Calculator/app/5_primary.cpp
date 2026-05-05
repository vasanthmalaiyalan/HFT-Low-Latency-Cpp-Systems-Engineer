#include <iostream>
#include <cctype>

// -------------- Token ------------------------
class Token {
    public:
       char kind; // '8' = number, '+', '-', '*', '/', '(', ')'
       double value;
};

// ------------------- Error ---------------------
void error(const char* msg) {
    std::cerr << "Error: " << msg << '\n';
    exit(1);
}

// ------------------ get_token() -------------------
Token get_token() {

    char ch;
    std::cin >> ch;

    if (isdigit(ch) || ch == '.') {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token{'8', val}; // number
    }

    return Token{ch, 0}; // operator
}

// forward declarations
double expression();

// ------------ Primary --------------------------
double primary() {

    Token t = get_token();

    switch (t.kind) {

        case '(': // handle (expression)
        {
            double d = expression();

            t = get_token();
            if (t.kind != ')')
               error("')' expected");

            return d;   
        }

        case '8':  // number
           return t.value;

        default:
           error("primary expected");
           return 0;   
    }
}

// ------------------- Term ----------------------
double term() {

    double left = primary();

    Token t = get_token();

    while (true) {
        switch (t.kind) {

            case '*':
              left *= primary();
              t = get_token();
              break;

            case '/': {

                double d = primary();
                if (d == 0)
                   error("divide by zero");

                left /= d;
                t = get_token();
                break;   
            }  

            default:
               std::cin.putback(t.kind);
               return left;
        }
    }
}

// ------------------ Expression ------------------
double expression() {

    double left = term();

    Token t = get_token();

    while (true) {
        switch (t.kind) {

            case '+':
               left += term();
               t = get_token();
               break;

            case '-':
               left -= term();
               t = get_token();
               break;
               
            default:
               std::cin.putback(t.kind);
               return left;   
        }
    }
}

// ------------ Main -------------------------------
int main() {

    std::cout << "Enter expression: ";

    double result = expression();

    std::cout << "Result = " << result << '\n';
}