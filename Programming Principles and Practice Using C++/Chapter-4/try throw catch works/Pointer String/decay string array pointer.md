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
---------

``"hello":
pointer type → pointer catch தேவை` array எப்படி pointer type ஆகும்? `hello":
pointer type ``

நல்ல கேள்வி 🔥 — இங்கே தான் “array → pointer” concept cleanஆ புரிஞ்சிக்கணும்.

---

# 🧠 1. `"hello"` உண்மையில் என்ன?

```cpp
"hello"
```

👉 இது **pointer இல்ல** ❗
👉 actual type:

```text
const char[6]
```

👉 memory:

```text
h  e  l  l  o  \0
```

---

# ⚠️ 2. அப்படின்னா pointer எப்படி ஆகுது?

👉 இது automatic conversion:

```text
array → pointer decay
```

---

# 🔄 3. Decay example

```cpp
const char* p = "hello";
```

👉 internally:

```text
const char[6] → const char*
```

👉 meaning:

```text
pointer → 'h' இருக்கும் address
```

---

# 🧪 4. Simple proof

```cpp
#include <iostream>

int main()
{
    const char* p = "hello";

    std::cout << p << '\n';     // full string
    std::cout << *p << '\n';    // first char மட்டும்

    return 0;
}
```

---

# 🧠 5. Why decay நடக்குது?

👉 C/C++ design:

```text
array name → pointer to first element
```

---

## Example:

```cpp
char arr[] = "hello";

char* p = arr;
```

👉 same concept ✔️

---

# 🔥 6. Exception context

```cpp
throw "hello";
```

👉 இது:

```text
const char[6]
```

👉 but throw செய்யும் போது:

```text
decay → const char*
```

👉 அதனால்:

```cpp
catch (const char* msg)
```

👉 match ✔️

---

# ⚠️ 7. Important clarification

👉 `"hello"`:

```text
❌ pointer அல்ல (original)
✔️ array
```

👉 but:

```text
use பண்ணும்போது → pointer ஆகும்
```

---

# 🎯 8. Visual

```text
"hello"
   ↓
[ h e l l o \0 ]   (array)
   ↓ decay
pointer → h
```

---

# 💬 Simple Tamil Summary

👉 `"hello"`:

* array (`const char[]`)

👉 use பண்ணும்போது:

* pointer ஆக மாறும் (`const char*`)

---

# 🔥 One-line memory

👉

> “String literal is array, but behaves like pointer when used”

---

# 🚀 If you want next

👉 array vs pointer full deep difference
👉 why decay happens internally
👉 function argumentsல என்ன நடக்குது

Just tell 👍
----------
