#include <iostream>
#include <string>

int main() {
    std::string first;
    std::string second;

    std::cout << "Enter two names:\n";
    std::cin >> first >> second;

    if (first == second)
        std::cout << "Same name\n";

    if (first < second)
       std::cout << " Comes before " << second << '\n';
       
    if (first > second) 
        std::cout << " Comes after " << second << '\n';
        
    return 0;    
}