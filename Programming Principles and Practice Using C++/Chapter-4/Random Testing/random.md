Nice 🔥 — இதுக்கு நான் ஒரு **clean + modern + testing-friendly C++ random code** தர்றேன்.
👉 இது:

* proper engine ✔️
* proper distribution ✔️
* seed handling ✔️
* testing example ✔️

---

# 💻 ✅ BEST Random + Testing `.cpp` Code

```cpp
#include <iostream>
#include <random>
#include <vector>
#include <string>

// ---------- Random Engine (global) ----------
std::mt19937 rng(std::random_device{}());  
// better than default_random_engine

// ---------- Random Integer ----------
int random_int(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// ---------- Random String ----------
std::string random_string(int min_len, int max_len)
{
    int len = random_int(min_len, max_len);

    std::string s;
    for (int i = 0; i < len; ++i)
        s += char(random_int('a', 'z'));

    return s;
}

// ---------- Function to Test ----------
int square(int x)
{
    return x * x;
}

// ---------- Testing with Random Inputs ----------
void test_square()
{
    std::cout << "Testing square() with random inputs:\n";

    for (int i = 0; i < 10; ++i)
    {
        int x = random_int(-100, 100);
        int result = square(x);

        std::cout << "x = " << x 
                  << " -> square = " << result << '\n';

        // simple validation
        if (result < 0)
            std::cerr << "ERROR: square result negative!\n";
    }
}

// ---------- Generate Random Data ----------
void generate_data()
{
    std::vector<std::pair<std::string, int>> data;

    for (int i = 0; i < 5; ++i)
    {
        data.push_back({random_string(4, 10), random_int(1, 1000)});
    }

    std::cout << "\nRandom (name, value) pairs:\n";
    for (auto& p : data)
        std::cout << p.first << " -> " << p.second << '\n';
}

// ---------- MAIN ----------
int main()
{
    // Dice example 🎲
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
```

---

# 🧠 Why this is BEST 🔥

---

## ✅ 1. Uses `mt19937`

👉 better randomness than `default_random_engine`

---

## ✅ 2. Proper design

* reusable `random_int()`
* reusable `random_string()`

---

## ✅ 3. Testing included

👉 random inputs → bug detect

---

## ✅ 4. Real-world style

👉 vector + pair + modular functions

---

# 🧪 Sample Output

```text
Dice rolls:
3 1 6 2 5 4 2 6 1 3

Testing square() with random inputs:
x = -23 -> square = 529
x = 45 -> square = 2025

Random (name, value) pairs:
abcd -> 123
xyzq -> 876
```

---

# 💬 Simple Tamil Summary

👉 best random code:

* engine + distribution separate
* reusable functions
* testing integrate

---

# 🎯 One-line memory

👉

> “Good random code = reusable + testable + predictable when needed”

---

# 🚀 If you want next

👉 seed control for debugging (repeatable runs 🔥)
👉 fuzz testing real-world
👉 cryptographic random vs mt19937

Just tell 👍
