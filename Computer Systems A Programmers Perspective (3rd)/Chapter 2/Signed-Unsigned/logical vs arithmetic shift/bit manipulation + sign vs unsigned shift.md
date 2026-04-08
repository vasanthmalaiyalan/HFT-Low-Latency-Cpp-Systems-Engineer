சூப்பர் problem 🔥 — இது **bit manipulation + sign vs unsigned shift** புரிஞ்சிக்க best example. நம்ம clearஆ break பண்ணலாம்.

---

# 🔹 Given Functions

```c
int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}
```

---

# 🔥 Core Idea

👉 இரண்டிலும் same operations போல தெரியும்
ஆனா **type difference** தான் result மாற்றுது 💥

---

# 🔹 Important Rules

### ✅ Left shift (`<<`)

👉 bits leftக்கு move
👉 right side 0 fill

---

### ✅ Right shift (`>>`)

| Type     | Behavior                         |
| -------- | -------------------------------- |
| unsigned | logical shift (0 fill)           |
| signed   | arithmetic shift (sign bit fill) |

---

# 🔥 Step-by-step understanding

## 🔹 fun1

```c
(word << 24) >> 24
```

👉 `(word << 24)` → unsigned
👉 `>> 24` → logical shift (0 fill)

👉 Result:
➡️ **last 8 bits மட்டும் keep பண்ணும் (unsigned)**

---

## 🔹 fun2

```c
((int) word << 24) >> 24
```

👉 cast to signed first
👉 `>>` → arithmetic shift

👉 Result:
➡️ **last 8 bits → signed number ஆக convert**

---

# 🔥 Table Solution

## 🟢 1. w = `0x00000076`

👉 last byte = `0x76` (118, positive)

| Function | Result     |
| -------- | ---------- |
| fun1     | 0x00000076 |
| fun2     | 0x00000076 |

---

## 🟢 2. w = `0x87654321`

👉 last byte = `0x21` (positive)

| Function | Result     |
| -------- | ---------- |
| fun1     | 0x00000021 |
| fun2     | 0x00000021 |

---

## 🟢 3. w = `0x000000C9`

👉 last byte = `0xC9`
👉 binary: `11001001` → negative (signed)

| Function | Result           |
| -------- | ---------------- |
| fun1     | 0x000000C9 (201) |
| fun2     | 0xFFFFFFC9 (-55) |

---

## 🟢 4. w = `0xEDCBA987`

👉 last byte = `0x87`
👉 binary: `10000111` → negative

| Function | Result            |
| -------- | ----------------- |
| fun1     | 0x00000087 (135)  |
| fun2     | 0xFFFFFF87 (-121) |

---

# 🔥 Final Table

| w          | fun1(w)    | fun2(w)    |
| ---------- | ---------- | ---------- |
| 0x00000076 | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000C9 | 0x000000C9 | 0xFFFFFFC9 |
| 0xEDCBA987 | 0x00000087 | 0xFFFFFF87 |

---

# 🔥 Part B: What each function does?

## ✅ fun1

👉
**Extract last byte (lowest 8 bits) as unsigned**

➡️ always positive (0–255)

---

## ✅ fun2

👉
**Extract last byte and interpret as signed 8-bit number**

➡️ range: -128 to 127

---

# 🔥 Simple understanding

| Function | Meaning                |
| -------- | ---------------------- |
| fun1     | “last byte (unsigned)” |
| fun2     | “last byte (signed)”   |

---

# 🔥 One-line summary

👉
**fun1 → zero-extended byte**
**fun2 → sign-extended byte**

---

💥 இது real-worldல use:

* parsing binary data
* network packets
* exploit development (byte-level control)

---

நீ விரும்பினா next:
👉 assembly (`movzx` vs `movsx`)
👉 visual bit diagram

காட்டுறேன் 😄
