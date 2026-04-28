Great 🔥 — this is where you start becoming a **real debugger**.
👉 “Compile-time errors” = compiler உன் first teacher 😄

Let’s break this **very clearly (Tamil + code + real understanding)** 👇

---

# 📘 4.3 Compile-time Errors — Core Idea

👉 Book சொல்றது:

> Compiler = first defense against errors

👉 meaning:

```text
code → compiler check → error? → stop ❌
```

👉 compile pass ஆகணும் தான் run ✔️

---

# 🧠 1. What compiler checks?

👉 2 main things:

---

## 🟢 1. Syntax errors (grammar mistake)

👉 language rules follow பண்ணல ❌

---

## 🟢 2. Type errors

👉 wrong data type use பண்ணினா ❌

---

# ⚠️ 2. Important mindset

👉 Beginner:

```text
compiler = irritating 😤
```

👉 Pro developer:

```text
compiler = best friend 💯
```

👉 why?

👉 it catches bugs early ✔️

---

# 🧪 3. Base Function Example

```cpp
int area(int length, int width);
```

👉 correct call:

```cpp
int s = area(7, 2);
```

---

# 🔴 4. Syntax Errors (Book Examples)

---

## ❌ Case 1: Missing `)`

```cpp id="e1"
int s1 = area(7, 2;
```

👉 error:

```text
missing ')'
```

---

## ❌ Case 2: Missing `;`

```cpp id="e2"
int s2 = area(7, 2)
```

👉 error:

```text
missing ';'
```

---

## ❌ Case 3: Wrong type (`Int` ❌)

```cpp id="e3"
Int s3 = area(7, 2);
```

👉 error:

```text
'Int' is not a type
```

👉 correct:

```cpp
int s3 = area(7, 2);
```

---

## ❌ Case 4: Wrong quotes

```cpp id="e4"
int s4 = area('7, 2);
```

👉 error:

```text
unterminated character
```

👉 காரணம்:

* `'` wrong usage
* string/char mismatch

---

# 🧠 5. Why error message confusing?

👉 Book சொல்றது:

> compiler doesn’t know your intention

👉 so it says:

```text
syntax error near s3
```

👉 instead of:

```text
you typed Int instead of int
```

---

# ⚠️ 6. Important Debugging Rule 🔥

👉 If error line wrongா தெரியலனா:

```text
ALWAYS check previous lines ❗
```

👉 Example:

```cpp id="dbg1"
int x = 10
int y = 20;
```

👉 error shows at line 2 ❗
👉 real problem → line 1 (missing `;`)

---

# 💻 7. Full Demo Code (with errors)

```cpp id="demo1"
#include <iostream>

int area(int length, int width)
{
    return length * width;
}

int main()
{
    int s1 = area(7, 2;     // error
    int s2 = area(7, 2)     // error
    Int s3 = area(7, 2);    // error
    int s4 = area('7, 2);   // error

    return 0;
}
```

---

# 🎯 8. Correct Version

```cpp id="demo2"
#include <iostream>

int area(int length, int width)
{
    return length * width;
}

int main()
{
    int s1 = area(7, 2);
    int s2 = area(7, 2);
    int s3 = area(7, 2);
    int s4 = area(7, 2);

    return 0;
}
```

---

# 🧠 9. Real Learning Insight

👉 Syntax errors:

* small mistakes
* easy to fix ✔️
* but error message confusing ❗

---

# 💬 Simple Tamil Summary

👉 Compile-time error:

* program run ஆகும் முன் வரும்

👉 Syntax error:

* grammar mistake

👉 Debug tip:

> error line மட்டும் இல்ல
> மேலே lines கூட check பண்ணு

---

# 🔥 One-line truth

👉

> “Compiler error = hint, not enemy”

---

# 🚀 If you want next

👉 Type errors deep explanation
👉 how to read compiler errors like pro
👉 real debugging tricks

Just tell 👍
