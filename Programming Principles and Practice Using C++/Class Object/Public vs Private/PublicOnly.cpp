#include <iostream>

class BankAccount {
    public:
        int balance; // anyone can change
};

int main() {
    BankAccount acc;

    acc.balance = 1000;
    std::cout << "Balance: " << acc.balance << "\n";

    // dangerous change
    acc.balance = -5000;

    std::cout << "After hacking: " << acc.balance << "\n";

    return 0;
}

/*
🧠 Problem

👉 Output:

Balance: 1000
After hacking: -5000

👉 Anyone can:

break logic
set invalid values

👉 ❌ NOT SAFE
*/