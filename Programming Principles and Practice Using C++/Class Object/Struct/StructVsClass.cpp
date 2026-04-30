#include <iostream>
#include <string>

// ----------- STRUCT ------------------
// Simple daa model (data only) 
struct StudentData {
    int id;      // public by default
    std::string name; // public by default
    double marks;      // public
};

// ----------- CLASS -------------------
// rules + behavior + conrols
class BankAccount {
    private:
       double balance; // outside direct access not allowed

    public:
       // Constructor -> initial setup
       BankAccount(double initial) {
        if (initial >= 0)
            balance = initial;
        else 
           balance = 0;    
       }   

       // behavior: deposit money
       void deposit(double amount) {
        if (amount > 0) {   //  rule check
            balance += amount;
        } else {
            std::cout << "Invaild deposite!\n";
        }
       }

// behavior: withdraw money
void withdraw(double amount) {
    if (amount > 0 && amount <= balance) { // rule check
        balance -= amount;
    } else {
        std::cout << "Invaild withdraw!\n";
    }
}

// Controlled access (getter)
double getBalance() const {
    return balance;
  }
};

int main() {

    // --------- STRUCT USAGE ----------------
    StudentData s1;

    // direct access (no control)
    s1.id = 101;
    s1.name = "Vasanth";
    s1.marks = 85.5;

    std::cout << "Student Data:\n";
    std::cout << "ID: " << s1.id << "\n";
    std::cout << "Name: " << s1.name << "\n";
    std::cout << "Marks: " << s1.marks << "\n";

    // problem: no vaildation
    s1.marks = -100; // logically wrong, but allowed

    std::cout << "After wrong update: " << s1.marks << "\n";

    // ------------- CLASS USAGE ---------------
    //BankAccount acc;
    BankAccount acc(1000); // object creation

    std::cout << "Bank Account:\n";

    acc.deposit(500); // vaild
    acc.withdraw(300); // vaild

    std::cout << "Balance: " << acc.getBalance() << "\n";

    // direct access not allowed
    // acc.balance = -5000; // compaile error

    acc.deposit(-200);  // reject (rule applied)
    acc.withdraw(5000);  // reject (rule applied)

    std::cout << "Final Balance; " << acc.getBalance() << "\n";

    return 0;
}

/*
./a.out 
Student Data:
ID: 101
Name: Vasanth
Marks: 85.5
After wrong update: -100
Bank Account:
Balance: 1200
Invaild deposite!
Invaild withdraw!
Final Balance; 1200
*/