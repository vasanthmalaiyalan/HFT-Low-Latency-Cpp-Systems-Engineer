#include <iostream>

int main() {

    char input;

    std::cout << "Enter didgit (0-9): ";
    std::cin >> input;

    switch (input) {

        case '0': case '2': case '4': case '6': case '8':
            std::cout << "Even Number\n";
            break;

        case '1': case '3': case '5': case '7': case '9':
           std::cout  << "Odd Number\n";
           break;
           
        default:
            std::cout << "Not a digit\n";
            break;   
    }

    return 0;
}