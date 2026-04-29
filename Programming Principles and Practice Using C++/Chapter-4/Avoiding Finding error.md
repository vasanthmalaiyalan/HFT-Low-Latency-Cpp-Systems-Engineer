Great 🔥 — இந்த **4.7 Avoiding and finding errors** தான்
👉 *“debugging mindset + clean coding habit”* build பண்ணும் section.

நாம் இதை **practical Tamil + real techniques + code** explain பண்ணலாம் 👇

---

# 📘 4.7 — Core Idea

👉 Book சொல்றது:

```text
First program → perfect ஆகாது ❌
```

👉 So:

```text
find bugs + fix bugs = main skill ✔️
```

---

# 🧠 1. Two Main Goals

---

## 🟢 1. Avoid errors

👉 bug வராம prevent பண்ணு

---

## 🔴 2. Find errors

👉 வந்த bug கண்டுபிடிச்சு fix பண்ணு

---

# 🛠️ 2. Avoid Errors (Prevention 🔥)

---

## ✅ Technique 1: Simple code

❌ Bad:

```cpp id="a1"
int x1, x2, x3;
```

✔️ Good:

```cpp id="a2"
int total_marks;
```

---

## ✅ Technique 2: Clear logic

👉 before coding:

```text
“What can go wrong?”
```

---

## ✅ Technique 3: Small functions

```cpp id="a3"
int area(int x, int y)
{
    return x * y;
}
```

👉 easy debug ✔️

---

## ✅ Technique 4: Use safe functions

```cpp id="a4"
v.at(i);   // instead of v[i]
```

---

# 🔍 3. Finding Errors (Debugging)

---

## 🟢 Technique 1: Print debugging

```cpp id="d1"
std::cout << "x = " << x << '\n';
```

👉 values check ✔️

---

## 🟢 Technique 2: Step-by-step thinking

👉 “Play computer”

```text
input → process → output
```

---

## 🟢 Technique 3: Test cases

👉 different inputs try பண்ணு

```text
normal case
edge case
invalid case
```

---

# 🧪 Example

```cpp id="d2"
int a = 5;
int b = 0;

std::cout << a / b;  // ❌ crash
```

👉 test case reveal bug

---

# ⚠️ 4. Assertions (VERY IMPORTANT 🔥)

👉 check condition

```cpp id="d3"
#include <cassert>

int main()
{
    int x = 5;

    assert(x > 0);   // must be true

    return 0;
}
```

👉 falseனா:

```text
program stop ❌
```

---

# 🧠 5. Organizing Code (KEY IDEA)

👉 Book சொல்றது:

> bugs hide ஆகாத மாதிரி code எழுதணும்

---

## ❌ Bad

```cpp id="d4"
int x = a*b + c/d - e*f + g;
```

👉 confusing ❌

---

## ✅ Good

```cpp id="d5"
int part1 = a * b;
int part2 = c / d;

int result = part1 + part2;
```

👉 readable ✔️

---

# 🔥 6. Real Debugging Flow

```text
Write code
↓
Run
↓
Error
↓
Fix
↓
Repeat 🔁
```

---

# 🧠 7. Important Mindset

👉 Debugging:

```text
NOT failure ❌
learning process ✔️
```

---

# 💬 Simple Tamil Summary

👉 bug avoid:

* clean code
* simple logic

👉 bug find:

* test
* print
* step-by-step

---

# 🎯 One-line memory

👉

> “Easy to read code = easy to debug code”

---

# 🚀 If you want next

👉 real debugging session example
👉 gdb debugger usage
👉 how pros debug fast

Just tell 👍
