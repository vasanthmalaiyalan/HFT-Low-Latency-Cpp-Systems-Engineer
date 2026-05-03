`putback பயன்படுத்தி buffer-ல இருப்பதை ஒரு step மட்டும் பின்னால் போவதற்கு மட்டும் பயன்படுத்துகிறோமா? `

சரியான observation 👍 — **ஆம், பொதுவாக `putback` ஒரு step மட்டும் பின்னால் போக பயன்படுத்துகிறோம்**.
ஆனா அதுதான் முழு story இல்லை — கொஞ்சம் nuance இருக்கு 👇

---

# 🧠 Core idea

```text
putback = last read character-ஐ மீண்டும் streamக்கு திருப்பி வைப்பது
```

👉 practically:

```text
pointer → ஒரு இடம் பின்னால்
```

---

# 🟢 1. Typical usage (நாம் calculator exampleல செய்தது)

```cpp
char ch;
std::cin >> ch;

std::cin.putback(ch);  // undo last read
```

👉 இது:

✔️ ஒரு step rewind
✔️ மிகவும் common usage

---

# 🟡 2. Can we go back more than 1 step?

👉 technically:

✔️ சில implementations allow பண்ணும்
❌ but **guarantee இல்லை**

```cpp
std::cin.putback('5');
std::cin.putback('.');
```

👉 இது sometimes work ஆகும்
👉 but standard guarantee பண்ணாது ⚠️

---

# 🔴 3. Important rule (Standard view)

👉 C++ standard சொல்றது:

```text
putback works reliably for ONE character
```

👉 அதற்கு மேல்:

```text
implementation dependent (unsafe)
```

---

# 🟢 4. Difference: putback vs unget

```cpp
std::cin.putback(ch);  // check + put
std::cin.unget();      // just move pointer back
```

👉 `unget()`:

✔️ faster
❌ character check இல்ல

---

# 🟢 5. Why putback is used?

👉 tokenizer exampleல:

```cpp
std::cin >> ch;
std::cin.putback(ch);
std::cin >> val;
```

👉 purpose:

```text
single character read → full number read செய்ய
```

---

# 🟢 6. When NOT to use putback

👉 complex parsingக்கு:

❌ multiple rewinds வேண்டும்னா
❌ unpredictable behavior வரும்

👉 instead:

✔️ read into string
✔️ parse manually

---

# 💬 Simple Tamil Summary

👉 `putback`:

✔️ ஒரு character மட்டும் undo பண்ணும்
✔️ pointer ஒரு step பின்னால் போகும்

👉 multiple steps:

⚠️ safe இல்ல

---

# 🎯 Final Answer

```text
ஆம் — பொதுவாக putback ஒரு step rewindக்கு தான் பயன்படுத்தப்படுகிறது
```

---

# 🚀 One-line

```text
putback = safe one-step rewind (not multi-step rewind tool)
```

---

If you want next 🔥

👉 real-world tokenizer எப்படி எழுதணும் (without putback issues)
👉 string-based parsing vs stream parsing

Just tell 👍
