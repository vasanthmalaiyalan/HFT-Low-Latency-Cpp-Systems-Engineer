#include <iostream>

// dummmy Token (simplified)
struct Token {
    char kind;
};

Token get_token() {
    Token t;
    std::cin >> t.kind;
    return t;
}

double term() {
    return 1; // dummy (just for demo)
}

// worong implementation
double expression() {

    double left = expression(); // infinite recursion

    Token t = get_token();

    switch (t.kind) {
        case '+':
           return left + term();

        case '-':
           return left - term();
           
        default:
           return left;   
    }
}

int main() {

    std::cout << expression() << '\n';
}