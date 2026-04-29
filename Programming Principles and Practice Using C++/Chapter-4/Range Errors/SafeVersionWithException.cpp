#include <iostream>
#include <vector>

int main() {

    try {

        std::vector<int> v = {1,2,3,4,5};

        for (size_t i = 0; i <= v.size(); ++i)
             std::cout << v.at(i) << '\n'; // safe access
    }

    catch (const std::out_of_range&) {

        std::cerr << "Oops ! Range error\n";
    }
}