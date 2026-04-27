சூப்பர் 👍 — இது basic ஆனாலும் **மிக முக்கியமான concept** 🔥

---

# 📘 `v.size()` என்ன?

👉

> vectorல இருக்குற elements count தான்

---

# 🧠 Simple Example

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {10, 20, 30, 40};

    std::cout << v.size() << '\n';

    return 0;
}
```

---

# 🧪 Output

```text
4
```

👉 explanation:

```text
[10, 20, 30, 40] → 4 elements
```

---

# 🔍 Important

👉 index vs size:

```text
index: 0  1  2  3
size:  4
```

👉

> last index = size - 1

---

# ⚠️ Common Mistake

```cpp
v[v.size()]   // ❌ WRONG
```

👉 correct:

```cpp
v[v.size() - 1]   // ✔️ last element
```

---

# 🧠 Another Example

```cpp
std::vector<int> v;

v.push_back(5);
v.push_back(10);

std::cout << v.size();   // 2
```

---

# 💬 Simple Tamil Summary

👉 `v.size()`:

* எத்தனை elements இருக்குனு சொல்லும்

---

# 🚀 One-line memory

👉

> “size = count of elements”

---

If you want 🔥

👉 `capacity()` vs `size()` difference
👉 vector memory எப்படி வேலை செய்கிறது

Just tell 👍
