#include <iostream>
#include <vector>

// --------------------------------
// Token class (same concept)
// --------------------------------
class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0.0} {}
       Token(char k, double v) : kind{k}, value{v} {}
};

// ------------------------------------
// Print using range-based for
// ------------------------------------

void print_token(const std::vector<Token>& tok) {

    std::cout << "Token: ";

    // range-based for loop
    for (const Token& t : tok) {

        // t = current element (reference)
        if (t.kind == '8')
           std::cout << t.value << " ";
        else 
           std::cout << t.kind << " ";   
    }

    std::cout << '\n';
}

// ------------------------------------------
// Modify using non-const reference
// ------------------------------------------
void zero_numbers(std::vector<Token>& tok) {
    for (Token& t : tok) {
        if (t.kind == '8')
            t.value = 0; // modifies original vector
    }
}

// -----------------------------------
// Main
// -----------------------------------

int main() {

    std::vector<Token> tok;

    // manually push token
    tok.push_back(Token{'8', 10});
    tok.push_back(Token{'+'});
    tok.push_back(Token{'8', 20});
    tok.push_back(Token{'*'});
    tok.push_back(Token{'8', 3});

    std::cout << "Original:\n";
    print_token(tok);

    std::cout << "\nAfter modification:\n";
    zero_numbers(tok);
    print_token(tok);

    return 0;
}