#include <iostream>

// Constructor example
class BankAccount {
    private:
      double balance;

    public:
      // Constructor (class name same, no return type)
      BankAccount(double initial) {
        std::cout << "Constructor called Automatically\n";
        balance = initial;
      }  

      void showBalance() {
        std::cout << "Balance: " << balance << "\n";
      }
};

int main() {
    // object create
    BankAccount acc(1000);
    // Constructor automatically call 

    acc.showBalance();

    return 0;
}

/*
💡 Key Points
✔️ auto call (object create ஆன உடனே)
✔️ class name same
✔️ no return type
*/