சூப்பர் கேள்வி 🔥 — இது தான் **tokenizerல முக்கியமான trick**.

நீ கொடுத்த code:

```cpp
{
    std::cin.putback(ch);   // put digit back
    double val;
    std::cin >> val;        // read full number
    return Token{'8', val}; // number token
}
```

இதன் அர்த்தத்தை **step-by-step** பார்ப்போம் 👇

---

# 🧠 1. Context (முன்னாடி என்ன நடந்தது?)

👉 இதற்கு முன்:

```cpp
char ch;
std::cin >> ch;
```

👉 user input:

```text
12.5+2
```

👉 first:

```text
ch = '1'
```

---

# ⚠️ Problem

👉 நாம் இப்போ:

```text
'1'
```

மட்டும் read பண்ணிட்டோம்

👉 ஆனால் actual number:

```text
12.5
```

👉 முழு number வேண்டியது ✔️

---

# 🟢 2. `putback(ch)` என்ன செய்கிறது?

```cpp
std::cin.putback(ch);
```

👉 இது:

```text
read பண்ணிய character-ஐ மீண்டும் stream-க்கு திருப்பி வைக்கிறது
```

---

## 💡 Tamil

👉 “ஒரு character read பண்ணிட்டோம்… அதை மீண்டும் unread பண்ணுறோம்”

---

## 🧪 Example

Before:

```text
cin → "2.5+3"
        ↑ (next)
```

After reading `'2'`:

```text
cin → ".5+3"
```

After `putback('2')`:

```text
cin → "2.5+3"
```

---

# 🟢 3. Why this is needed?

👉 Because:

```cpp
std::cin >> val;
```

👉 expects:

```text
full number (2.5, 12, etc.)
```

👉 not single digit

---

# 🟢 4. Next line

```cpp
double val;
std::cin >> val;
```

👉 இது:

```text
full number read பண்ணும்
```

---

## 🧪 Example

Input:

```text
12.5+2
```

👉 result:

```text
val = 12.5
```

---

# 🟢 5. Final line

```cpp
return Token{'8', val};
```

👉 இது:

```text
number token உருவாக்குகிறது
```

---

## 💡 Meaning

```text
kind = '8'   (number)
value = 12.5
```

---

# 🧠 Full Flow

```text
Input: 12.5+2

Step 1: ch = '1'
Step 2: putback('1')
Step 3: cin >> val → 12.5
Step 4: Token{'8', 12.5}
```

---

# 🔥 Important Insight

👉 Without `putback`:

```text
val = 2.5 ❌ (wrong)
```

👉 Because first digit lost

---

# 🧪 Compare

## ❌ Without putback

```text
read '1'
cin >> val → 2.5 ❌
```

---

## ✔ With putback

```text
putback('1')
cin >> val → 12.5 ✔️
```

---

# 💬 Simple Tamil Summary

👉 இந்த code:

1. digit read பண்ணுது
2. அதை மீண்டும் input-க்கு திருப்பி வைக்குது
3. முழு number read பண்ணுது
4. Token உருவாக்குது

---

# 🎯 Final Answer

```text
putback() → read பண்ணிய character-ஐ மீண்டும் input stream-க்கு திருப்பி வைக்கும்
```

---

# 🚀 One-line

```text
putback = undo last read character
```

---

If you want next 🔥

👉 cin எப்படி internally buffer handle பண்ணுது
👉 get() vs >> difference
👉 tokenizer full deep dive

Just tell 👍
