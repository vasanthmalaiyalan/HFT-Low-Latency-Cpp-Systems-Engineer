#include <iostream>
#include <vector>

int main() {

    // Array (fixed)
    int arr[3] = {1, 2, 3};
    std::cout << "Array: ";
    for (int i = 0; i < 3; ++i) 
         std::cout << arr[i] << ' ';
         
    // Vector (dynamic)
    std::vector<int> v = {1, 2, 3};
    v.push_back(4);
    std::cout << "\nVector add: " << v[3] << '\n';
    
    std::cout << "\nVector:  ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }

    return 0;
}