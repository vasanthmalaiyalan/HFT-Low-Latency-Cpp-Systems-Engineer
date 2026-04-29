Great question 🔥 — நீ இப்ப **C++ error handling (exceptions)**ல முதல் அடியை வைக்கிறாய்.

---

# 🧠 1. இந்த code என்ன?

```cpp
void error(const std::string& msg)
{
    throw std::runtime_error(msg);
}
```

👉 இது ஒரு **helper function**
👉 வேலை:

```text
error வந்தா → program normal flow stop → error throw
```

---

# ⚠️ 2. `throw` என்ன?

👉 `throw` =

```text
“இந்த இடத்தில் error நடந்தது ❗”
```

👉 program immediately:

* current flow stop
* control goes to `catch` block

---

# 🧪 3. Example (full flow)

```cpp
#include <iostream>
#include <stdexcept>

void error(const std::string& msg)
{
    throw std::runtime_error(msg);
}

int main()
{
    try {
        error("Something went wrong");
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}
```

---

## 🧾 Output:

```text
Error: Something went wrong
```

---

# 🧠 4. `std::runtime_error` என்ன?

👉 இது C++ standard library class

👉 meaning:

```text
runtimeல நடந்த error represent பண்ணும் object
```

---

## inside:

```text
runtime_error("msg")
```

👉 store பண்ணும்:

* error message

---

# 🧠 5. `e.what()` என்ன?

👉 error message return பண்ணும்

```cpp
e.what()
```

👉 returns:

```text
"Something went wrong"
```

---

# ⚙️ 6. Flow Diagram

```text
throw runtime_error("msg")
        ↓
program stops normal execution
        ↓
catch block catches it
        ↓
print / handle error
```

---

# ⚠️ 7. If no `catch`?

👉 program:

```text
crash ❌
terminate ❌
```

---

# 🧠 8. Why use this?

👉 instead of:

```cpp
if (error) {
    std::cout << "error";
}
```

👉 better:

```cpp
throw runtime_error("error");
```

👉 clean + scalable ✔️

---

# 💡 9. Real-world use

👉 Example:

```cpp
if (x <= 0)
    throw std::runtime_error("Invalid input");
```

---

# 💬 Simple Tamil Summary

👉 `throw`:

* error throw பண்ணும்
* program normal flow stop

👉 `runtime_error`:

* error message store பண்ணும்

👉 `catch`:

* அந்த error handle பண்ணும்

---

# 🎯 One-line memory

👉

> “throw = signal error, catch = handle error”

---

# 🚀 Next Level (IMPORTANT 🔥)

👉 Want:

* `try-catch` deep explanation
* multiple exception types
* when to use exceptions vs if

Just tell 👍
