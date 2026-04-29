Nice 🔥 — இது **real design problem**:
👉 *Error யார் handle பண்ணணும்?*

இந்த section சொல்லுது:
👉 **Caller handle பண்ணும் approach** (Let the user beware)

நாம் இதை **simple Tamil + example + why bad** explain பண்ணலாம் 👇

---

# 📘 4.5.1 Caller deals with errors — Core Idea

👉 meaning:

```text
function safe இல்ல → caller check பண்ணணும்
```

---

# 🧠 1. Basic Example

```cpp
int area(int x, int y)
{
    return x * y;
}
```

👉 problem:

* negative values check இல்ல ❌

---

## 🟢 Caller handles it

```cpp
if (x <= 0)
    error("non-positive x");

if (y <= 0)
    error("non-positive y");

int a = area(x, y);
```

---

# ⚠️ 2. Simplified version

```cpp
if (x <= 0 || y <= 0)
    error("invalid area input");

int a = area(x, y);
```

👉 `||` = OR

---

# 🧠 3. Problem starts with `framed_area`

```cpp
int framed_area(int x, int y)
{
    return area(x - 2, y - 2);
}
```

---

## ❌ Caller now must know internal logic

👉 call:

```cpp
int area2 = framed_area(1, z);
```

👉 but inside:

```text
1 - 2 = -1 ❌
```

👉 invalid

---

## 🟡 So caller must do:

```cpp
if (z <= 2)
    error("invalid framed_area input");

int area2 = framed_area(1, z);
```

---

# ⚠️ 4. BIG PROBLEM (IMPORTANT 🔥)

👉 Caller needs to know:

```text
framed_area subtracts 2
```

👉 இது wrong design ❌

---

# 🧠 5. This is called "Brittle Code"

👉 meaning:

```text
change small thing → break everything ❗
```

---

## Example:

👉 if someone changes:

```cpp
return area(x - 1, y - 1);
```

👉 now:

* all caller checks wrong ❌

---

# ⚠️ 6. Magic Constant Problem

👉 `2` hardcoded ❌

---

## Better:

```cpp
constexpr int frame_width = 2;

int framed_area(int x, int y)
{
    return area(x - frame_width, y - frame_width);
}
```

---

## Caller must now do:

```cpp
if (y - frame_width <= 0 || z - frame_width <= 0)
    error("invalid");
```

---

👉 still messy ❌

---

# 🤢 7. Why this approach is BAD

👉 Problems:

---

## ❌ 1. Code becomes ugly

```text
too many checks everywhere
```

---

## ❌ 2. Hard to read

```text
logic hidden inside checks
```

---

## ❌ 3. Tight coupling

```text
caller depends on function internals
```

---

## ❌ 4. Maintenance nightmare

```text
change function → update all callers
```

---

# 🎯 8. Important Insight

👉 Book சொல்றது:

> “We shouldn’t know how function works internally”

👉 abstraction break ஆகுது ❌

---

# 💻 9. Bad Design Example

```cpp
int area2 = framed_area(1, z);
int area3 = framed_area(y, z);
```

👉 simple ✔️

---

👉 but with caller checks:

```cpp
if (1 - frame_width <= 0 || z - frame_width <= 0)
    error("bad");

int area2 = framed_area(1, z);
```

👉 ugly ❌

---

# 🔥 10. Best Insight

👉 Caller approach:

✔️ sometimes needed
❌ but not scalable

---

# 💬 Simple Tamil Summary

👉 Caller deals with error:

* function safe இல்ல
* caller check பண்ணும்

👉 problem:

* code messy
* logic தெரிய வேண்டி வரும்
* maintain பண்ண கஷ்டம்

---

# 🎯 One-line truth

👉

> “Caller-based error handling = fragile design”

---

# 🚀 What next?

👉 Next section (IMPORTANT 🔥):

👉 **4.5.2 → Callee deals with errors (BEST approach)**

👉 இது தான் real good design 💯

---

If you want, I’ll explain that next 👍
