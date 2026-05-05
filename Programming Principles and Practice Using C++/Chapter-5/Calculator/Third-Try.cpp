#include <iostream>

// ----------------- Token ------------------------
class Token {
    public:
       char kind;
       double value;
};

Token get_token() {

    char ch;
    std::cin >> ch;

    if (isdigit(ch)) {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token{'8', val}; // without constructor auto initilization happen
    }

    return Token{ch, 0}; // this one always same
}

// -------------- Primary ------------------------
double primary() {
    Token t = get_token(); // seperate object creation

    if (t.kind == '8') // address + offset(0)
       return t.value;

    std::cerr << "Error: number expected\n";
    return 0;   
}

// --------------- Term -----------------------------
double term() {

    double left = primary();

    Token t = get_token();

    while (true) {
        if (t.kind == '*') {
            left *= primary();
            t = get_token();
        }
        else if (t.kind == '/') {
            left /= primary();
            t = get_token();
        }
        else {
            std::cin.putback(t.kind);
            return left;
        }
    }
}

// ----------------- Expression ---------------------
double expression() {

    double left = term(); // start with term
    Token t = get_token(); // read next token

    while (true) {
        switch (t.kind) {
            case '+':
               left += term();  // add next term
               t = get_token();
               break;

            case '-':
               left -= term();  // subtract next term  
               t = get_token();
               break;
               
            default:
               std::cin.putback(t.kind);
               return left;  // no more   
        }
    }
}

//------------------ Main -------------------------
int main() {

    std::cout << "Enter expression: ";

    double result = expression();

    std::cout << "Result = " << result << "\n";
}