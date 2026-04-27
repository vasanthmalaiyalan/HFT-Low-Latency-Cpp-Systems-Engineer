#include <iostream>

// Function declaration
int square(int);

int main() {
    int result = square(5); // call before defination
    std::cout << "Square = " << result << '\n';

    return 0;
}

// Function definition
int square(int x) {
    return x * x;
}

/*
Great 🔥 — இது **Function Declarations (3.5.2)**
👉 இது beginnersக்கு confusing… ஆனா once புரிஞ்சா **real project level concept** 💯

நான் இதை **simple Tamil + clear difference + best code** explain பண்ணுறேன்.

---

# 📘 Function Declaration — Core Idea

👉

> function எப்படி call பண்ணுவது மட்டும் சொல்லும் (body இல்ல)

---

# 🧠 1. Declaration vs Definition

---

## 🟢 Declaration

```cpp
int square(int);
```

👉 meaning:

```text
square function இருக்கு  
int input வாங்கும்  
int return பண்ணும்  
```

👉 body இல்ல ❗

---

## 🟢 Definition

```cpp
int square(int x)
{
    return x * x;
}
```

👉 full logic ✔️

---

# 🔥 2. Why Declaration?

👉 function body பார்க்க வேண்டாம்

👉 just use பண்ணலாம் ✔️

---

# 💡 Real example

👉 `sqrt()` use பண்ணுறோம்:

```cpp
#include <cmath>

double x = sqrt(25);
```

👉 நம்ம function body தெரியாது
👉 declaration மட்டும் use ஆகுது ✔️

---

# 💻 BEST Example (.cpp — Declaration + Definition)

```cpp
#include <iostream>

// 🔹 Function declaration
int square(int);

int main()
{
    int result = square(5);   // call before definition

    std::cout << "Square = " << result << '\n';

    return 0;
}

// 🔹 Function definition
int square(int x)
{
    return x * x;
}
```

---

# 🧠 Important Concept

👉 declaration இருந்தால்தான்:

```cpp
square(5);
```

👉 compiler accept பண்ணும் ✔️

---

# ❌ Without declaration (error)

```cpp
int main()
{
    int result = square(5);   // ❌ error (unknown)
}
```

---

# 🧠 3. Why this needed?

👉 real programs:

* 1000+ functions
* எல்லாத்தையும் மேல எழுத முடியாது

👉 solution:

✔️ declaration மேல
✔️ definition கீழ

---

# 🧠 4. Structure

```text
Declaration → “how to use”
Definition → “how it works”
```

---

# 🔥 5. Key Difference Table

| Feature   | Declaration | Definition |
| --------- | ----------- | ---------- |
| body      | ❌           | ✔️         |
| semicolon | ✔️          | ❌          |
| purpose   | usage info  | logic      |

---

# 💬 Simple Tamil Summary

👉 declaration:

* function info மட்டும்

👉 definition:

* actual code

---

# 🚀 One-line memory

👉

> “Declaration = promise, Definition = work”

---

# 🔥 Final Advice

👉 beginner mistake:

❌ declaration skip

👉 correct:

✔️ function use பண்ணும் முன்னாடி declare பண்ணு

---

If you want 🔥

👉 next: **header files (#include) எப்படி work ஆகுது**
👉 or multi-file C++ project setup

Just tell 👍

*/