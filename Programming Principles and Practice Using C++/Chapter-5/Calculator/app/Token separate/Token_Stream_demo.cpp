#include <iostream>
#include <stdexcept>
#include <cctype>

// ============================================
// Token
// ============================================

class Token {
    public:
       char kind;
       double value;

       Token(char k)
          : kind{k}, value{0}
       {

       }
       
       Token(char k, double v) 
          : kind{k}, value{v}
       {

       }   
};

// ==================================================
// Error helper
// ==================================================

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// ================================================
// Token_stream
// ====================================================

class Token_stream {

    public:
       
    Token_stream()
        : full{false}, buffer{'0'}
    {
    }
    
    Token get();   // get next token
    void putback(Token t); // put token back

  private:
     
  bool full; // is buffer occupied
  Token buffer; // stores one token
};

// -----------------------------------------------
// putback()
// -----------------------------------------------

void Token_stream::putback(Token t) {

    if (full)
        error("putback into full buffer");

     buffer = t;
     full = true;   
}

// =================================================
// get()
// =================================================

Token Token_stream::get() {

    // use buffered token first
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch (ch) {

        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case ';':
        case 'q':
            return Token{ch};

        case '.':
        case '0': case '1': case '2':
        case '3': case '4': case '5':
        case '6': case '7': case '8':
        case '9':
        {
            std::cin.putback(ch);

            double val;
            std::cin >> val;

            return Token{ '8', val};
        }
        
        default:
          error("Bad token");
    }

    return Token{'0'};
}

// ================================================
// Main demo
// ===============================================

int main() {

    try {
        Token_stream ts;

        std::cout << "Enter tokens: \n";

        while (true) {

            Token t = ts.get();

            if (t.kind == 'q')
                break;

            if (t.kind == '8')
                std::cout << "Number: " << t.value << '\n';
            else 
               std::cout << "Token: " << t.kind << '\n';      
        }
    }
    catch (std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
    }
}
