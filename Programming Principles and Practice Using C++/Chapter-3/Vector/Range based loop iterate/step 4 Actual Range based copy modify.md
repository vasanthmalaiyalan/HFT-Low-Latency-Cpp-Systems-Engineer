சூப்பர் 🔥 — இது தான் **range-based for loop** (modern C++ style) 💯
முதலில் இது weirdா தெரியும்… ஆனா மிகவும் easy 👍

---

# 🧠 Code

```cpp
for (double x : temps)
```

---

# 🧠 Short Meaning

👉

> “tempsல உள்ள ஒவ்வொரு valueயையும் xல வைத்து loop ஓடு”

---

# 📦 Example

```cpp
std::vector<double> temps = {1.2, 3.4, 5.6};
```

---

## Loop:

```cpp
for (double x : temps)
{
    std::cout << x << '\n';
}
```

---

# 🧪 Output

```
1.2
3.4
5.6
```

---

# 🔍 Step-by-step

```text
Iteration 1 → x = 1.2
Iteration 2 → x = 3.4
Iteration 3 → x = 5.6
```

---

# 🧠 Compare with normal loop

## ❌ old way

```cpp
for (int i = 0; i < temps.size(); ++i)
{
    std::cout << temps[i];
}
```

---

## ✔️ new way

```cpp
for (double x : temps)
{
    std::cout << x;
}
```

👉 clean + easy ✔️

---

# 🧠 2. Syntax breakdown

```cpp
for ( type variable : collection )
```

---

### here:

```text
double x   → each element store ஆகும் variable
temps      → vector (collection)
```

---

# ⚠️ Important

👉 இது read-only copy:

```cpp
for (double x : temps)
```

👉 x copy தான்

---

## modify பண்ணணும்னா:

```cpp
for (double& x : temps)
{
    x = x * 2;
}
```

---

# 💻 Example (modify)

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3};

    for (int& x : v)
    {
        x = x * 10;
    }

    for (int x : v)
    {
        std::cout << x << ' ';
    }
}
```

---

# 🧪 Output

```
10 20 30
```

---

# 💬 Simple Tamil Summary

👉

```cpp
for (double x : temps)
```

👉 meaning:

> tempsல உள்ள ஒவ்வொரு valueயும் xக்கு assign ஆகும்

---

# 🚀 One-line memory

👉

> “: → collectionல இருந்து values எடுத்துக்கொள்”

---

# 🔥 Final clarity

👉
✔️ index தேவையில்லை
✔️ clean loop
✔️ modern C++

---

If you want 🔥

👉 iterator எப்படி work ஆகுது
👉 range-for behind the scenes
👉 performance difference

Just tell 👍
