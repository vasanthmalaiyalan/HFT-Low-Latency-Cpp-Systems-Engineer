#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {1,2,3};

    for (int& x : v) {

        x = x * 10;
        std::cout << x << "\n";
    }

    for (int x : v) {
        std::cout << x << ' ';
    }
}