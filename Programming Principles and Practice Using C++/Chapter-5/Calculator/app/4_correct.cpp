#include <iostream>

// ------------- Token -------------------------
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
        return Token{'8', val};
    }

    return Token{ch, 0};
}

// ------------------- Primary ----------------------

double primary() {

    Token t = get_token();

    if (t.kind == '8')
       return t.value;

    std::cerr << "Error: number expected\n";
    return 0;    
}

// ----------------- Term ---------------------------
double term() {

    double left = primary(); // first number
    Token t = get_token(); // next token

    while (true) {
        switch (t.kind) {

            case '*':
               left *= primary();
               t = get_token();
               break;

            case '/': {
                
                double d = primary();

                if (d == 0) {
                    std::cerr << "Error: divided by zero\n";
                    return 0;
                }

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

// ---------------- Main -------------------------
int main() {

    std::cout << "Enter: ";
    std::cout << term() << '\n';
}