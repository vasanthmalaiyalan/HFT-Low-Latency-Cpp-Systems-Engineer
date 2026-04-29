#include <iostream>
#include <random>
#include <vector>
#include <string>

// ------------ Random Engine (global) -------------
std::mt19937 rng(std::random_device{}());
// better than default_random_engine

// -------- Random Integer ---------------
int random_int(int min, int max) {

    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// -------- Random String ----------------
std::string random_string(int min_len, int max_len) {

    int len = random_int(min_len, max_len);

    std::string s;
    for (int i = 0; i < len; ++i) 
        s += char(random_int('a', 'z'));

     return s;   
}

// --------- Function to Test ---------------
int square(int x) {

    return x * x;
}

// ------------- Function to Test ------------------
int test_square(){

    std::cout << "Testing square() with random input:\n";

    for (int i = 0; i < 10; ++i) {
        int x = random_int(-100, 100);
        int result = square(x);

        std::cout << "x = " << x << " -> square = " << '\n';

        // Simple validation
        if (result < 0) 
           std::cerr << "Error: square result negative!\n";
    }
}

// ------- Generate Random Data ---------------
void generate_data() {

    std::vector<std::pair<std::string, int>> data;

    for (int i = 0; i < 5; ++i) {

        data.push_back({random_string(4, 10), random_int(1, 1000)});
    }

    std::cout << "\nRandom (name, value) pairs:\n";
    for (auto& p : data)
        std::cout << p.first << " -> " << p.second << '\n';
}

// -------- Main ------------
int main() {

    // Dice example
    std::cout << "Dice rolls:\n";
    for (int i = 0; i < 10; ++i)
        std::cout << random_int(1, 6) << ' ';

     std::cout << "\n\n";
     
     // Testing
     test_square();

     // Random data generation
     generate_data();

     return 0;
}