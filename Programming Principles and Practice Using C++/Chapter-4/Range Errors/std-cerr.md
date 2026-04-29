Nice 🔥 — இது C++ல ஒரு முக்கிய output concept.

---

# 🧠 `std::cerr` என்ன?

👉 `cerr` = **Character Error output stream**

👉 Tamilல:

```text
Error messages காட்ட use பண்ணுற output
```

---

# 📦 1. Types of Output

| Stream      | Use           |
| ----------- | ------------- |
| `std::cout` | normal output |
| `std::cerr` | error output  |
| `std::clog` | logging       |

---

# 💻 Example

```cpp
#include <iostream>

int main()
{
    std::cout << "Normal output\n";
    std::cerr << "Error message\n";
}
```

---

## 🧪 Output (terminal)

```text
Normal output
Error message
```

👉 same போல தெரியும்
👉 but internally different 🔥

---

# ⚠️ Difference (IMPORTANT)

---

## 🟢 `std::cout`

* buffered
* delay ஆகலாம்

---

## 🔴 `std::cerr`

* **unbuffered**
* immediately print ✔️

---

# 🧠 Why `cerr` use பண்ணுறோம்?

👉 error வந்தா:

```text
immediate display வேண்டும்
```

👉 debugging easy ✔️

---

# 💻 Real Example

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3};

    try {
        std::cout << v.at(5);
    }
    catch (const std::out_of_range&)
    {
        std::cerr << "Oops! Range error\n";
    }
}
```

---

# 🎯 Real-world usage

👉 `cout`:

```text
user output
```

👉 `cerr`:

```text
error / debug info
```

---

# 💬 Simple Tamil Summary

👉 `std::cerr`:

* error print பண்ண
* fast (no buffering)
* debuggingக்கு useful

---

# 🔥 One-line memory

👉

> `cout = normal output`
> `cerr = error output`

---

# 🚀 If you want next

👉 `cout vs cerr vs clog` deep comparison
👉 buffering எப்படி வேலை செய்கிறது
👉 terminal redirect (advanced 🔥)

Just tell 👍
