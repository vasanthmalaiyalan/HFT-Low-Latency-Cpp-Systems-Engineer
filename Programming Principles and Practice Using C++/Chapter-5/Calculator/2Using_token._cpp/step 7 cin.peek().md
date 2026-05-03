``if (std::cin.peek() == '\n')
            break;`இதற்கு என்ன அர்த்தம்`

சூப்பர் 👍 — இது ஒரு **small but powerful I/O trick**.

---

# 🧠 Code

```cpp
if (std::cin.peek() == '\n')
    break;
```

---

# 🟢 1. `peek()` என்ன செய்கிறது?

👉 `std::cin.peek()`:

```text
அடுத்த character என்ன இருக்கிறது என்று பார்க்கும்
ஆனா அதை read செய்யாது ❌
```

---

# 🧪 Example

Input:

```text
1+2*3\n
```

Buffer:

```text
[ '1' ][ '+' ][ '2' ][ '*' ][ '3' ][ '\n' ]
                                     ↑
                                   pointer
```

---

# 🟢 2. What happens?

```cpp
std::cin.peek()
```

👉 returns:

```text
'\n'   (newline)
```

👉 BUT:

```text
pointer move ஆகாது ❌
```

---

# 🟢 3. Full meaning of code

```cpp
if (std::cin.peek() == '\n')
    break;
```

👉 Meaning:

```text
"அடுத்த character newline என்றால் loop-ஐ நிறுத்து"
```

---

# 🧠 Why needed?

👉 இந்த loop:

```cpp
while (std::cin) {
    Token t = get_token();
    tok.push_back(t);
}
```

👉 இல்லாமல்:

❌ இது continue ஆகும்
❌ newline வந்தாலும் stop ஆகாது

---

# 🟢 So peek helps

👉 detect:

```text
user enter (press Enter key)
```

---

# 🧪 Flow

Input:

```text
1+2*3 ↵
```

👉 after reading `3`:

```text
next char = '\n'
```

👉 so:

```cpp
peek() == '\n' → true
break;
```

---

# 🔥 Important Difference

| Function | Behavior           |
| -------- | ------------------ |
| `peek()` | பார்க்கும் மட்டும் |
| `get()`  | read + remove      |

---

# 🧪 Compare

```cpp
char c = std::cin.get();   // removes char
int p = std::cin.peek();   // just looks
```

---

# 💬 Simple Tamil

👉 `peek()`:

* அடுத்த character என்ன என்று பார்க்கும்
* அதை remove செய்யாது

👉 இந்த code:

```text
newline வந்தா loop stop பண்ணு
```

---

# 🎯 Final Answer

```text
peek() மூலம் அடுத்த character '\n'னா loop break ஆகும்
```

---

# 🚀 One-line

```text
peek() = look next character without consuming it
```

---

If you want 🔥

👉 peek vs get vs ignore full comparison
👉 input buffer deep internals

Just tell 👍
