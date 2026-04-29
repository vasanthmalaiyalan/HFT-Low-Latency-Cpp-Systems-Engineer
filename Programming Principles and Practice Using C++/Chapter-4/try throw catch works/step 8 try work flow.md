சரியான கேள்வி 🔥 — `try` புரியாமல் `throw/catch` முழுசா புரியாது.

---

# 🧠 1. `try` என்ன செய்கிறது?

👉 Simple answer:

```text
try = “இந்த codeல error வர வாய்ப்பு இருக்கு, கவனமா handle பண்ணு”
```

---

# ⚙️ 2. Syntax

```cpp
try {
    // risky code
}
catch (...) {
    // handle error
}
```

---

# 🧠 3. `try` வேலை என்ன?

👉 `try` block:

* normalஆ code run பண்ணும் ✔️
* error (`throw`) வந்தா:

  * **control immediately stop**
  * nearest matching `catch`க்கு jump

---

# 🔥 4. Example

```cpp
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        std::cout << "Start\n";
        throw std::runtime_error("Error!");
        std::cout << "End\n"; // ❌ run ஆகாது
    }
    catch (std::runtime_error& e) {
        std::cout << "Caught: " << e.what();
    }
}
```

---

## Output:

```text
Start
Caught: Error!
```

---

# 🔍 Breakdown

```text
1. try start
2. "Start" print
3. throw → error
4. try block STOP ❌
5. catch run ✔️
```

👉 `"End"` line skip ஆகும் ❗

---

# ⚠️ 5. If no `try`?

```cpp
throw std::runtime_error("error");
```

👉 result:

```text
program crash ❌
```

---

# 🧠 6. Important Role of `try`

👉 `try`:

* error catch செய்யும் boundary
* “safe zone” create பண்ணும்

---

# 🧪 7. Multiple catch

```cpp
try {
    throw 10;
}
catch (int e) {
    std::cout << "int";
}
catch (...) {
    std::cout << "unknown";
}
```

---

# 🧠 8. Without throw?

```cpp
try {
    std::cout << "No error";
}
catch (...) {
    std::cout << "Won’t run";
}
```

👉 catch execute ஆகாது ✔️

---

# 🎯 9. Important Insight

👉 `try` alone:

❌ nothing special

👉 `try + throw`:

✔️ exception flow start

---

# 💬 Simple Tamil Summary

👉 `try`:

* risky code surround பண்ணும்
* error வந்தா catchக்கு அனுப்பும்

---

# 🔥 One-line memory

👉

> “try = watch zone, throw = alarm, catch = response”

---

# 🚀 Next (if you want)

👉 try-catch best practices
👉 nested try எப்படி வேலை செய்கிறது
👉 real-world error handling design

Just tell 👍
