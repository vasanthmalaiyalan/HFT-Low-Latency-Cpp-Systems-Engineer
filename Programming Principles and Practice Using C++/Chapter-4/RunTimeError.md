## ஏன் Ratio Print ஆகல?

Step by step trace பண்ணோம்:

```
test(-1, 2, 3) call ஆகுது
  x = -1, y = 2, z = 3
```

---

### area1 calculation:

```cpp
area1 = area(-1, 2)
  → length = -1  ← 0-ஐ விட சிறியது!
  → return 0
area1 = 0
```

---

### area3 calculation:

```cpp
area3 = framed_area(2, 3)
  → area(2-2, 3-2)
  → area(0, 1)
  → length = 0  ← 0-ஐ விட சிறியதில்லை, ஆனா equal!
  → return 0
area3 = 0
```

---

### if check:

```cpp
if (area3 == 0)  // true!
    std::cout << "Error: division by zero\n";
    return;      // இங்கயே function exit ஆகிடுது
```

`area3 = 0` ஆனதால் division by zero check trigger ஆகுது — ratio line-யே reach ஆகல!

---

## Fix — Guard Condition சரி பண்ணு

```cpp
int area(int length, int width) {
    if (length <= 0 || width <= 0)  // 0-உம் invalid-ஆ treat பண்றோம்
        return 0;
    return length * width;
}
```

`length <= 0` இருக்கு — so `area(0, 1)` = 0 வருது. இது correct behaviour — 0 width-க்கு area இல்ல.

**Ratio பார்க்கணும்னா valid values போடணும்:**

```cpp
int main() {
    test(4, 5, 6);  // valid values
}
```

```
area1 = area(4, 5)        = 20
area3 = framed_area(5, 6) = area(3, 4) = 12
ratio = 20.0 / 12         = 1.66667
```

**Output:**
```
1.66667
```

---

**Simple rule:**

> `-1, 2, 3` போட்டதால் இரண்டு areas-உமே `0` ஆச்சு — division by zero guard trigger ஆச்சு, ratio print ஆகல. Valid positive values போட்டா ratio வரும்.

-------

Excellent 🔥 — இந்த **4.5 Run-time errors** தான் real debugging ஆரம்பம்.
👉 compile pass ஆகி, program run ஆகும்போது தான் **actual problems தெரியும்**

நாம் இதை **deep but simple Tamil + code breakdown** explain பண்ணலாம் 👇

---

# 📘 4.5 Run-time Errors — Core Idea

👉 Book சொல்றது:

> Program run ஆகும் போது வரும் errors

---

# 🧠 1. Reality

👉 Compile OK ✔️
👉 Link OK ✔️

👉 Still:

```text id="k0l0lm"
❌ no output
❌ wrong output
❌ crash
```

---

# ⚠️ 2. Why this happens?

👉 காரணங்கள்:

* logic mistake
* wrong condition
* invalid input
* divide by zero

---

# 💻 3. Given Code (Important)

```cpp id="rt1"
int area(int length, int width)
{
    return length * width;
}

int framed_area(int x, int y)
{
    return area(x - 2, y - 2);
}

void test(int x, int y, int z)
{
    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);

    double ratio = double(area1) / area3;
}
```

---

# 🧪 4. Input

```cpp id="rt2"
int main()
{
    test(-1, 2, 3);
}
```

---

# 🔍 5. Step-by-step Execution (PLAY COMPUTER 🔥)

---

## 🟢 Step 1

```text id="s1"
x = -1, y = 2
area1 = -1 * 2 = -2 ❌
```

👉 negative area ❗

---

## 🟢 Step 2

```text id="s2"
framed_area(1,3)
→ area(1-2, 3-2)
→ area(-1,1)
→ -1 ❌
```

---

## 🟢 Step 3 🔥

```text id="s3"
framed_area(2,3)
→ area(0,1)
→ 0
```

👉 area3 = 0 ❗

---

## 🟢 Step 4 💣

```cpp id="rt3"
double ratio = area1 / area3;
```

👉 becomes:

```text id="s4"
-2 / 0 ❌
```

👉 divide by zero → crash 💥

---

# ⚠️ 6. Key Problems

---

## 🔴 Problem 1: Invalid logic

👉 negative area:

```text id="p1"
area = -2 ❌
```

---

## 🔴 Problem 2: Divide by zero

```text id="p2"
area3 = 0 → crash ❌
```

---

# 🧠 7. Important Insight

👉 Book சொல்றது:

> Computer = very fast moron 😄

👉 meaning:

```text id="p3"
You write wrong → computer executes correctly ❗
```

---

# ⚠️ 8. Who should handle error?

👉 2 options:

---

## 🟢 Option 1: Caller handle

```cpp id="opt1"
if (x > 0 && y > 0)
    area(x, y);
else
    std::cout << "Invalid input";
```

---

## 🟢 Option 2: Function handle (better 🔥)

```cpp id="opt2"
int area(int length, int width)
{
    if (length <= 0 || width <= 0)
    {
        std::cout << "Invalid dimensions\n";
        return 0;
    }

    return length * width;
}
```

---

# 💻 9. Safe Version (Fixed Code)

```cpp id="safe1"
#include <iostream>

int area(int length, int width)
{
    if (length <= 0 || width <= 0)
        return 0;

    return length * width;
}

int framed_area(int x, int y)
{
    return area(x - 2, y - 2);
}

void test(int x, int y, int z)
{
    int area1 = area(x, y);
    int area3 = framed_area(y, z);

    if (area3 == 0)
    {
        std::cout << "Error: division by zero\n";
        return;
    }

    double ratio = double(area1) / area3;
    std::cout << ratio << '\n';
}

int main()
{
    test(-1, 2, 3);
}
```

---

# 🎯 10. Key Learning

👉 Run-time errors:

* hardest to find ❗
* compiler detect பண்ணாது ❗

---

# 💬 Simple Tamil Summary

👉 Run-time error:

* program run ஆகும்போது வரும்

👉 Example:

* divide by zero
* negative values
* wrong logic

---

# 🔥 One-line truth

👉

> “Program correctா run ஆகுது ≠ correct result”

---

# 🚀 If you want next

👉 exception handling (try-catch)
👉 real debugging techniques
👉 input validation methods

Just tell 👍
