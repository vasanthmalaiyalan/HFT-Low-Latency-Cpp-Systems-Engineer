#include <iostream>
#include <vector>

int main() {

    // create vector
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // access elements
    std::cout << "First: " << numbers[0] << '\n';
    
    // modify element
    numbers[1] = 99;

    // loop through vector
    std::cout << "All values:\n";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << ' '; // why use size_t because size() return unsigned
    } 

    // create empty vector with size
    std::vector<int> marks(3); // {0,0,0}

    std::cout << "\n\nDefault values:\n";
    for (size_t i = 0; i < marks.size(); ++i) {
        std::cout << marks[i] << ' ';
    }

    return 0;
}