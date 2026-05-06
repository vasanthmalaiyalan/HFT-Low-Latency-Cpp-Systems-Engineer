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
          : kind{k}, value{0,0}
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
        
      }     
}