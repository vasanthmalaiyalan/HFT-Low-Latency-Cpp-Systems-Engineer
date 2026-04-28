#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    std::vector<std::string> words;

    for (std::string temp; std::cin >> temp; ) {
          if (temp == "quit") break; 
          words.push_back(temp);
    }
    std::cout << "Number of words: " << words.size() << '\n';
    
    std::sort(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i-1] != words[i]) // cancel dublicate
           std::cout << words[i] << '\n';
    }

    return 0;
}