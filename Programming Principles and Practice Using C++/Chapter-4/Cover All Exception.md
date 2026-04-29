சூப்பர் கேள்வி 🔥 — இது **exceptions எப்படி work ஆகுது**ன்னு core concept.

நேராக explain பண்ணுறேன் 👇

---

# 🧠 1. `throw std::runtime_error(...)` என்ன செய்கிறது?

```cpp
throw std::runtime_error("Invalid input");
```

👉 இதன் அர்த்தம்:

```text
ஒரு error object உருவாக்கி → program normal flow-ஐ நிறுத்தி → மேலே throw பண்ணுகிறது
```

👉 type:

```text
std::runtime_error  (exception object)
```

---

# 🧠 2. Control flow எப்படி move ஆகுது?

```text
throw → nearest matching catch block-க்கு jump ஆகும்
```

---

# 💻 Example

```cpp
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        throw std::runtime_error("Invalid input");
    }
    catch (...)
    {
        std::cout << "Caught something!\n";
    }
}
```

---

## 🧪 Output

```text
Caught something!
```

---

# 🧠 3. `catch (...)` என்ன?

👉 இது:

```text
“எந்த exception வந்தாலும் பிடிக்கும்”
```

👉 meaning:

```text
ALL exception types ✔️
```

---

# 🧠 4. எப்படி catch ஆகுது?

👉 Step-by-step:

---

## Step 1

```cpp
throw std::runtime_error("Invalid input");
```

👉 exception create ஆகுது

---

## Step 2

👉 runtime search:

```text
matching catch இருக்கா?
```

---

## Step 3

```cpp
catch (...)
```

👉 இது:

```text
“any type accept” ✔️
```

---

## Step 4

👉 control inside catch block

---

# ⚠️ 5. Important Difference

---

## 🔴 catch (...)

```cpp
catch (...)
```

👉 catch everything
👉 but:

```text
error details கிடையாது ❌
```

---

## 🟢 catch (std::exception& e)

```cpp
catch (const std::exception& e)
{
    std::cout << e.what();
}
```

👉 better ✔️

👉 reason:

```text
error message கிடைக்கும் ✔️
```

---

# 💻 Comparison Example

---

## ❌ catch (...)

```cpp
catch (...)
{
    std::cout << "Error happened\n";
}
```

👉 no info ❌

---

## ✅ catch with type

```cpp
catch (const std::runtime_error& e)
{
    std::cout << e.what();
}
```

👉 output:

```text
Invalid input
```

---

# 🧠 6. Exception Hierarchy

👉 important 🔥

```text
std::runtime_error
        ↓
std::exception
```

👉 so:

```cpp
catch (std::exception& e)
```

👉 catches runtime_error ✔️

---

# 💬 Simple Tamil Summary

👉 `throw runtime_error`:

* error object throw

👉 `catch (...)`:

* எந்த errorயும் பிடிக்கும்

👉 drawback:

* error details தெரியாது

---

# 🎯 One-line memory

👉

> `catch (...) = catch everything but know nothing`

---

# 🚀 Best Practice

👉 use this:

```cpp
catch (const std::exception& e)
```

👉 avoid:

```cpp
catch (...)
```

---

# 🚀 If you want next

👉 multiple catch எப்படி வேலை செய்கிறது
👉 custom exception create பண்ணுவது
👉 stack unwinding deep explanation 🔥

Just tell 👍
