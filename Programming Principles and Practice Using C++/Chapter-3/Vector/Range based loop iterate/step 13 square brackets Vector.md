சூப்பர் 🔥 — இது **array / vector access** concept.
நீ கேட்டது முக்கியமானது 💯

---

# 🧠 Code

```cpp
std::cout << "Median: " << temps[temps.size() / 2] << '\n';
```

---

# 🧠 Short Answer

👉
`temps[ ... ]` என்பது:

> vectorல **index மூலம் value access பண்ணுவது**

👉
`() (parentheses)` → function call
👉
`[] (square brackets)` → element access

---

# 📦 1. Breakdown

```cpp
temps.size() / 2
```

👉 இது:

```text
middle index
```

---

## Example

```cpp
temps = [1.2, 3.4, 5.6, 7.8, 9.0]
size = 5
```

👉

```text
5 / 2 = 2
```

👉

```cpp
temps[2] = 5.6 ✔️
```

---

# 🔍 2. ஏன் `[]` பயன்படுத்துகிறோம்?

👉 vector ஒரு **array மாதிரி behave பண்ணும்**

👉 syntax:

```cpp
v[index]
```

👉 meaning:

```text
அந்த positionல உள்ள value கொடு
```

---

# ⚠️ முக்கியம்

👉

```cpp
temps(2)   ❌
```

👉 error ❗

👉 ஏன்?

```text
() = function call
```

---

# 🧠 3. Under the hood

👉

```cpp
temps[i]
```

👉 internally:

```cpp
*(temps.data() + i)
```

👉 pointer arithmetic 🔥

---

# 📦 Visual

```text
Index:   0    1    2    3    4
Value:  [1.2][3.4][5.6][7.8][9.0]
               ↑
           temps[2]
```

---

# 🔥 4. Median logic

👉 median = middle value

👉 formula:

```cpp
index = size / 2
```

---

# 💻 Example

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3,4,5};

    std::cout << v[v.size() / 2];  // 3
}
```

---

# 💬 Simple Tamil Summary

👉

```cpp
temps[i]
```

👉 meaning:

> i-வது positionல உள்ள value

---

# 🚀 One-line memory

👉

> “[] → index access, () → function call”

---

# 🔥 Final clarity

👉
✔️ `[]` → data access
✔️ `()` → function call

---

If you want 🔥

👉 `at()` vs `[]` difference
👉 out-of-bound error எப்படி வரும்
👉 memory level pointer explanation

Just tell 👍
