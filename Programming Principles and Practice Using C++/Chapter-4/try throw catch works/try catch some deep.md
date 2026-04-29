Awesome 🔥 — now you’re stepping into **real C++ error handling: `try-catch`**
👉 இது beginner → intermediate jump point 💯

நான் இதை **clear Tamil + flow + examples + mistakes** explain பண்ணுறேன்.

---

# 📘 1. What is `try-catch`?

👉 Purpose:

```text
Error வந்தாலும் program crash ஆகாமல் handle பண்ண
```

---

# 🧠 Basic Syntax

```cpp
try {
    // risky code
}
catch (ExceptionType e) {
    // handle error
}
```

---

# ⚙️ 2. Flow எப்படி வேலை செய்கிறது?

```text
try block run
   ↓
error (throw) வந்தா
   ↓
matching catch block execute
   ↓
program continues
```

---

# 🧪 3. Simple Example

```cpp id="ex1"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        throw std::runtime_error("Something went wrong");
    }
    catch (std::runtime_error& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    return 0;
}
```

---

## Output:

```text
Caught: Something went wrong
```

---

# 🧠 4. Real Example (Practical 🔥)

```cpp id="ex2"
#include <iostream>
#include <stdexcept>

int divide(int a, int b)
{
    if (b == 0)
        throw std::runtime_error("Division by zero");

    return a / b;
}

int main()
{
    try {
        std::cout << divide(10, 0);
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}
```

---

# ⚠️ 5. Without try-catch

```cpp
divide(10, 0);
```

👉 result:

```text
program crash ❌
```

---

# 🔥 6. Multiple Catch Blocks

```cpp id="ex3"
try {
    throw 10;
}
catch (int x) {
    std::cout << "Integer error\n";
}
catch (...) {
    std::cout << "Unknown error\n";
}
```

---

👉 `catch (...)`:

```text
any type error catch பண்ணும்
```

---

# 🧠 7. Important Concepts

---

## 🟢 Throw anywhere

```cpp
if (x < 0)
    throw std::runtime_error("negative");
```

---

## 🟢 Catch must match type

```cpp
throw 10;

catch (int x)  // ✔️ correct
```

---

## ❌ Wrong:

```cpp
catch (double x)  // ❌ won't catch
```

---

# ⚠️ 8. Stack Unwinding (IMPORTANT 🔥)

👉 error throw ஆனா:

```text
function → function → function
```

👉 system:

```text
current function stop
↑
previous function
↑
main()
```

👉 until matching catch found

---

# 🧪 Example

```cpp id="ex4"
#include <iostream>
#include <stdexcept>

void func()
{
    throw std::runtime_error("error in func");
}

int main()
{
    try {
        func();
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}
```

---

# ⚠️ 9. Common Mistakes

---

## ❌ No catch

```cpp
throw std::runtime_error("error");
```

👉 crash ❌

---

## ❌ Wrong type catch

```cpp
throw 10;

catch (std::string e)  // ❌ won't catch
```

---

## ❌ Overuse

👉 every small thingக்கு use பண்ணாதே ❌

---

# 🧠 10. When to use try-catch?

---

## ✔️ Use for:

* serious errors
* invalid input
* file errors
* division by zero

---

## ❌ Avoid for:

* normal conditions
* simple checks

---

# 💬 Simple Tamil Summary

👉 `try`:

* risky code

👉 `throw`:

* error signal

👉 `catch`:

* error handle

---

# 🎯 One-line memory

👉

> “try → run, throw → error, catch → handle”

---

# 🚀 Next Level (VERY IMPORTANT 🔥)

👉 I can teach:

* custom exceptions
* best practices (industry level)
* when NOT to use exceptions

Just tell 👍
