#include <iostream>
#include <stdexcept>
#include <cctype>

// ===============================================
// Token
// ================================================

class Token {
    public:
        char kind;
        double value;

    Token(char k) : kind{k}, value{0} {}
    Token(char k, double v) : kind{k}, value{v} {}    
};

// ==============================================
// Error helper
// ==============================================
void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// ===============================================
// Token_stream
// ===============================================

class Token_stream {
    public:
       Token_stream() : full{false}, buffer{'0'} {}

       Token get();
       void putbak(Token t);

   private:
      bool full;
      Token buffer;    
};

// ===============================================
// putback()
// ===============================================

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

    // ============================================
    // use buffered token first
    // ============================================

    if (full) {

        full = false;

        std::cout << "[Buffer Token] -> "
                  << buffer.kind << '\n';

        return buffer;          
    }

    // -------------------------------------------
    // read new charater
    // ---------------------------------------------

    char ch = 0;

    if (!(std::cin >> ch))
        error("no input");

    std::cout << "[Read Char] -> "
              << ch << '\n';
              
   // ------------------------------------
   // classify character
   // ------------------------------------
   
   switch (ch) { // one character only read because you use char 

    // operators and symbols
    case ';':
    case 'q':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
         return Token{ch};
    
    // number
    case '.':
    case '0': case '1': case '2': case '4':
    case '5': case '6': case '7': case '8':
    case '9': 
    {

        // put character back
        std::cin.putback(ch);

        double val = 0;
        std::cin >> val;

        std::cout << "[Number Read] -> "
                  << val << '\n';

        return Token{'8', val};          
    }   

    default:
       error("Bad Token");
   }

   return Token{'0'};
}

// =============================================
// Main
// =============================================

int main() 
try {
    Token_stream ts;

    std::cout << "Enter expression:\n";

    while (true) {

        Token t = ts.get();

        if (t.kind == 'q')
           break;

        if (t.kind == '8') {

            std::cout << "Number Token: "
                      << t.value << '\n';
        }
        else {

            std::cout << "Symbol Token: "
                      << t.kind << '\n';
        }
    }
}
