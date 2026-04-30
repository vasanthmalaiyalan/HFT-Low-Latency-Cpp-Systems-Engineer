#include <iostream>

struct Bank {
    private:
        int balance;

    public:
        void deposit(int amt) {
            if (amt > 0)
               balance += amt;
        }    

        int getBalance() {
            return balance;
        }
};

int main() {
    Bank b;

    b.deposit(1000);
    std::cout << b.getBalance();
}

/*
🧠 Tamil Summary

👉 structல:

✔️ function எழுதலாம்
✔️ private/public use பண்ணலாம்

👉 class மாதிரி தான் almost

🎯 Final Truth 🔥
C++ struct = class (almost same)
difference = default access மட்டும்
🚀 Real-world tip

👉 Use:

struct → simple data models
class → complex logic / big systems
*/