Excellent 🔥 — இது **Link-time errors** (4.4), compilerக்கு அடுத்த stage.
👉 இது புரிஞ்சா தான் multi-file programs புரியும்.

நாம் இதை **clear Tamil + step-by-step + real code** explain பண்ணலாம் 👇

---

# 📘 4.4 Link-time Errors — Core Idea

👉 Book சொல்றது:

> Compile ஆன பிறகு → linker combine பண்ணும்
> 👉 அப்போ வரும் errors = link-time errors

---

# 🧠 1. Flow புரிஞ்சிக்கோ

```text
.cpp files → compile → .o files → link → executable
```

👉 Linker job:

```text id="v3qfhm"
all parts combine பண்ணி final program உருவாக்கும்
```

---

# ⚠️ 2. முக்கிய விதிகள்

👉 C++ rules:

---

## 🟢 Rule 1:

👉 Function **declare செய்யலாம் many times** ✔️

---

## 🔴 Rule 2:

👉 Function **define only once** ❗

---

## 🔴 Rule 3:

👉 declaration & definition **exact same type** இருக்கணும்

---

# 🧪 3. Example (Link error)

```cpp id="l1"
#include <iostream>

int area(int length, int width);  // declaration மட்டும்

int main()
{
    int x = area(2, 3);
}
```

---

👉 problem:

```text id="l2"
area() definition இல்லை ❌
```

---

👉 linker error:

```text id="l3"
undefined reference to 'area'
```

---

# ✅ 4. Correct Version

```cpp id="l4"
#include <iostream>

int area(int length, int width);  // declaration

int main()
{
    int x = area(2, 3);
    std::cout << x;
}

// definition
int area(int x, int y)
{
    return x * y;
}
```

---

# ⚠️ 5. Type mismatch (Link problem)

---

## ❌ Wrong definition

```cpp id="l5"
double area(double x, double y)  // ❌ not matching
{
    return x * y;
}
```

👉 declaration:

```cpp id="l6"
int area(int, int);
```

👉 mismatch ❌

👉 linker:

```text id="l7"
cannot match function
```

---

# ⚠️ 6. Another mismatch

```cpp id="l8"
int area(int x, int y, char unit)  // ❌ extra argument
{
    return x * y;
}
```

👉 இது வேறு function

👉 original `area(int,int)` missing ❗

---

# 🧠 7. Important Insight

👉 Compiler vs Linker difference:

---

## 🟢 Compiler:

* syntax check ✔️
* type check ✔️

---

## 🔴 Linker:

* definitions match ✔️
* all functions exist ✔️

---

# ⚠️ 8. Common Link Errors

👉 Most common:

```text id="common1"
undefined reference
```

👉 காரணம்:

* function define பண்ணல
* file link பண்ணல
* name mismatch

---

# 🧠 9. Multi-file Example (Real World)

---

## file1.cpp

```cpp id="f1"
int area(int x, int y)
{
    return x * y;
}
```

---

## file2.cpp

```cpp id="f2"
#include <iostream>

int area(int, int);

int main()
{
    std::cout << area(2, 3);
}
```

---

## compile:

```bash id="cmd1"
g++ file1.cpp file2.cpp -o app
```

👉 linking success ✔️

---

# 💬 Simple Tamil Summary

👉 Link-time error:

* compile ok
* but linking fail

👉 காரணம்:

* function definition missing
* type mismatch
* multiple definitions

---

# 🎯 One-line memory

👉

> “Declaration tells, Definition gives”

---

# 🔥 Final Insight

👉 Beginner error:

```text id="b1"
function declare பண்ணி விட்டேன் → enough
```

❌ WRONG

👉 must also:

```text id="b2"
define + link ✔️
```

---

# 🚀 If you want next

👉 header files (.h) deep explain
👉 multi-file project structure
👉 real linker errors debugging

Just tell 👍
