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

        }
    }
}