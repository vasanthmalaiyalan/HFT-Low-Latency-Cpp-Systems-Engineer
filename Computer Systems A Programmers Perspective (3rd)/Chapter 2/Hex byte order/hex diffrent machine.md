# Practice Problem 2.7

## Setup

```c
const char *m = "mnopqr";
show_bytes((byte_pointer) m, strlen(m));
```

**Key note:** `strlen(m)` = 6 — null terminator **include பண்றதில்லை** (unlike previous example where we passed 6 explicitly for "12345").

## ASCII values — 'a'=0x61, so:

```
'm' = 'a' + 12 = 0x61 + 0x0C = 0x6D
'n' = 0x61 + 13 = 0x6E
'o' = 0x61 + 14 = 0x6F
'p' = 0x61 + 15 = 0x70
'q' = 0x61 + 16 = 0x71
'r' = 0x61 + 17 = 0x72
```

## Output

```
6d 6e 6f 70 71 72
```

Null terminator print ஆகாது — `strlen()` null byte count பண்றதில்லை.

---

# 2.1.5 Representing Code

## Book-ரோட example function

```c
int sum(int x, int y) {
    return x + y;
}
```

## 4 machines-ல machine code bytes

```
Linux32:  55 89 e5 8b 45 0c 03 45 08 c9 c3          (11 bytes)
Windows:  55 89 e5 8b 45 0c 03 45 08 5d c3          (11 bytes)
Sun:      81 c3 e0 08 90 02 00 09                    (8 bytes)
Linux64:  55 48 89 e5 89 7d fc 89 75 f8 03 45 fc c9 c3  (15 bytes)
```

**Same C function → completely different bytes on different machines.**

---

## Book-ரோட key observations

**1. Different machine types = different, incompatible instructions:**

```
Linux32 starts:  55 89 e5 ...  (x86 32-bit encoding)
Sun starts:      81 c3 e0 ...  (SPARC encoding — totally different ISA)
Linux64 starts:  55 48 89 ...  (x86-64 encoding — extra REX prefix bytes)
```

**2. Same processor, different OS = different conventions:**

```
Linux32:  ... 03 45 08 c9 c3
Windows:  ... 03 45 08 5d c3
              ^^^^^^^^^^^^
              Almost same (same x86 ISA)
              but last 2 bytes differ — different calling conventions!

Linux32:  c9 c3   (leave + ret)
Windows:  5d c3   (pop %ebp + ret)
Same effect, different encoding — OS convention difference.
```

**3. Binary code is seldom portable:**

```
Linux32 binary  → runs on Linux32 ✓
Linux32 binary  → runs on Windows ✗ (different conventions)
Linux32 binary  → runs on Sun     ✗ (different ISA entirely)
Linux32 binary  → runs on Linux64 ✓ (backward compatible — special case)
```

---

## Fundamental concept — book-ரோட exact words

> "A program, from the perspective of the machine, is simply a sequence of bytes. The machine has no information about the original source program, except perhaps some auxiliary tables maintained to aid in debugging."

```
Source code (human sees):
  int sum(int x, int y) { return x + y; }

Machine sees:
  55 48 89 e5 89 7d fc 89 75 f8 03 45 fc c9 c3
  ← just bytes, no variable names, no types, nothing

Debug info (optional — -g flag):
  DWARF tables: "byte 0x55 = function sum, line 1"
  Without -g: machine has zero knowledge of source
```

---

## Unicode aside — book mention

```
ASCII:    128 characters — English only
          1 byte per character
          0x00–0x7F

Unicode:  100,000+ characters — all languages
          Base encoding: 32 bits (4 bytes) per character

UTF-8:    Variable length encoding
          ASCII characters → 1 byte (same as ASCII!)
          Other characters → 2, 3, or 4 bytes

Key property of UTF-8:
  All ASCII byte sequences have same meaning in UTF-8
  → ASCII text = valid UTF-8 text
  → Backward compatible!

Java: uses Unicode for strings internally
C:   ASCII default, Unicode libraries available
```

---

## Chapter 3 preview

இந்த section-ரோட point: machine code = bytes. Chapter 3-ல:

```
55        → push %rbp
48 89 e5  → mov %rsp, %rbp
89 7d fc  → mov %edi, -4(%rbp)
89 75 f8  → mov %esi, -8(%rbp)
03 45 fc  → add -4(%rbp), %eax
c9        → leave
c3        → ret
```

ஒவ்வொரு byte sequence-உம் என்ன instruction என்று புரியும். இப்போ bytes மட்டும் தெரியுது — Chapter 3-ல meaning தெரியும்.

அடுத்து 2.1.6 (Introduction to Boolean Algebra) போகலாமா?

------------

சூப்பர் 🔥 இப்போ இரண்டு topics —
👉 **Practice 2.7 (string bytes)**
👉 **Representing Code (machine code)**
இரண்டையும் **book flow + deep clarity**-ல explain பண்ணுறேன் 👇

---

# 🔥 ✅ Practice Problem 2.7

## GIVEN

```c
const char *m = "mnopqr";
show_bytes((byte_pointer)m, strlen(m));
```

---

# 🧠 STEP 1 — strlen(m)

```text
"mnopqr" → 6 characters
```

👉 so:

```text
len = 6
```

👉 NOTE:

```text
'\0' (null) include ஆகாது ❗
```

---

# ⚙️ STEP 2 — characters break

```text
m n o p q r
```

---

# 🔥 STEP 3 — ASCII values

👉 hint already given:

```text
'a' = 0x61 → so letters increase by 1
```

---

| Character | Hex  |
| --------- | ---- |
| m         | 0x6D |
| n         | 0x6E |
| o         | 0x6F |
| p         | 0x70 |
| q         | 0x71 |
| r         | 0x72 |

---

# 💥 STEP 4 — show_bytes output

```text
6d 6e 6f 70 71 72
```

👉 (space இல்லாம printனா:)

```text
6d6e6f707172
```

---

# 🔥 FINAL ANSWER (2.7)

```text
6d 6e 6f 70 71 72
```

---

# 💣 CORE INSIGHT

```text
String → each char = 1 byte → ASCII mapping
```

---

# ⚡ முக்கிய note

👉 null terminator print ஆகல:

```text
strlen() → length மட்டும் (6)
```

👉 so:

```text
'\0' skip ஆகுது
```

---

---

# 🔥 ✅ 2.1.5 Representing Code

இது ரொம்ப important concept 🔥

---

# 🧠 🔥 ONE LINE

```text
Program = bytes sequence தான்
```

---

# ⚙️ Example C code

```c
int sum(int x, int y) {
    return x + y;
}
```

---

👉 நீ பார்க்குறது:

```text
C code (human readable)
```

---

👉 compiler convert பண்ணும்:

```text
machine code (bytes)
```

---

# 💥 Example outputs

```text
Linux32:
5589e58b450c034508c9c3

Linux64:
554889e5897dfc8975f80345fcc9c3
```

---

# 🧠 என்ன meaning?

👉 இது:

```text
CPU execute பண்ணும் instructions (byte form)
```

---

# 🔥 முக்கியம்

👉 இது number இல்ல ❌
👉 இது string இல்ல ❌

👉 இது:

```text
instructions encoded as bytes
```

---

# ⚡ WHY different outputs?

| Machine | Reason              |
| ------- | ------------------- |
| Linux32 | 32-bit architecture |
| Linux64 | 64-bit architecture |
| Windows | different ABI       |
| Sun     | different CPU       |

---

👉 so:

```text
same C code ≠ same machine code
```

---

# 💣 BIG INSIGHT

```text
Binary code portable இல்ல ❌
Source code portable ✅
```

---

# 🧠 Deep concept

👉 CPU பார்க்குறது:

```text
bytes மட்டும்
```

👉 அது:

```text
"இது sum function"ன்னு தெரியாது ❗
```

---

# ⚡ Analogy

👉 imagine:

```text
C code → English sentence
Machine code → binary instructions
```

---

👉 different CPU:

```text
different language
```

---

# 🔥 Unicode aside (short)

👉 ASCII limitation:

```text
English மட்டும்
```

---

👉 Unicode:

```text
100,000+ characters
```

---

👉 UTF-8:

```text
ASCII compatible
```

---

# 💥 FINAL SUMMARY

## Practice 2.7

```text
"mnopqr"
→ ASCII → 6d 6e 6f 70 71 72
```

---

## Representing Code

```text
Program = bytes
CPU = executes bytes
Different machine = different bytes
```

---

# 💣 FINAL ONE-LINE

```text
"String bytes மனிதர் உருவாக்கியது — Machine code bytes CPUக்கு instructions"
```

---

🔥 நீ இப்போ புரிஞ்சுட்ட:

👉 string vs number vs code
👉 ASCII vs machine instructions
👉 portability concept

---

👉 next (🔥 powerful):

* assembly breakdown (இந்த bytes என்ன instruction?)
* disassembler எப்படி read பண்ணும்
* reverse engineering 😈

சொல்லு 😎
