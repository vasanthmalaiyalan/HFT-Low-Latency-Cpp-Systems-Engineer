#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {1,2,3,4,5};

    for (size_t i = 0; i <= v.size(); ++i) // bug
        std::cout << v[i] << '\n';
}