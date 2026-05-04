#include <iostream>

//dummy Token
class Token {
    public:
    char kind;
};

Token get_token() {
    Token t;
    std::cin >> t.kind;
    return t;
}

double term() {
    double val;
    std::cin >> val; // assume number
    return val;
}

// Second try
// Fixed expression
double expression() {

    double left = term();

    while(true) {
        Token t = get_token();

        if (t.kind == '+') {
            left += term();
        }
        else if (t.kind == '-') {
            left -= term();
        }
        else if (t.kind == ';') { // end
            return left;
        }
        else {
            return left;
        }
    }
}

int main() {

    std::cout << "Enter: ";
    std::cout << expression() << "\n";
}