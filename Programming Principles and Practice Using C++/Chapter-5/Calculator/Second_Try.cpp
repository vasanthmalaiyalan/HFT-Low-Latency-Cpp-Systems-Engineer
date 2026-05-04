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
double expression() {

    double left = term(); // start from term

    Token t = get_token(); // read operator

    switch (t.kind) {
        case '+':
           return left + expression(); // recursive

        case '-':
           return left - expression(); // recursive
           
        default:
           return left;   
    }
}

int main() {

    std::cout << "Enter: ";
    std::cout << expression() << "\n";
}