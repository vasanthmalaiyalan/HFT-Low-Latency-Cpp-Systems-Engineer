#include <iostream>

// =================================================
// Token
// =================================================

class Token {
    public:
       char kind;
       double value;

       Token(char k) : kind{k}, value{0} {}

       Token(char k, double v) : kind{k}, value{v} {}
};

// ==================================================
// Token_stream
// ==================================================

class Token_stream {
    public:
       Token get();
       void putback(Token t);
};

// global token stream
Token_stream ts;

// ================================================
// Forward Declaration
// ================================================

double expression();

// ================================================
// primary()
// ================================================

double primary() {

    std::cout 
         << "[primary called]\n";

    // primary needs expression()
    return expression();     
}

// ==================================================
// term()
// ==================================================

double term() {

    std::cout 
        << "[term called]\n";

     return primary();   
}

// ==================================================
// expression()
// ==================================================

double expression() {

    std::cout 
         << "[expression called]\n";

      return 42;   
}

// ==============================================
// main()
// ==============================================

int main() {

    std::cout 
         << term() << '\n';
}