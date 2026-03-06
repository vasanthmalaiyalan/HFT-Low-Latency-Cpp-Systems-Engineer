இந்த **Chapter 20 – “ASCII and a Cast of Characters”**-ல author சொல்ல வருவது மிகவும் simple idea தான்.
**Computer memory bits மட்டும் தான் store செய்யும்.**
அதனால் **text (letters, numbers, punctuation)** கூட **bits ஆக convert செய்ய வேண்டும்**.

---

# 1️⃣ Problem: Computer text எப்படி store செய்யும்?

Computer memory:

```text
0 1 0 1 1 0 1 0 ...
```

ஆனால் நாம் எழுதுவது:

```text
Hello
A
7
!
```

அதனால் solution:

```text
Each character → unique binary code
```

இதுதான் **character encoding**.

---

# 2️⃣ ASCII Standard

Most important system:

**ASCII**

ASCII என்பது:

```text
7-bit code
```

அதாவது:

```text
2^7 = 128 characters
```

Range:

```text
0000000 → 1111111
0 → 127
```

---

# 3️⃣ ASCII examples

Example:

```text
Hello
```

ASCII hex codes:

```
H = 48
e = 65
l = 6C
l = 6C
o = 6F
```

So memory stores:

```
48 65 6C 6C 6F
```

---

Example sentence:

```
Hello, you!
```

ASCII:

```
48 65 6C 6C 6F 2C 20 79 6F 75 21
```

Where:

```
2C = ,
20 = space
21 = !
```

---

# 4️⃣ ASCII structure

ASCII characters roughly:

| Range  | Meaning            |
| ------ | ------------------ |
| 0–31   | control characters |
| 32–47  | punctuation        |
| 48–57  | digits             |
| 65–90  | A–Z                |
| 97–122 | a–z                |

Example:

```
A = 65
B = 66
C = 67
```

---

# 5️⃣ Interesting trick (uppercase / lowercase)

ASCII clever design:

```
a = 61
A = 41
```

Difference:

```
20h (32 decimal)
```

So programs easily convert case.

Example logic:

```
lowercase - 32 → uppercase
```

---

# 6️⃣ Control characters

ASCII includes special non-visible codes:

| Code | Meaning         |
| ---- | --------------- |
| 09   | TAB             |
| 0A   | Line Feed       |
| 0D   | Carriage Return |
| 08   | Backspace       |

Example:

```
A TAB B TAB C
```

prints:

```
A    B    C
```

---

# 7️⃣ ASCII limitation

ASCII problem:

```
Only English characters
```

Missing:

```
é ñ ö
£
Greek
Chinese
Hindi
```

---

# 8️⃣ Extended ASCII

Many systems used:

```
8-bit
```

Characters:

```
256 possible
```

But different computers used **different tables** → compatibility problems.

---

# 9️⃣ Unicode (modern solution)

Modern system:

**Unicode**

Unicode uses:

```
16-bit
```

Characters:

```
2^16 = 65,536
```

So it supports:

```
English
Chinese
Arabic
Hindi
Japanese
Korean
etc
```

Important design:

```
First 128 characters = ASCII
```

So compatibility maintained.

---

# ⭐ Chapter 20 core idea (very short)

```
Text → characters
characters → numbers
numbers → binary bits
```

Computer stores text using **character encoding standards like ASCII and Unicode**.

---

✅ **One line summary**

> Computers store text by mapping every character to a numeric code (ASCII → Unicode) and storing that code as bits.

---

💡 Since you asked earlier about **important chapters**, this chapter is actually **very important for programmers** because it explains:

```
strings
files
text encoding
memory storage
```

which appear everywhere in:

```
C
C++
operating systems
network protocols
file formats
```

---

If you want, I can also show you a **very powerful realization computer scientists get from this chapter**:

```
text
images
audio
video
programs
```

👉 **All of them are ultimately just bytes in memory.**

That realization is the **final mental model of this entire book**.
