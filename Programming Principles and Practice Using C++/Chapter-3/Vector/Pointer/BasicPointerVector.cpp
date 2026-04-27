#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {10, 20 , 30};

    std::cout << "Sizeof(v): " << sizeof(v) << '\n';
    std::cout << "length of size(): " << v.size() << '\n';

    std::cout << "address of data: " << v.data() << '\n';
}