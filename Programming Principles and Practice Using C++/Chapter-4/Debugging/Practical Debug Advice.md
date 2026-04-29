Great 🔥 — நீ share பண்ணது **4.7.2.1 Practical Debug Advice**
👉 இது *real developer habits* build பண்ணும் GOLD section.

நான் இதை **clear Tamil + practical rules + example code** explain பண்ணுறேன் 👇

---

# 📘 4.7.2.1 Practical Debug Advice — Core Idea

👉 Book சொல்றது:

```text
Debugging start → BEFORE coding ❗
```



👉 meaning:

👉 code எழுதின பிறகு மட்டும் debug பண்ணக்கூடாது
👉 design timeலேயே prepare ஆகணும்

---

# 🧠 1. Before Writing Code

👉 decide:

```text
Error வந்தா எப்படி handle பண்ண போற?
```

👉 default rule:

```cpp
error() → throw → main() catch
```

---

# 🧠 2. Code Readable ஆக இருக்கணும் (VERY IMPORTANT 🔥)

---

## ✅ Good comments

👉 not this ❌:

```cpp
int x = a + b; // add a and b
```

👉 but this ✔️:

```cpp
// Calculate total marks from 2 subjects
int total_marks = a + b;
```

---

## Comment should explain:

* program purpose
* assumptions
* tricky logic
* missing parts

---

# 🧠 3. Meaningful Names

---

## ❌ Bad

```cpp
int x1, x2;
```

---

## ✅ Good

```cpp
int width, height;
```

---

# 🧠 4. Small Functions

👉 Book சொல்றது:

```text
functions shortா இருக்கணும்
```

---

## ❌ Bad

```cpp
int big_function() { /* 200 lines */ }
```

---

## ✅ Good

```cpp
int area(int w, int h) { return w*h; }
```

---

# 🧠 5. Avoid Complex Code

---

## ❌ Bad

```cpp
if (a && b || c && d && e)
```

---

## ✅ Good

```cpp
bool cond1 = a && b;
bool cond2 = c && d && e;

if (cond1 || cond2)
```

---

# 🧠 6. Use Library Code

👉 Book:

```text
library code = tested ✔️
```

👉 Example:

```cpp
std::vector<int> v;   // better than raw array
```

---

# 🧠 7. Compiler is your friend

👉 Rule:

```text
compiler always right (mostly 😄)
```

👉 error வந்தா:

* argue பண்ணாதே
* fix பண்ணு

---

# 🧠 8. Real Debug Technique 🔥

---

## Step-by-step tracing

👉 Book:

```text
“Play computer”
```

👉 Example:

```cpp
int x = 5;
int y = x + 2;
```

👉 track:

```text
x = 5  
y = 7
```

---

# ⚠️ 9. Common Mistake Example

```cpp
for (int i = 0; 0 <= max; ++i)   // ❌ bug
```

👉 correct:

```cpp
for (int i = 0; i <= max; ++i)
```

👉 typo → infinite loop ❗

---

# 🔍 10. Debug with `std::cerr`

```cpp
std::cerr << "x = " << x << '\n';
```

👉 use for debugging

---

## Example

```cpp
int my_fct(int a, double d)
{
    std::cerr << "Called with: " << a << ", " << d << '\n';

    int res = a * d;

    std::cerr << "Result = " << res << '\n';

    return res;
}
```

---

# 🧠 11. Use Invariants (VERY IMPORTANT 🔥)

👉 invariant = always true condition

---

## Example

```cpp
if (!(0 < a && a < b && b < c))
    error("bad arguments");
```

👉 bug detect early ✔️

---

# ⚠️ 12. Key Debugging Truth

👉 Book சொல்றது:

```text
Bug கண்டுபிடிக்க முடியலனா → wrong placeல search பண்ணுறே
```



---

# 💻 Final Best Debug-Friendly Code

```cpp
#include <iostream>
#include <stdexcept>

void error(const std::string& msg)
{
    throw std::runtime_error(msg);
}

int area(int w, int h)
{
    if (w <= 0 || h <= 0)
        error("Invalid dimensions");

    return w * h;
}

int main()
{
    try
    {
        int w, h;

        std::cout << "Enter width & height: ";
        std::cin >> w >> h;

        std::cerr << "Debug: w=" << w << ", h=" << h << '\n';

        int result = area(w, h);

        std::cout << "Area = " << result << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
```

---

# 💬 Simple Tamil Summary

👉 Debugging best practice:

* before coding think
* small functions
* clear names
* use `cerr`
* check invariants

---

# 🎯 One-line memory

👉

> “Readable code = debuggable code”

---

# 🚀 If you want next

👉 real bug tracing example (step-by-step 🔥)
👉 how pros debug 10x faster
👉 gdb debugger practical

Just tell 👍
