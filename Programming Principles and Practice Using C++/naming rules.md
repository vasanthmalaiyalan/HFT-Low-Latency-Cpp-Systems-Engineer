Excellent 🔥 — இது **naming rules (2.6 Names)**, but don’t underestimate it.
👉 Good naming = readable code
👉 Bad naming = bugs + confusion

நான் இதை **clear Tamil + rules + good/bad examples + C++ code** explain பண்ணுறேன்.

---

# 📘 2.6 Names — Core Idea

👉 Book சொல்றது:

> Variablesக்கு meaningful name வேண்டும்

---

# 🧠 1. What is a Name?

👉 Name = variable / function / objectக்கு கொடுக்குற பெயர்

---

## ✅ Valid Names

```cpp id="v1"
int x;
int number_of_elements;
double Fourier_transform;
int z2;
```

👉 Rules follow பண்ணுது ✔️

---

## ❌ Invalid Names

```cpp id="v2"
int 2x;              // ❌ start with digit
int time@to@market;  // ❌ @ not allowed
int Start menu;      // ❌ space not allowed
```

---

# ⚠️ 2. Naming Rules (VERY IMPORTANT)

👉 Name:

✔️ start with letter
✔️ contain letters, digits, `_`

❌ no special symbols
❌ no spaces

---

# ⚠️ 3. Case Sensitive

```cpp id="case1"
int x = 10;
int X = 20;
```

👉 x ≠ X

👉 இரண்டு different variables

---

# ❌ 4. Common Mistake Program

```cpp id="err1"
#include <iostream>

int Main()
{
    STRING s = "Hello";
    cOut << S << '\n';
}
```

---

## 🔴 Errors:

* `Main` ❌ → should be `main`
* `STRING` ❌ → should be `std::string`
* `cOut` ❌ → should be `std::cout`
* `S` ❌ → should be `s`

👉 case sensitive problem 🔥

---

# ⚠️ 5. Keywords cannot be used

```cpp id="kw1"
int if = 7;   // ❌ error
```

👉 `if` = keyword

---

# ⚠️ 6. Avoid Standard Names

```cpp id="bad1"
int string = 5;  // ❌ bad practice
```

👉 later `std::string` use பண்ண முடியாது

---

# ⚠️ 7. Avoid underscore at start

```cpp id="bad2"
int _data;  // ❌ avoid
```

👉 system reserved

---

# 🧠 8. Good Naming Practice

---

## ❌ Bad

```cpp id="bad3"
int x1, x2, x3;
```

👉 meaning தெரியாது

---

## ✅ Good

```cpp id="good1"
int total_marks;
int student_count;
```

👉 readable ✔️

---

# ⚠️ 9. Confusing Names

```cpp id="bad4"
int foo;
int f00;   // zero
int fl;    // l
int f1;    // one
```

👉 confusion 🔥

---

# 🧠 10. Naming Style

👉 Recommended:

```cpp id="style1"
int element_count;
int partial_sum;
```

👉 underscores use ✔️

---

## ❌ Avoid

```cpp id="style2"
int the_number_of_elements;  // too long ❌
```

---

# 💻 11. BEST PRACTICE EXAMPLE

```cpp id="final1"
#include <iostream>
#include <string>

int main()
{
    std::string student_name = "Vasanth";
    int total_marks = 450;
    int subject_count = 5;

    double average_marks = total_marks / subject_count;

    std::cout << "Name: " << student_name << '\n';
    std::cout << "Average: " << average_marks << '\n';

    return 0;
}
```

---

# 🎯 Why this is GOOD?

👉 names:

* `student_name` ✔️ clear
* `total_marks` ✔️ meaningful
* `average_marks` ✔️ readable

---

# 💬 Simple Tamil Summary

👉 Name:

* letterல start ஆகணும்
* space இருக்கக்கூடாது
* special symbol இருக்கக்கூடாது

👉 Case important:

* `x` ≠ `X`

👉 Good name:

> program புரிய easy ஆக இருக்கும்

---

# 🚀 One-line memory

👉

> “Code எழுதுறது computerக்கு இல்ல — மனிதருக்கு”

---

# 🔥 Real Developer Tip

👉 Clean naming → interview pass
👉 Bad naming → reject ❌

---

If you want next 🔥

👉 naming conventions (Google, Java, C++)
👉 real company coding style
👉 bad vs good code comparison

Just tell 👍
