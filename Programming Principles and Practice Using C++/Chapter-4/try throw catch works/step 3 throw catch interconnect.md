ஆம் 🔥 — **`throw` மற்றும் `catch` இரண்டும் direct inter-connected** தான்.
👉 இது ஒரு **signal–handler system** மாதிரி வேலை செய்கிறது.

---

# 🧠 Core Idea

```text
throw → error signal அனுப்பு
catch → அந்த signal பிடித்து handle பண்ணும்
```

👉 இவை இரண்டும் இல்லாம complete ஆகாது ❗

---

# ⚙️ Flow (Simple)

```text
try block
   ↓
throw (error)
   ↓
catch (handle)
```

---

# 🧪 Example

```cpp
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        throw std::runtime_error("Error happened");
    }
    catch (std::runtime_error& e) {
        std::cout << "Caught: " << e.what();
    }
}
```

---

# 🔍 Step-by-step

```text
1. try block start
2. throw runtime_error → error signal
3. normal flow STOP
4. matching catch block search
5. catch execute
6. program continue
```

---

# ⚠️ Important Rule

👉 `throw` alone இருந்தா:

```cpp
throw std::runtime_error("error");
```

👉 result:

```text
program crash ❌
```

---

👉 `catch` மட்டும் இருந்தா:

```cpp
try {
    // no throw
}
catch (...) {
    // nothing happens
}
```

👉 result:

```text
catch execute ஆகாது ❌
```

---

# 🧠 Interconnection Summary

| Part  | Role                 |
| ----- | -------------------- |
| throw | error உருவாக்கும்    |
| catch | error handle பண்ணும் |

---

# 🔥 Real-life analogy

👉 Imagine:

```text
throw = alarm 🔔
catch = security guard 👮
```

👉 alarm வந்தா தான் guard react பண்ணுவான்

---

# 💬 Simple Tamil Summary

👉 `throw`:

* error அனுப்பும்

👉 `catch`:

* அந்த error பிடிக்கும்

👉 இரண்டும்:

✔️ இணைந்து தான் வேலை செய்யும்

---

# 🎯 One-line memory

👉

> “throw இல்லா catch useless, catch இல்லா throw dangerous”

---

If you want 🔥

👉 நான் next explain பண்ணலாம்:

* multiple catch எப்படி வேலை செய்கிறது
* custom exception create பண்ணுவது

Just tell 👍
