#include <iostream>
#include <vector>

int main() {

    std::cout << "sizeof(size_t): " << sizeof(size_t) << '\n';

    std::vector<int> v;
    std::cout << "sizeof(vector): " << sizeof(v) << '\n';
}