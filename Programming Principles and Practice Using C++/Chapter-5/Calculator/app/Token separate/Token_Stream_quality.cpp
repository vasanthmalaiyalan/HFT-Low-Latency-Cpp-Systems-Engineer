#include <iostream>
#include <stdexcept>

// ==================================================
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

// =================================================
// Token_stream
// =================================================

class Token_stream {

    public:
       
       Token_stream() : full{false}, buffer{'0'} {} /// use this garbage clean

       Token get();
       void putback(Token t);

    private:
       
       bool full; // buffer occupied
       Token buffer; // one-token memory
};

// =================================================
// putback()
// =================================================

void Token_stream::putback(Token t) {

    if (full)
       error("putback() in to a full buffer");

    buffer = t;
    full = true;
    
    std::cout << "[putback] token stored -> " << buffer.kind << '\n';
}

// ================================================
// get()
// =================================================

Token Token_stream::get() {

    // if buffer has token -> retrun it
    if (full) {

        full = false;

        std::cout << "[get] returning BUFFER token -> "
                  << buffer.kind << '\n';

         return buffer;         
    }

    // otherwise read fresh token
    char ch;
    std::cin >> ch;

    std::cout << "[get] reading New Token -> "
              << ch << '\n';

     return Token{ch};         
}

// =================================================
// Main
// =================================================

int main() 
try {

    Token_stream ts;

    // ---------------------------------------
    // first read
    // ---------------------------------------

    std::cout << "Type one character: ";

    Token t1 = ts.get();

    std::cout << "Main reeived token: "
              << t1.kind << "\n\n";

    // ------------------------------------
    // put token back
    // ------------------------------------
    
    ts.putback(t1);

    std::cout << '\n';

    // ---------------------------------------
    // read again
    // ---------------------------------------

    Token t2 = ts.get();

    std::cout << "Main receive again: " 
              << t2.kind << '\n';
}
catch (std::exception& e) {

     std::cerr << "Error: "
               << e.what() << '\n';
}