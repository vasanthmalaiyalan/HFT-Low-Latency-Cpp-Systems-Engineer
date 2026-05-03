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
---------

``std::cin >> ch;
std::cin.putback(ch);
std::cin >> val;` putback மூலம் மீண்டும் buffer undo செய்து `std::cin >> val;` cin மீண்டும் அந்த buffer-ல இருந்து ரீட் செய்து val -ல ஸ்டோர் செய்கிறது அல்லவா?`

ஆமாம் ✔️ — நீ சொன்ன flow சரிதான், ஆனால் அதை **preciseஆ புரிஞ்சிக்கணும்** 👇

---

# 🧠 Code

```cpp
std::cin >> ch;
std::cin.putback(ch);
std::cin >> val;
```

---

# 🟢 Step-by-step என்ன நடக்குது?

## 🟡 Step 1

```cpp
std::cin >> ch;
```

👉 ஒரு character read ஆகும்

```text
Input: 12.5+3
ch = '1'
pointer → '2'
```

---

## 🟡 Step 2

```cpp
std::cin.putback(ch);
```

👉 last read character (`'1'`) மீண்டும் streamக்கு திருப்பி வைக்கப்படும்

```text
pointer → '1'
```

👉 buffer content change ஆகாது ❌
👉 pointer மட்டும் move ஆகும் ✔️

---

## 🟡 Step 3

```cpp
std::cin >> val;
```

👉 இப்ப pointer மீண்டும் `'1'`ல இருக்கிறது

👉 so:

```text
val = 12.5
```

---

# 🧠 Key Understanding

👉 நீ சொன்னது:

> “cin மீண்டும் அந்த bufferல இருந்து read செய்து valல store செய்கிறது”

✔️ Correct

👉 but more precise:

```text
putback → pointer rewind
>> val → அந்த rewind point-ல இருந்து full number read
```

---

# 🔥 Why this is powerful?

👉 first நாம்:

```text
single char detect பண்ணுறோம்
```

👉 பிறகு:

```text
full number read பண்ணுறோம்
```

---

# 🧪 Without putback

```cpp
std::cin >> ch;   // '1'
std::cin >> val;  // 2.5 ❌
```

👉 first digit miss ஆகும்

---

# 🟢 With putback

```cpp
std::cin >> ch;        // '1'
std::cin.putback(ch);  // rewind
std::cin >> val;       // 12.5 ✔️
```

---

# 💬 Simple Tamil

👉 `putback`:

* “நாம் read பண்ணியது cancel பண்ணு”
* pointer பின்னால் போகும்
* அதே இடத்திலிருந்து மீண்டும் read செய்யலாம்

---

# 🎯 Final Answer

```text
ஆம் — putback மூலம் rewind செய்து, cin மீண்டும் அந்த இடத்திலிருந்து read பண்ணி val-ல் store செய்கிறது
```

---

# 🚀 One-line

```text
putback = rewind → next read starts from same position again
```

---

If you want next 🔥

👉 cin >> எப்படி number parse பண்ணுது (internal logic)
👉 tokenizer without putback (advanced method)

Just tell 👍
