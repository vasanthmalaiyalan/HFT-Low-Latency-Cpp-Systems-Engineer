``std::cin >> val;   ` val உள்ளே ஸ்டோர் ஆவது இந்த முழு value? `12.5+3``

இல்ல ❌ — `std::cin >> val;` முழு `"12.5+3"`-ஐ store பண்ணாது.

---

# 🧠 என்ன நடக்குது?

```cpp
double val;
std::cin >> val;
```

👉 இது **number மட்டும்** தான் read பண்ணும்
👉 number முடியும் இடத்தில stop ஆகும்

---

# 🧪 Example

Input:

```text
12.5+3
```

---

## Step-by-step

👉 `std::cin >> val;`

```text
val = 12.5
```

👉 அடுத்து:

```text
'+' buffer-ல இருக்கும்
```

---

# 🟢 Buffer state

```text
[ '1' ][ '2' ][ '.' ][ '5' ][ '+' ][ '3' ]
                        ↑
                     pointer stops here
```

👉 `+` வந்ததும் reading stop ✔️

---

# 🧠 Why stop?

👉 `>> val`:

```text
valid number characters மட்டும் read பண்ணும்
```

✔ digits (`0-9`)
✔ `.`
✔ scientific notation (`e`, etc.)

❌ `+` (operator contextல) → stop

---

# 🟢 Next read

```cpp
char op;
std::cin >> op;
```

👉 இப்ப:

```text
op = '+'
```

---

# 🟢 Full flow

```cpp
double val;
char op;
int next;

std::cin >> val;   // 12.5
std::cin >> op;    // '+'
std::cin >> next;  // 3
```

---

# 💬 Simple Tamil

👉 `std::cin >> val;`

✔️ number மட்டும் read பண்ணும்
❌ முழு string இல்ல

---

# 🎯 Final Answer

```text
12.5+3 → val = 12.5 மட்டும் தான்
```

---

# 🚀 One-line

```text
>> val reads ONLY the number part, stops at non-number character
```

---

If you want 🔥

👉 `cin >> val` எப்படி internally parse பண்ணுது
👉 whitespace + buffer handling deep dive

Just tell 👍

------------

``12.5+3 → val = 12.5 மட்டும் தான்` val உள்ளே 3 இருக்கணும் தானே? why 12.5?``


இல்ல ❌ — `val` உள்ளே **3 வரவே கூடாது**.
👉 `std::cin >> val;` எப்போதும் **ஒரே ஒரு number token மட்டும்** தான் read பண்ணும்.

---

# 🧠 முக்கிய rule

```text
operator>> (double) = next valid number மட்டும் read பண்ணும்
```

👉 அது **number முடியும் இடத்தில் stop ஆகும்**.

---

# 🧪 Example

Input:

```text
12.5+3
```

---

## Step-by-step

### 🔹 Step 1

```cpp
std::cin >> val;
```

👉 parser read பண்ணும்:

```text
1 → OK
2 → OK
. → OK
5 → OK
+ → STOP ❗
```

---

## 👉 Result

```text
val = 12.5 ✔️
```

👉 `+` வந்ததும்:

```text
"இது number இல்லை → நிறுத்து"
```

---

# 🟢 அடுத்தது என்ன?

buffer இப்போ:

```text
+3
```

---

### 🔹 Step 2

```cpp
char op;
std::cin >> op;
```

👉

```text
op = '+'
```

---

### 🔹 Step 3

```cpp
int x;
std::cin >> x;
```

👉

```text
x = 3
```

---

# 🧠 Why `3` val-ல் போகாது?

👉 ஏனென்றால்:

```text
12.5+3 ≠ single number ❌
```

👉 அது:

```text
number + operator + number ✔️
```

---

# 🔥 Important Insight

👉 `cin >> val`:

```text
ஒரு token மட்டும் read பண்ணும்
```

👉 expression முழுவதையும் read பண்ணாது ❌

---

# 🧪 Compare

## ❌ Wrong thinking

```text
12.5+3 → 15.5 ❌
```

👉 இது calculation, input reading இல்லை

---

## ✔ Correct behavior

```text
12.5 → val
+    → op
3    → next value
```

---

# 💬 Simple Tamil

👉 `std::cin >> val;`

* number மட்டும் read பண்ணும்
* operator வந்தவுடன் நிறுத்தும்
* அதனால் `3` val-க்கு போகாது

---

# 🎯 Final Answer

```text
val = 12.5 தான், ஏனெனில் cin ஒரு number மட்டும் தான் read பண்ணும்
```

---

# 🚀 One-line

```text
cin >> val = first number மட்டும், expression முழுவதும் இல்லை
```

---

If you want 🔥

👉 tokenizer எப்படி tokens split பண்ணுது full deep
👉 expression parsing எப்படி build பண்ணுறது

Just tell 👍
