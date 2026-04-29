Great 🔥 — இது **Testing (very important real-world skill)**.
👉 Debugging மட்டும் போதாது — **systematic testing** தான் பெரிய projects save பண்ணும்.

நாம் இதை **clear Tamil + practical + real code** explain பண்ணலாம் 👇

---

# 📘 4.7.4 Testing — Core Idea

👉 Book சொல்றது:

```text
“Last bug”ன்னு ஒன்றே கிடையாது ❗
```

👉 அதனால்:

```text
Testing = systematically bugs கண்டுபிடிக்க முயற்சி
```

---

# 🧠 1. Debugging vs Testing

| Debugging   | Testing     |
| ----------- | ----------- |
| bug fix     | bug find    |
| reactive    | proactive   |
| small scale | large scale |

---

# 🧠 2. What is Testing?

👉 definition:

```text
Different inputs கொடுத்து  
output correctஆ check பண்ணுதல்
```

👉 Each input set:

```text
Test case
```

---

# 🧠 3. Types of Test Cases

---

## ✅ 1. Normal case

```text
5, 3 → area = 15
```

---

## ⚠️ 2. Edge case

```text
1, 1 → smallest valid
```

---

## ❌ 3. Invalid case

```text
-1, 5 → error
```

---

# 💻 4. Simple Manual Testing Code

```cpp
#include <iostream>
#include <stdexcept>

int area(int w, int h)
{
    if (w <= 0 || h <= 0)
        throw std::runtime_error("Invalid input");

    return w * h;
}

void test(int w, int h)
{
    try
    {
        int result = area(w, h);
        std::cout << "area(" << w << "," << h << ") = " << result << '\n';
    }
    catch (...)
    {
        std::cout << "area(" << w << "," << h << ") = ERROR\n";
    }
}

int main()
{
    // Normal
    test(5, 3);

    // Edge
    test(1, 1);

    // Invalid
    test(-2, 4);

    return 0;
}
```

---

# 🧪 Output

```text
area(5,3) = 15
area(1,1) = 1
area(-2,4) = ERROR
```

---

# 🧠 5. Testing Mindset (VERY IMPORTANT 🔥)

👉 Book சொல்றது:

---

## ❌ Bad attitude

```text
“My code perfect”
```

---

## ✅ Good attitude

```text
“I will break my code 😈”
```

---

👉 best tester:

```text
calm + systematic + curious ✔️
```

---

# 🧠 6. Why Testing Important?

---

## ✅ 1. Hidden bugs detect

👉 debugging miss பண்ணும்

---

## ✅ 2. Confidence

👉 code reliable ✔️

---

## ✅ 3. Large systems

👉 millions of test cases

---

# 🧠 7. Automated Testing (Real-world 🔥)

👉 tools:

* Google Test
* Catch2
* Boost.Test

👉 use:

```text
expected output vs actual output
```

---

# 💻 8. Example (Simple unit-style test)

```cpp
#include <iostream>

void check(int result, int expected)
{
    if (result == expected)
        std::cout << "PASS\n";
    else
        std::cout << "FAIL\n";
}

int main()
{
    check(2+2, 4);  // PASS
    check(5*2, 11); // FAIL
}
```

---

# 🧠 9. Key Insight

👉 debugging:

```text
bug already தெரியும்
```

👉 testing:

```text
bug இருக்கா தெரியாது → கண்டுபிடிக்கணும்
```

---

# 💬 Simple Tamil Summary

👉 testing:

* many inputs try பண்ணு
* output verify பண்ணு

👉 mindset:

* code break பண்ண முயற்சி 😄

---

# 🎯 One-line memory

👉

> “Good testers try to break code, not prove it works”

---

# 🚀 If you want next

👉 Google Test full setup (real company style 🔥)
👉 test case design deep explanation
👉 bug bounty mindset apply to testing 😎

Just tell 👍
