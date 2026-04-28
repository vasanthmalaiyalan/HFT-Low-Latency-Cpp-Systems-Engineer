அடிக்கடி வரும் doubt இதுதான் 🔥 — நல்லா கவனிச்சிருக்கே 💯

---

# 🧠 Short Answer

👉
**size ≠ capacity (எப்போதும் equal இருக்காது)**

👉
`cap = 4 (maybe)` போட்டதற்கு காரணம்:

> vector future growth காக extra space allocate பண்ணும் ✔️

---

# 📦 1. size vs capacity

| Concept  | Meaning                         |
| -------- | ------------------------------- |
| size     | எத்தனை elements இருக்கிறது      |
| capacity | எவ்வளவு elements வைக்க முடியும் |

---

# 🔍 Example

```cpp id="c7d0fs"
std::vector<int> v;
```

---

## Step 1

```cpp id="z4u6v6"
v.push_back(10);
```

```text
size = 1
capacity = 1
```

---

## Step 2

```cpp id="t5saz4"
v.push_back(20);
```

👉 usually grow:

```text
size = 2
capacity = 2 (or 2→4 depending impl)
```

---

## Step 3

```cpp id="nfxv9l"
v.push_back(30);
```

👉 இங்கே தான் முக்கியம் 🔥

```text
size = 3
capacity = 4 ✔️
```

---

# 🧠 2. ஏன் capacity = 4?

👉 காரணம்:

```text
future growth optimize பண்ண
```

---

## ❌ bad approach

ஒவ்வொரு pushக்கும்:

```text
new memory allocate ❌
copy ❌
delete ❌
```

👉 slow ❌

---

## ✔️ smart approach (vector)

👉 memory double பண்ணும்:

```text
1 → 2 → 4 → 8 → 16 ...
```

---

# 📊 Growth pattern

```text
size:      1   2   3   4   5
capacity:  1   2   4   4   8
```

---

# 🔥 3. Why this important?

👉 performance 🔥

```text
less allocation = fast ✔️
```

---

# 💻 Proof code

```cpp id="nwd44l"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i);
        std::cout << "size: " << v.size()
                  << " capacity: " << v.capacity() << '\n';
    }
}
```

---

# 🧪 Example output

```text
size: 1 capacity: 1
size: 2 capacity: 2
size: 3 capacity: 4
size: 4 capacity: 4
size: 5 capacity: 8
```

---

# 💬 Simple Tamil Summary

👉 size:

* actual elements

👉 capacity:

* maximum space

👉 vector:

* future growth காக extra space வைக்கும்

---

# 🚀 One-line memory

👉

> “size = used, capacity = reserved”

---

# 🔥 Final clarity

👉
✔️ size == capacity → always இல்ல
✔️ capacity ≥ size ✔️

---

If you want 🔥

👉 capacity doubling deep math
👉 amortized complexity explain
👉 real interview question

Just tell 👍
