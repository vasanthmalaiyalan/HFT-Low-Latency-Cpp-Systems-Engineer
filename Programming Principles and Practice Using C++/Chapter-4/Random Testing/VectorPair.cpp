#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<std::pair<std::string, int>> data;

    data.push_back({"Alice", 100});
    data.push_back({"Bob", 200});
    data.push_back({"Charlie", 300});

    for (auto& p : data) {

        std::cout << p.first << " -> " << p.second << '\n';
    }
}