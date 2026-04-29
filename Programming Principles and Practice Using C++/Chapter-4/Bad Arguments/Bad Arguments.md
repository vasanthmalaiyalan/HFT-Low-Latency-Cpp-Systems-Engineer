Excellent 🔥 — இது **custom exception + clean error design** concept.
👉 இங்க தான் “professional C++ thinking” start ஆகுது.

நான் இதை **simple Tamil + flow + improved code** explain பண்ணுறேன்.

---

# 📘 4.6.1 Bad Arguments — Core Idea

👉 Idea:

```text id="core1"
error detect → throw custom type
error handle → somewhere else (caller)
```

---

# 🧠 1. Custom Exception Type

```cpp
class Bad_area { };
```

👉 இது ஒரு **empty class**
👉 purpose:

```text id="p1"
“area() error வந்தது” என்று identify பண்ண
```

---

# 💻 2. area() with exception

```cpp
int area(int length, int width)
{
    if (length <= 0 || width <= 0)
        throw Bad_area{};   // ❗ throw custom type

    return length * width;
}
```

---

## 🧠 Important

👉 `Bad_area{}` meaning:

```text id="p2"
create object + throw
```

---

# 🔁 3. Flow

```text id="flow1"
area() → error → throw Bad_area
        ↓
test() → no catch → pass up
        ↓
main() → catch → handle
```

---

# 💻 4. Example Program (Clean Version)

```cpp id="best1"
#include <iostream>

// ---------- Custom exception ----------
class Bad_area { };

// ---------- Functions ----------
int area(int length, int width)
{
    if (length <= 0 || width <= 0)
        throw Bad_area{};

    return length * width;
}

int framed_area(int x, int y)
{
    constexpr int frame = 2;

    return area(x - frame, y - frame);
}

void test(int x, int y, int z)
{
    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);

    double ratio = double(area1) / area3;

    std::cout << "Ratio = " << ratio << '\n';
}

// ---------- Main ----------
int main()
{
    try
    {
        test(-1, 2, 4);   // ❌ invalid input
    }
    catch (Bad_area)
    {
        std::cout << "Oops! bad arguments to area()\n";
    }

    return 0;
}
```

---

# 🧪 Output

```text id="out1"
Oops! bad arguments to area()
```

---

# 🧠 5. VERY IMPORTANT CONCEPT 🔥

---

## 🟢 Separation of Responsibility

👉 area():

```text id="sep1"
detect error மட்டும் ✔️
```

---

## 🟢 main():

```text id="sep2"
handle error மட்டும் ✔️
```

---

👉 Both independent ✔️

---

# 🔥 6. Why this is powerful?

---

## ✅ 1. Central handling

👉 100 calls இருந்தாலும்:

```text id="c1"
1 catch block போதும் ✔️
```

---

## ✅ 2. No need to check everywhere

👉 no:

```cpp
if (error) ...
```

---

## ✅ 3. Works across functions

👉 even nested calls:

```text id="c2"
area → framed_area → test → main
```

👉 error propagate ஆகும் ✔️

---

# ⚠️ 7. Real-world Meaning

👉 Large projectல:

* many functions
* many libraries

👉 impossible:

```text id="c3"
everywhere check ❌
```

👉 solution:

```text id="c4"
throw → catch
```

---

# 💬 Simple Tamil Summary

👉 custom exception:

* own error type create
* throw பண்ணலாம்

👉 benefit:

* clean separation
* reusable
* scalable

---

# 🎯 One-line memory

👉

> “Throw where error happens, catch where it matters”

---

# 🚀 If you want next

👉 custom exception with message (advanced 🔥)
👉 multiple catch எப்படி வேலை செய்கிறது
👉 real-world exception design pattern

Just tell 👍
