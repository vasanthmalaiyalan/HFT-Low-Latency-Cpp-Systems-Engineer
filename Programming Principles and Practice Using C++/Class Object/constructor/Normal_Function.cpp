#include <iostream>
// Normal function example
class BankAccount {
    private:
       double balance;

    public:
       // this is not constructor (name diffrent)
       void init(double initial) {
        std::cout << "init() called manually\n";
        balance = initial;
       }   

       void showBalance() {
        std::cout << "Balance: " << balance << "\n";
       }
};
int main() {
    //object create
    BankAccount acc; // didn't initialize balance just manual way

    //manually call
    acc.init(1000);

    acc.showBalance();

    return 0;
}

/*
🧠 Output
init() called manually
Balance: 1000
💡 Key Points
❌ auto call இல்லை
✔️ manual call வேண்டும்
✔️ any name use பண்ணலாம்
✔️ return type வேண்டும் (void)
*/