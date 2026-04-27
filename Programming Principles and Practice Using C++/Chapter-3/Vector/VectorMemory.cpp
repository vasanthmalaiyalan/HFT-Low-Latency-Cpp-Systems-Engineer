#include <iostream>
#include <vector>

int main() {

    std::vector<int> v;

    std::cout << "Vector object size: " << sizeof(v) << " bytes\n";

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "element count: " << v.size() << '\n';

    return 0;
}