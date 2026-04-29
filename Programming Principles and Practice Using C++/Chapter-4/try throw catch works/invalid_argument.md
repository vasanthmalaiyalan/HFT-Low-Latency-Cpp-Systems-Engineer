சூப்பர் கேள்வி 🔥 — இது **C++ exception hierarchy** புரிஞ்சா தான் clear ஆகும்.

---

# 🧠 Core Idea

👉 `std::invalid_argument` என்பது
👉 `std::exception`-இன் **derived class** (child class)

---

# 📦 Hierarchy (simple)

```text
std::exception   (base class)
        ↑
std::logic_error
        ↑
std::invalid_argument
```

---

# 💡 Meaning

👉 நீ throw பண்ணுறது:

```cpp
throw std::invalid_argument("error message");
```

👉 catch பண்ணுறது:

```cpp
catch (const std::exception& e)
```

👉 இது **parent type catch** ✔️

---

# 🔍 Why it works?

👉 C++ rule:

```text
Derived object → Base reference-க்கு assign ஆகலாம்
```

👉 அதனால்:

```text
invalid_argument → exception ✔️
```

---

# 💻 Example

```cpp id="ex1"
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        throw std::invalid_argument("Invalid input!");
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught: " << e.what() << '\n';
    }
}
```

---

## 🧾 Output:

```text
Caught: Invalid input!
```

---

# ⚠️ Important Detail

👉 `e.what()` works because:

```text
what() is virtual function in std::exception
```

👉 runtime-ல correct message வரும் ✔️

---

# 🔥 Catch Types Comparison

---

## 🟢 Specific catch

```cpp id="c1"
catch (const std::invalid_argument& e)
```

👉 only that type

---

## 🟡 Generic catch

```cpp id="c2"
catch (const std::exception& e)
```

👉 ALL standard exceptions ✔️

---

# 🧠 Best Practice

👉 Use this:

```cpp
catch (const std::exception& e)
```

👉 because:

* covers all exceptions
* clean code
* scalable

---

# ⚠️ Order matters (IMPORTANT)

```cpp id="order1"
catch (const std::invalid_argument& e)
catch (const std::exception& e)
```

👉 correct ✔️

---

```cpp id="order2"
catch (const std::exception& e)
catch (const std::invalid_argument& e)
```

👉 wrong ❌ (child unreachable)

---

# 💬 Simple Tamil Summary

👉 `invalid_argument`:

* `exception`-இன் child

👉 so:

```text
child → parent catch possible ✔️
```

---

# 🎯 One-line memory

👉

> “Derived exception → base catch works”

---

# 🚀 If you want next

👉 full exception hierarchy
👉 custom exception எப்படி create பண்ண
👉 try-catch best practices (interview level)

Just tell 👍
