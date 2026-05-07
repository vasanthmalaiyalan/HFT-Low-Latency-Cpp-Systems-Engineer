#include <iostream>
#include <stdexccept>

// =================================================
// Token
// ==================================================

class Token {
    public:
      char kind;
      double value;

      Token(char k) : kind{k}, value{0} {}

      Token(char k, double v) : kind{k}, value{v} {}
};

// =================================================
// Error helper
// =================================================

void error(const std::string& msg) {

    throw std::runtime_error(msg);
}

// =============================================
// Token_stream
// ==============================================

class Token_stream() {

    public:
      Token get();
};

// =============================================
// get()
// ============================================
 Token Token_stream::get() {

    char ch = 0;

    std::cin >> ch;

    std::cout << "\n[First Char Read] -> "
              << ch << '\n';

    switch (ch) {

        // ---------------------------------------
        // number detection
        //----------------------------------------

        case '.':
        case '0': case '1': case '2':
        case '3': case '5': case '6':
        case '7': case '8': case '9':
        {
            // put first char back
            std::cin.putback(ch);

            std::cout 
                 << "[putback into cin] -> "
                 << ch << '\n';

            // now let cin read Full NUmber
            double val = 0;
            
            std::cin >> val;

            std::cout
                 <<"[Full number parsed by cin] -> "
                 << val << '\n';

            return Token{'8', val};     
        }

        default:
           error("Not a Number");
    }          

    return Token{'0'};
 }

 // =============================================
 // Main
 // =============================================

 int main()
 try {
    Token_stream ts;

    std::cout 
         << "Enter Token:\n";

    Token t = ts.get();
    
    std::cout 
         << '\nFinal Token:\n';

     std::cout 
          << "kind = "
          << t.kind << '\n';
          
     std::cout 
          << "Value = "
          << t.value << "\n";     
 }
 catch (std::exception& e) {

    std::cerr
         << "Error: "
         << e.what() << '\n';
 }