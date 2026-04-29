சூப்பர் 🔥 — இது இரண்டு முக்கிய concepts:

1. `v.at(i)` என்ன?
2. `catch (const std::out_of_range&)` என்ன?

நாம் clearஆ புரிஞ்சிக்கலாம் 👇

---

# 🧠 1. `v.at(i)` என்ன?

👉 இது `vector`-ல ஒரு **safe access function**

---

## 🔹 Normal access

```cpp
v[i];
```

👉 problem:

* range check இல்லை ❌
* out of range வந்தா → crash / garbage

---

## 🔹 Safe access

```cpp
v.at(i);
```

👉 என்ன செய்கிறது?

```text
index validஆ? → return value ✔️  
index invalidனா → exception throw ❗
```

---

## 🧪 Example

```cpp
std::vector<int> v = {10, 20, 30};

std::cout << v.at(1);  // ✔️ 20
std::cout << v.at(5);  // ❌ error throw
```

---

# ⚠️ Difference

| Method    | Safety   |
| --------- | -------- |
| `v[i]`    | ❌ unsafe |
| `v.at(i)` | ✔️ safe  |

---

# 💥 2. What happens when error?

👉 `v.at(i)` internally:

```text
if (i >= size) → throw std::out_of_range
```

---

# 🧠 3. `catch (const std::out_of_range&)` என்ன?

---

## 🔹 Meaning

```cpp
catch (const std::out_of_range&)
```

👉 means:

```text
“out_of_range exception வந்தா நான் handle பண்ணுறேன்”
```

---

## 🔹 Full code

```cpp
try
{
    std::cout << v.at(5);  // ❌
}
catch (const std::out_of_range&)
{
    std::cerr << "Oops! Range error\n";
}
```

---

## 🧪 Output

```text
Oops! Range error
```

---

# 🧠 4. Why `const`?

👉 exception modify பண்ண வேண்டாம்
👉 safe + standard practice ✔️

---

# 🧠 5. Why `&` (reference)?

👉 copy avoid பண்ண
👉 performance better

---

# 🧠 6. Why no variable name?

```cpp
catch (const std::out_of_range&)
```

👉 because:

```text
error message use பண்ணல
```

---

## If need message:

```cpp
catch (const std::out_of_range& e)
{
    std::cerr << e.what() << '\n';
}
```

---

# 💻 Full Example (Best)

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3};

    try
    {
        std::cout << v.at(5) << '\n';  // ❌
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
```

---

# 💬 Simple Tamil Summary

👉 `v.at(i)`:

* safe access
* range check
* error வந்தா exception throw

👉 `catch (std::out_of_range)`:

* அந்த error handle பண்ண

---

# 🎯 One-line memory

👉

> `v[i]` = fast but risky
> `v.at(i)` = safe but slightly slower

---

# 🚀 If you want next

👉 segmentation fault vs exception difference
👉 vector memory எப்படி வேலை செய்கிறது
👉 when to use `[]` vs `at()` (interview 🔥)

Just tell 👍
-----------

Good 🔥 — straight to the point:

---

# 🧠 `.at` meaning (simple)

👉 `.at` என்பது:

```text
“safe access function”
```

👉 Tamilல:

```text
“index சரியா இருந்தா value குடுக்கும்  
தவறா இருந்தா error throw பண்ணும்”
```

---

# 💻 Example

```cpp
std::vector<int> v = {10, 20, 30};

v.at(1);   // ✔️ 20
v.at(5);   // ❌ error (out_of_range)
```

---

# ⚠️ Compare with `[]`

```cpp
v[5];   // ❌ no check → crash / garbage
```

```cpp
v.at(5); // ✔️ check → exception
```

---

# 🧠 Real Meaning of `.at`

👉 Internally:

```text
if (index >= size)
    throw error
else
    return element
```

---

# 💬 Simple Tamil

👉 `.at(i)`:

* “i positionல element எடு”
* ஆனால் first check பண்ணும் ✔️

---

# 🎯 One-line memory

👉

> `.at` = “check பண்ணி access பண்ணு”

---

If you want 🔥
👉 when to use `[]` vs `.at()` (real interview question)
