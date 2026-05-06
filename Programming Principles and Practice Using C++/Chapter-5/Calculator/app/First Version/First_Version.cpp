// calculator_first_version_fixed.cpp
// Trying the first version
// Recursive descent parser with Token_stream

#include <iostream>
#include <stdexcept>
#include <cctype>

// =============================================
// Token 
// =============================================

class Token {
    public:
      char kind; // what kind of token
      double value; // for numbers
      
      Token (char k)
          : kind{k}, value{0}
      {

      } 
      
      Token (char k, double v)
         : kind{k}, value{v}
       {

       }  
};

// ==============================================
// Error helper
// ==============================================

void error (const std::string& msg) {

    throw std::runtime_error(msg);
}

// =================================================
// Token_stream
// ==================================================

class Token_stream {
    public:
      Token_stream()
           : full{false}, buffer{'0'}
      {
        // because by defualt value is empty and clean you doesn't use this constructor garbage is loading
      }    
      
      Token get();  // read token
      void putback(Token t); // put token back

    private:
      bool full; // is buffer full?
      Token buffer; // stores one token  
};

// -------------------------------------------------
// putback()
// -------------------------------------------------

void Token_stream::putback(Token t) {

    if (full)
       error("putback() into a full buffer");

    buffer = t;
    full = true;   
}

// ------------------------------------------------
// get()
// -------------------------------------------------

Token Token_stream::get() {

    // use buffered token first
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;

    switch (ch) {

        // operators
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
           return Token{ch};

       // number
       case '.':
       case '0': case '1': case '2':
       case '3': case '4': case '5':
       case '6': case '7': case '8':
       case '9':
       {

        std::cin.putback(ch);

        double val;
        std::cin >> val;

        return Token{'8', val}; // this return is use compailer use RVO(return value optimization) or temp create and obj copy  
       }
       
       default:
          error("Bad token");
    }

    return Token{'0'};
}

// global token stream
Token_stream ts;

// forward declarations
double expression();

// ================================================
// Primary
// handles:
//   Number
//    "(" Expression ")"
// ================================================

double primary() {

    Token t = ts.get();

    switch (t.kind) {

        case '(': {

            double  d = expression();

            t = ts.get();

            if (t.kind != ')')
               error("')' expected");

            return d;   
        }

        case '8':
           return t.value;

        default:
           error("Primary expected");   
    }

    return 0;
}

// =============================================
// term()
// handles:
//   * and /
// =============================================

double term() {

    double left = primary();

    Token t = ts.get();

    while (true) {

        switch (t.kind) {

            case '*':
              left *= primary();
              t = ts.get();
              break;
              
            case '/':
               {
                double d = primary();

                if (d == 0) 
                   error("divide by zero");

                left /= d;
                t = ts.get();
                break;

               }
               
               default:
                  ts.putback(t); // Important Fix
                  return left;
        }
    }
}

// ================================================
// expression()
// handles:
//   + and -
// ================================================

double expression() {

    double left = term();

    Token t = ts.get();

    while (true) {

        switch (t.kind) {

            case '+':
              left += term();
              t = ts.get();
              break;

            case '-':
               left -= term();
               t = ts.get();
               break;
               
            default:
               ts.putback(t); // Important Fix
               return left;   
        }
    }
}

// ==============================================
// main()
// ===========================================

int main() {

    try {
        std::cout << "Simple Calculator\n";
        std::cout << "Enter expression:\n";

        while (std::cin) { // only check this one in live or not that status

            double result = expression();

            std::cout << "= " << result << '\n';
        }
    }

    catch (std::exception& e) {

        std::cerr << "Error: " << e.what() << '\n';
        return 1; 
    }
    catch (...) {

        std::cerr << "Unknown exception\n";
        return 2;
    }
}