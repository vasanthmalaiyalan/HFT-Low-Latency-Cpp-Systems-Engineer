#include <iostream>

class BankAccount {
    private:
       int balance; // prodected

    public:
       void setBalance(int b ) {
           balance = b;
       }   

    public:
       void deposit(int amount) {
        if (amount > 0)
            balance += amount;
       }
       
       void withdraw(int amount) {
        if (amount > 0 && amount <= balance)
           balance -= amount;
       }

       int getBalance() {
        return balance;
       }
};

int main() {
    BankAccount acc;

    acc.setBalance(0);

    acc.deposit(1000);
    std::cout << "Balance: " << acc.getBalance() << "\n";

    // direct access not allowed
    // acc.balance = -5000; // compile error

    acc.withdraw(500);
    std::cout << "After withdraw: " << acc.getBalance() << "\n";

    return 0;
}