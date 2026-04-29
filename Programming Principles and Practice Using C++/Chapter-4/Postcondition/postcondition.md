Excellent 🔥 — இப்ப நீ வந்திருக்கிற இடம் **Design by Contract (Pro level thinking)**.
👉 **Precondition + Postcondition = Strong, reliable code**

நாம் இதை **super clear Tamil + example + best code** explain பண்ணலாம் 👇

---

# 📘 4.7.3.3 Postconditions — Core Idea

👉 Book சொல்றது:

```text
Precondition → input correct இருக்கணும்  
Postcondition → output correct இருக்கணும் ❗
```

---

# 🧠 1. What is Postcondition?

👉 Definition:

```text
Function முடிந்த பிறகு true ஆக இருக்க வேண்டிய condition
```

👉 Tamil:

```text
“function return value correctா இருக்கணும்”
```

---

# 💻 2. Example (area function)

---

## 🟢 Precondition check

```cpp
expect(length > 0 && width > 0, "bad input");
```

👉 input valid ✔️

---

## 🟢 Postcondition check

```cpp
expect(a > 0, "bad result");
```

👉 output valid ✔️

---

# 💻 3. Full Code (Best Practice)

```cpp
#include <iostream>
#include <stdexcept>

void error(const std::string& msg)
{
    throw std::runtime_error(msg);
}

void expect(bool cond, const std::string& msg)
{
    if (!cond)
        error(msg);
}

int area(int length, int width)
// Precondition: length > 0 && width > 0
// Postcondition: result > 0
{
    expect(length > 0 && width > 0, "bad arguments");

    int a = length * width;

    expect(a > 0, "bad result");   // postcondition

    return a;
}

int main()
{
    try
    {
        std::cout << area(5, 3) << '\n';   // ✔️
        std::cout << area(1000000, 1000000) << '\n'; // ⚠️ overflow case
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
```

---

# ⚠️ 4. Important Insight 🔥

👉 Book சொல்றது:

```text
We can’t always check FULL correctness
```

👉 but:

```text
partial check போதும் ✔️
```

---

## Example

👉 full check:

```text
area correct formula?
```

👉 hard ❗

---

👉 simple check:

```text
area > 0 ✔️
```

👉 easy ✔️

---

# 💥 5. Try This (Book Question Answer)

👉 question:

```text
Precondition true  
Postcondition false possibleஆ?
```

---

## Answer:

👉 YES ❗ (overflow case)

```cpp
area(1000000, 1000000);
```

👉 calculation:

```text
1000000 * 1000000 = overflow ❗
```

👉 result:

```text
negative / garbage ❌
```

👉 so:

```text
precondition ✔️  
postcondition ❌
```

---

# 🧠 6. Why Postcondition Important?

---

## ✅ 1. Detect hidden bugs

👉 logic wrong இருந்தாலும் detect ✔️

---

## ✅ 2. Validate output

👉 trust increase ✔️

---

## ✅ 3. Safety-critical systems

👉 medical / banking code 🔥

---

# 🧠 7. Pre vs Post

| Type          | Check            |
| ------------- | ---------------- |
| Precondition  | before execution |
| Postcondition | after execution  |

---

# 🧠 8. Real-world Thinking

👉 Function:

```text
Input correct → Output correct guarantee ✔️
```

👉 This is:

```text
“contract”
```

---

# 💬 Simple Tamil Summary

👉 Precondition:

* input சரியா?

👉 Postcondition:

* output சரியா?

👉 இரண்டும் சேர்ந்து:

```text
safe + reliable function ✔️
```

---

# 🎯 One-line memory

👉

> “Precondition checks input
> Postcondition checks output”

---

# 🚀 If you want next

👉 Invariants (next powerful concept 🔥)
👉 Design by contract full system
👉 real-world bug detection examples

Just tell 👍
