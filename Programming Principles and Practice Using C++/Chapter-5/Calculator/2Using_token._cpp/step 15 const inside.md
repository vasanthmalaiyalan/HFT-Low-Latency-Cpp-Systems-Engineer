சுருக்கமாக சொன்னா 👍 — **`const` கட்டாயம் இல்லை**, code compile ஆகும்.
ஆனா அதை நீக்கினால் **behavior மாறும்**, சில நேரங்களில் **bug வர வாய்ப்பு** கூட இருக்கு. எப்படி என்பதை பார்க்கலாம் 👇

---

# 🟢 மூன்று விதம் எழுதலாம்

## 1) 🔒 Safe (read-only) — Recommended

```cpp
for (const Token& t : tok)
```

👉 meaning:

* `t` மூலம் **modify செய்ய முடியாது**
* copy ஆகாது (fast)
* safe ✔️

---

## 2) ✏️ Modify செய்ய வேண்டும்னா

```cpp
for (Token& t : tok)
```

👉 meaning:

* `t.kind`, `t.value` **change செய்யலாம்**
* original vector data **மாறும்**

### 🧪 Example

```cpp
for (Token& t : tok) {
    if (t.kind == '8') t.value = 0;  // vector data change ஆகும்
}
```

---

## 3) 📦 Copy version (avoid usually)

```cpp
for (Token t : tok)
```

👉 meaning:

* ஒவ்வொரு iteration-க்கும் **copy உருவாகும்**
* vector data change ஆகாது

### ⚠️ Problem

```cpp
for (Token t : tok) {
    t.value = 0;   // ❌ original மாற்றமில்லை
}
```

👉 performance ↓ (unnecessary copy)

---

# 🧠 Key Difference Table

| Version        | Copy? | Modify original? | Safe? | Performance |
| -------------- | ----- | ---------------- | ----- | ----------- |
| `const Token&` | ❌     | ❌                | ✔️    | 🔥 Best     |
| `Token&`       | ❌     | ✔️               | ⚠️    | 🔥 Best     |
| `Token`        | ✔️    | ❌                | ✔️    | ❌ Slow      |

---

# 🟢 So answer to your question

👉 “const இல்லாம போடலாமா?”

✔️ போடலாம்
❗ ஆனால்:

```text
const இல்லாம இருந்தா accidental modification நடக்கலாம்
```

---

# 💬 Simple Tamil

👉 `const`:

* data change ஆகாமல் பாதுகாக்கும்
* read-only access

👉 remove பண்ணினா:

* change பண்ண முடியும்
* bug வர வாய்ப்பு ↑

---

# 🎯 Final Answer

```text
const இல்லாம எழுதலாம், ஆனால் const பயன்படுத்துவது safer + best practice
```

---

# 🚀 One-line

```text
const Token& = fast + safe + no modification
```

---

If you want 🔥
👉 const correctness full deep
👉 reference vs value performance test

Just tell 👍
