#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {1, 2, 3};

    std::cout << "Object Address(Stack): " << &v << '\n';
    std::cout << "Data Address(Heap): " << v.data() << '\n';
}