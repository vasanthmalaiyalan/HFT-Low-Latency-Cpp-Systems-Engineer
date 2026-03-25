சூப்பர் 🔥 இது CSAPPல **Integral Data Types (very important foundation)** — நான் simple + clearஆ explain பண்ணுறேன்.

---

# 🧠 1. Integral Data Types என்றால் என்ன?

👉 Cல:

> integer values store பண்ண use பண்ணும் types

---

## 🔹 Main types

```c
char
short
int
long
```

👉 இதுக்கு இரண்டு versions இருக்கும்:

```c
signed    // negative + positive
unsigned  // only positive
```

---

# 🔥 2. Size (bytes) → range decide ஆகும்

👉 முக்கியம்:

> **bits அதிகமா இருந்தா → range அதிகம்**

---

## 🧪 Typical sizes (modern systems)

| Type  | Bytes             | Bits |
| ----- | ----------------- | ---- |
| char  | 1                 | 8    |
| short | 2                 | 16   |
| int   | 4                 | 32   |
| long  | 8 (64-bit system) |      |

---

# 📊 3. Range எப்படி calculate?

## 🔹 Unsigned

```text
0 to (2^w - 1)
```

👉 Example (8-bit):

```text
0 to 255
```

---

## 🔹 Signed (two’s complement)

```text
-2^(w-1) to 2^(w-1) - 1
```

👉 Example (8-bit):

```text
-128 to 127
```

---

# 💥 4. முக்கிய observation (book சொல்லும்)

> ❗ range symmetric இல்ல

---

## Why?

```text
-128 to 127
```

👉 negative side → 128 values
👉 positive side → 127 values

---

## 🧠 காரணம்

👉 one bit (MSB) → signக்கு use ஆகுது

👉 அதனால்:

```text
10000000 = -128
```

👉 +128 represent பண்ண முடியாது ❌

---

# 🔥 5. 32-bit vs 64-bit difference

## 🔹 32-bit program

```text
int / long → 4 bytes
```

👉 range:

```text
-2^31 to 2^31-1
```

---

## 🔹 64-bit program

```text
long → 8 bytes
```

👉 range:

```text
-2^63 to 2^63-1
```

👉 huge range 🔥

---

# ⚠️ Important point (book highlight)

> ❗ `long` size machine-dependent

| System | long size |
| ------ | --------- |
| 32-bit | 4 bytes   |
| 64-bit | 8 bytes   |

---

# 🔒 6. Fixed-size types (safe)

👉 இதுக்காக தான்:

```c
#include <stdint.h>
```

---

## Examples

```c
int32_t   // exactly 32-bit
int64_t   // exactly 64-bit
uint32_t
uint64_t
```

👉 portable code எழுத use பண்ணணும் ✅

---

# 💥 7. C standard vs reality

👉 C standard சொல்லுது:

> minimum range மட்டும் guarantee

---

## Example

👉 `int`:

* minimum: 16-bit
* usually: 32-bit

---

# 🧠 8. Java difference

👉 Java:

> ❗ unsigned types கிடையாது (except char)

---

# 🎯 Final summary

| Concept  | Meaning             |
| -------- | ------------------- |
| signed   | negative + positive |
| unsigned | only positive       |
| size ↑   | range ↑             |
| MSB      | sign bit            |
| range    | asymmetric          |

---

# 🔥 One-line takeaway

> bits count தான் range decide பண்ணும்
> MSB sign ஆகும் → asymmetric range

---

# 🚀 உனக்கு next level

👉 **“sign extension vs zero extension”**
👉 (type casting + bugsல use ஆகும் 🔥)

சொல்லு — அதை deepஆ explain பண்ணுறேன் 😏
