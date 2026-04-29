Awesome 🔥 — இது **Range errors (most common real bug)**.
👉 Almost every programmer lifeல இதை encounter பண்ணுவான் 😄

நாம் இதை **simple Tamil + step-by-step + safe code** explain பண்ணலாம் 👇

---

# 📘 4.6.2 Range Errors — Core Idea

👉 Range error =

```text
index (subscript) valid range-க்கு வெளியே போகும் போது
```

---

# 🧠 1. Valid Range என்ன?

👉 vector `v` இருந்தா:

```text
[0 : v.size())
```

👉 meaning:

* start = 0 ✔️
* end = size - 1 ✔️

---

## 🧪 Example

```cpp
std::vector<int> v = {10, 20, 30};
```

👉 valid indices:

```text
0, 1, 2
```

👉 invalid:

```text
3 ❌
```

---

# 💥 2. Common Bug (Off-by-one error)

---

## ❌ Wrong Code

```cpp
for (int i = 0; i <= v.size(); ++i)
```

👉 problem:

```text
i = v.size() → out of range ❌
```

---

## ✅ Correct Code

```cpp
for (int i = 0; i < v.size(); ++i)
```

---

# 🧠 3. Why this happens?

👉 human mistake:

```text
<= vs < confusion 😵
```

👉 this is called:

* off-by-one error
* range error
* bounds error

---

# 💻 4. Example Program (with error)

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3,4,5};

    for (int i = 0; i <= v.size(); ++i)   // ❌ bug
        std::cout << v[i] << '\n';
}
```

👉 crash / undefined behavior ❗

---

# ⚠️ 5. Safe Version (with exception)

👉 Use `.at()` instead of `[]`

---

## 💻 Safe Code

```cpp
#include <iostream>
#include <vector>

int main()
{
    try
    {
        std::vector<int> v = {1,2,3,4,5};

        for (int i = 0; i <= v.size(); ++i)
            std::cout << v.at(i) << '\n';   // 🔥 safe access
    }
    catch (const std::out_of_range&)
    {
        std::cerr << "Oops! Range error\n";
    }
}
```

---

## 🧪 Output

```text
1
2
3
4
5
Oops! Range error
```

---

# 🧠 6. Important Difference

---

## ❌ `v[i]`

* no checking
* dangerous
* fast

---

## ✅ `v.at(i)`

* checks range
* throws exception
* safe ✔️

---

# 🔥 7. Why vector throws exception?

👉 vector doesn’t know:

```text
what YOU want to do ❗
```

👉 so:

```text
throw error → you decide ✔️
```

---

# 🧠 8. Better Loop (Best Practice)

---

## ✅ Range-based loop

```cpp
for (int x : v)
    std::cout << x << '\n';
```

👉 no index mistake ✔️

---

# ⚠️ 9. When index needed?

👉 then use:

```cpp
for (int i = 0; i < v.size(); ++i)
```

👉 NEVER:

```cpp
i <= v.size() ❌
```

---

# 💬 Simple Tamil Summary

👉 range error:

* index overflow

👉 common mistake:

* `<=` instead of `<`

👉 safe method:

* `v.at(i)` ✔️

---

# 🎯 One-line memory

👉

> “Index always: 0 ≤ i < size”

---

# 🚀 If you want next

👉 vector internal எப்படி வேலை செய்கிறது
👉 iterator vs index
👉 segmentation fault deep explanation

Just tell 👍
