இது ஒரு common misunderstanding 😄 — **“decay ஆனா first letter மட்டும் கிடைக்கும்”** என்பது தவறு.

---

# 🧠 முக்கிய point

👉 `const char*` என்பது:

```text
❌ ஒரு character மட்டும் இல்ல
✔️ string-ன் முதல் எழுத்தின் address (pointer)
```

---

# 📦 1. `"hello"` memory எப்படி இருக்கும்?

```text
h   e   l   l   o   \0
↑
pointer (start)
```

---

# 🔄 2. decay என்ன செய்கிறது?

```cpp
const char* p = "hello";
```

👉 இது:

```text
p → 'h' இருக்கும் இடத்தைக் காட்டும்
```

👉 but:

```text
அதுக்கு பின்னாடி முழு string இருக்குது ✔️
```

---

# 🧪 3. Example

```cpp
#include <iostream>

int main()
{
    const char* p = "hello";

    std::cout << p << '\n';      // full string
    std::cout << *p << '\n';     // first letter மட்டும்

    return 0;
}
```

---

## Output:

```text
hello
h
```

---

# 🧠 4. Difference

| Expression | Meaning         |
| ---------- | --------------- |
| `p`        | full string     |
| `*p`       | first character |

---

# 🔍 5. catch context

```cpp
try {
    throw "hello";
}
catch (const char* msg) {
    std::cout << msg;
}
```

👉 `msg`:

```text
pointer to 'h'
```

👉 print:

```text
hello ✔️
```

---

# ⚠️ 6. Why full string print ஆகுது?

👉 காரணம்:

```text
C-style string = null-terminated
```

👉 `\0` வரைக்கும் print ஆகும்

---

# 🧠 7. Visual

```text
msg → h → e → l → l → o → \0
```

👉 `std::cout << msg`:

```text
start → until \0 → print ✔️
```

---

# 💬 Simple Tamil Summary

👉 `const char*`:

* first letter மட்டும் இல்ல ❌
* string முழுவதும் access செய்யும் pointer ✔️

---

# 🎯 One-line memory

👉

> “Pointer points to first character, but sees the whole string”

---

# 🚀 If you want next

👉 pointer arithmetic explain
👉 எப்படி msg[1], msg[2] வேலை செய்கிறது
👉 memory diagram deep

Just tell 👍
