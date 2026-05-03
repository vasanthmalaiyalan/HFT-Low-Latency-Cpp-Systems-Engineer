//using_token.cpp
// Demonstrates 5.3.4: Using tokens (first attempt - not final solution)

#include <iostream>
#include <vector>

// ---------------------------------------
// Token class
// ---------------------------------------
class Token {
    public:
       char kind; // '8' for number, '+', '-', '*', '/'
       double value; // used only if kind == '8'

       Token(char k) : kind{k}, value{0.0} {}
       Token(char k, double v) : kind{k}, value{v} {}
};

// ----------------------------
// get_token(): read from input
// ----------------------------

Token get_token() {

    char ch;
    std::cin >> ch;

    switch (ch) {
        case '+': case '-': case '*': case '/': case '(': case ')':
             return Token{ch}; // operator token

         case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
         {
            std::cin.putback(ch);  // put digit back
            double val;
            std::cin >> val; // read full number
            return Token{'8', val}; // number token
         }    

         default:
            std::cout << "Bad token!\n";
            return Token{'?'};
    }
}

// -------------------------------
// Print token (debug)
// -------------------------------
void print_token(const std::vector<Token>& tok)
{
    std::cout << "Tokens: ";
    for (const Token& t : tok) {
        if (t.kind == '8')
           std::cout << t.value << " ";
        else 
           std::cout << t.kind << " ";   
    }
    std::cout << '\n';
}

// ---------------------------------
// Native multiply attempt
// ---------------------------------
void try_multiply(const std::vector<Token>& tok) {

    for (size_t i = 0; i < tok.size(); ++i) {
        if (tok[i].kind == '*') {
            double d = tok[i - 1].value * tok[i + 1].value;
            std::cout << "Found multiply: "
                      << tok[i - 1].value << " "
                      << tok[i + 1].value << " = "
                      << d << "\n";
        }
    }
}

// -----------------------------------
// Main
// -----------------------------------
int main() {

    std::cout << "Enter expression (e.g., 1+2*3):\n";

    std::vector<Token> tok;

    while (std::cin) {
        Token t = get_token();
        tok.push_back(t);

        // stop when newline
        if (std::cin.peek() == '\n')
         break;
    }

    print_token(tok);

    // try naive evaluation
    try_multiply(tok);

    std::cout << "\n This approach is incomplete!\n";
    std::cout << "We cannot handle order of operation properly.\n";

    return 0;
}

/*
 ./a.out 
Enter expression (e.g., 1+2*3):
1+2*3
Tokens: 1 + 2 * 3 
Found multiply: 2 3 = 6

 This approach is incomplete!
We cannot handle order of operation properly.
*/