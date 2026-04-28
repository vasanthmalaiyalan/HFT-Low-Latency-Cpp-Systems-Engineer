சூப்பர் 🔥 — இது தான் C++ STLல ரொம்ப powerful concept 💯
முதல் பார்வைக்கு கஷ்டமா தெரியும், ஆனா breakdown பண்ணினா easy 👇

---

# 🧠 Code

```cpp
std::sort(temps.begin(), temps.end());
```

---

# 🧠 Short Meaning

👉

> temps vectorல உள்ள values எல்லாம் **ascending orderல sort பண்ணு**

---

# 📦 Example

```cpp
std::vector<int> temps = {5, 2, 8, 1};
```

```cpp
std::sort(temps.begin(), temps.end());
```

👉 result:

```text
[1, 2, 5, 8]
```

---

# 🧩 1. Breakdown

## 🔹 `std::sort`

👉
C++ standard library function

👉

> data sort பண்ண பயன்படும்

---

## 🔹 `temps.begin()`

👉

> first element address / start position

---

## 🔹 `temps.end()`

👉

> last elementக்கு அடுத்த position

⚠️ (last element இல்லை ❗)

---

# 🧠 Visual

```text
temps = [5, 2, 8, 1]

begin → 5
end   → (after 1)
```

---

# 🔥 2. Why begin & end?

👉 sortக்கு தெரியணும்:

```text
எந்த range sort பண்ணணும்?
```

👉 அதனால:

```cpp
sort(start, end)
```

---

# 🔍 3. Internal idea

👉 roughly:

```text
start → begin()
end   → end()
```

👉 sort works on:

```text
[start, end)
```

---

# 💻 Equivalent logic (concept)

```cpp
for (...) {
    // compare and swap
}
```

👉 ஆனால் actual sort:

✔️ highly optimized
✔️ faster

---

# ⚠️ Important

👉 include வேண்டும்:

```cpp
#include <algorithm>
```

---

# 🧠 4. Descending order

```cpp
std::sort(temps.begin(), temps.end(), std::greater<int>());
```

---

# 💻 Full Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {5, 2, 8, 1};

    std::sort(v.begin(), v.end());

    for (int x : v)
        std::cout << x << " ";
}
```

---

# 🧪 Output

```text
1 2 5 8
```

---

# 💬 Simple Tamil Summary

👉

```cpp
std::sort(temps.begin(), temps.end());
```

👉 meaning:

> tempsல உள்ள values எல்லாம் orderல arrange பண்ணு

---

# 🚀 One-line memory

👉

> “begin → start, end → finish, sort → arrange”

---

# 🔥 Final clarity

👉
✔️ sort → arrange
✔️ begin → first
✔️ end → last+1

---

If you want 🔥

👉 iterator என்ன (deep explain)
👉 எப்படி sort work ஆகுது (algorithm)
👉 custom sort (complex objects)

Just tell 👍

---------

