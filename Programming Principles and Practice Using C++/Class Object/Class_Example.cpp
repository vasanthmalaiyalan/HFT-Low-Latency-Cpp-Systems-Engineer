#include <iostream>

// class = rule + behavior + control
class BankAccount {
    private:
       double balance; // direct access not allowed

    public:
        // constructor (initial setup)   
        BankAccount(double initial) {
            if (initial >= 0) 
                balance = initial; 
            else 
               balance = 0;     
          }

          // behavior + rule
          void deposit(double amount) {
            if (amount > 0)  // rule
               balance += amount;
            else 
              std::cout << "Invalid deposit\n";   
          }

          // behavior + rule
          void withdraw(double amount) {
            if (amount > 0 && amount <= balance) // rule
                balance -= amount;
            else 
               std::cout << "Invalid withdraw\n";    
          }

          // controlled access
          double getBalanced() {
            return balance;
          }
};

int main() {
    BankAccount acc(1000); // object create because constructoe call automatic create object
    acc.deposit(500); // vaild
    acc.withdraw(300); // vaild

    std::cout <<  "Balance: " << acc.getBalanced() << "\n";

    // not allowed
    //acc.balance = -50000;

    acc.deposit(-200); // reject
    acc.withdraw(50000); // reject

    std::cout << "Final Balance: " << acc.getBalanced() << "\n";

    return 0;

}

/*
🧠 Key idea
class → rules + behavior + control
✔️ validation
✔️ safety
✔️ encapsulation
*/