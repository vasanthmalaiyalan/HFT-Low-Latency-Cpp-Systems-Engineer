Nice 🔥 — this is the **heart of modern C++ error handling**.
👉 Exceptions = *clean + safe + professional way*

நான் இதை **simple Tamil + concept + working code** explain பண்ணுறேன்.

---

# 📘 4.6 Exceptions — Core Idea

👉 Book சொல்றது:

> Error detect (callee)
> Error handle (caller)

👉 but:

```text id="m8f0kx"
error ignore ஆகக்கூடாது ❗
```

👉 இதை solve பண்ணுது → **exceptions**

---

# 🧠 1. What is Exception?

👉 Normal flow break ஆகும் ❗

👉 Instead of:

```cpp
return value;
```

👉 we do:

```cpp
throw error;
```

---

# 🔁 2. Flow

```text id="flow1"
function → error detect
        → throw
        → caller catch
        → handle
```

---

# 💻 3. Basic Example

```cpp id="ex1"
#include <iostream>
#include <stdexcept>

int divide(int a, int b)
{
    if (b == 0)
        throw std::runtime_error("Cannot divide by zero");

    return a / b;
}

int main()
{
    try
    {
        int result = divide(10, 0);
        std::cout << result << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
}
```

---

## 🧪 Output:

```text id="out1"
Error: Cannot divide by zero
```

---

# 🧠 4. Key Parts

---

## 🟢 throw

```cpp id="t1"
throw std::runtime_error("error message");
```

👉 error send

---

## 🟢 try

```cpp id="t2"
try {
    // risky code
}
```

👉 error வரும் code

---

## 🟢 catch

```cpp id="t3"
catch (const std::exception& e)
```

👉 error handle

---

# ⚠️ 5. Important Rule

👉 If nobody catches:

```text id="rule1"
program crash ❌
```

---

# 🧠 6. Why exceptions powerful?

---

## ✅ 1. Cannot ignore errors

👉 return value போல forget ஆகாது

---

## ✅ 2. Clean code

```cpp
int x = func();   // no checking here
```

👉 readable ✔️

---

## ✅ 3. Separate logic

👉 function → detect
👉 main → handle

---

# ⚠️ 7. What is “exceptional”?

👉 Book important point 🔥

---

## ❌ NOT exception

```text id="not1"
file not found
user input wrong
```

👉 normal situation

---

## ✅ Exception

```text id="yes1"
invalid math (divide by 0)
impossible state
logic break
```

---

# 🧠 8. Example Difference

---

## ❌ Normal handling

```cpp id="n1"
if (!file.open())
    std::cout << "file not found";
```

---

## ✅ Exception case

```cpp id="n2"
if (b == 0)
    throw std::runtime_error("divide by zero");
```

---

# 🎯 9. Best Practice

👉 Use exceptions when:

✔️ function cannot fix error
✔️ error serious
✔️ caller must handle

---

# 💬 Simple Tamil Summary

👉 exception:

* error வந்தா throw
* caller catch

👉 benefit:

* ignore ஆகாது
* clean code

---

# 🔥 One-line memory

👉

> “throw → stop → catch → handle”

---

# 🚀 If you want next

👉 multiple catch எப்படி வேலை செய்கிறது
👉 custom exception class
👉 real-world exception design

Just tell 👍
