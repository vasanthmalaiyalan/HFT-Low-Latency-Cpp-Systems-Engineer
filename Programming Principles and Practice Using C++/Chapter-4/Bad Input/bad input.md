Great 🔥 — this section **4.6.3 Bad input** is super practical.
👉 Real programs mostly fail because of **bad input**, not logic.

நான் இதை **clear Tamil + examples + best code** explain பண்ணுறேன் 👇

---

# 📘 4.6.3 Bad Input — Core Idea

👉 Book சொல்றது:

> Input fail ஆனதா இல்லையா check பண்ணணும் 

---

# 🧠 1. Basic Input Problem

```cpp
double d;
std::cin >> d;
```

👉 user input:

```text
hello
```

👉 result:

```text
cin fails ❌
```

---

# 🔍 2. How to detect failure?

👉 simply:

```cpp
if (std::cin)
```

---

## 🟢 Meaning

```text
cin → success ✔️
!cin → failure ❌
```

---

# 💻 3. Example

```cpp
#include <iostream>

int main()
{
    double d = 0;

    std::cin >> d;

    if (std::cin)
        std::cout << "Value = " << d << '\n';
    else
        std::cout << "Invalid input!\n";
}
```

---

# ⚠️ 4. Better Approach (with error)

👉 Book suggests:

```cpp
if (!cin)
    error("message");
```

---

# 💻 5. error() function

```cpp
#include <stdexcept>

void error(std::string s)
{
    throw std::runtime_error{s};
}
```

👉 இது:

```text
error வந்தா → exception throw
```

---

# 💻 6. Full BEST Program

```cpp
#include <iostream>
#include <stdexcept>

void error(std::string s)
{
    throw std::runtime_error{s};
}

double read_number()
{
    double d = 0;

    std::cin >> d;

    if (!std::cin)
        error("Couldn't read a double");

    return d;
}

int main()
{
    try
    {
        std::cout << "Enter a number: ";
        double x = read_number();

        std::cout << "You entered: " << x << '\n';
        return 0;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }
}
```

---

# 🧪 Example Run

---

## ✔️ Input:

```text
5.5
```

👉 Output:

```text
You entered: 5.5
```

---

## ❌ Input:

```text
hello
```

👉 Output:

```text
runtime error: Couldn't read a double
```

---

# 🧠 7. Important Concepts

---

## 🔹 `!cin`

👉 previous input failed

---

## 🔹 `e.what()`

👉 error message return

---

## 🔹 `runtime_error`

👉 message store பண்ணும் exception

---

# 🔥 8. Catch Multiple Errors

```cpp
catch (std::exception& e)
```

👉 handles:

* runtime_error ✔️
* out_of_range ✔️

---

## Catch ALL

```cpp
catch (...)
```

👉 unknown errors

---

# ⚠️ 9. Return values from main()

```text
0 → success ✔️
1 → failure ❌
2 → unknown error ❌
```

---

# 🧠 10. Two-message error

```cpp
void error(std::string s1, std::string s2)
{
    throw std::runtime_error{s1 + s2};
}
```

---

# 💬 Simple Tamil Summary

👉 bad input:

* cin fail ஆகும்
* `!cin` check பண்ணு

👉 best approach:

* error() throw
* main catch

---

# 🎯 One-line memory

👉

> “Input fail → !cin → throw error → catch in main”

---

# 🚀 If you want next

👉 `cin.clear()` & `cin.ignore()` (input recovery 🔥)
👉 multiple input validation system
👉 real-world form validation

Just tell 👍
