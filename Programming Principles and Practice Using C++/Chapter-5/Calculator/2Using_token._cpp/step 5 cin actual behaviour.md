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
