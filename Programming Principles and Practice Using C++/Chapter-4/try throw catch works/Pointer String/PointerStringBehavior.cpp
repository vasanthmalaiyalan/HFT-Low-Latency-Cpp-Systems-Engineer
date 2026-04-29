#include <iostream>

int main() {

    // string literal
    const char* msg = "hello";

    std::cout << "Full string: " << msg << '\n';

    // pointer details
    std::cout << "Address (msg): " << (void*)msg << '\n';
    std::cout << "First char (*msg); " << *msg << '\n';

    // traversal nanually using pointer in cout
    std::cout << "Manual traversal: ";
    const char* p = msg;

    while (*p != '\0') {
        std::cout << *p;
        p++; // move pointer
    }
    std::cout << '\n';

    // pointer shifting 
    std::cout << "msg + 1: " << msg + 1 << '\n';
    std::cout << "msg + 2: " << msg + 2 << '\n';

    return 0;
}

/*
சரி 🔥 — நீ இப்ப கேட்டது:
👉 **pointer → address மட்டும் வைத்திருக்கும், ஆனால் முழு string access ஆகும்**
இதைக் **clearஆ காட்டும் best .cpp example** கொடுக்கிறேன்.

---

# 💻 🧪 Best Example (.cpp) — Pointer & String Behavior

```cpp
#include <iostream>

int main()
{
    // string literal
    const char* msg = "hello";

    std::cout << "Full string: " << msg << '\n';

    // pointer details
    std::cout << "Address (msg): " << (void*)msg << '\n';
    std::cout << "First char (*msg): " << *msg << '\n';

    // traverse manually using pointer
    std::cout << "Manual traversal: ";
    const char* p = msg;

    while (*p != '\0') {
        std::cout << *p;
        p++;   // move pointer
    }
    std::cout << '\n';

    // pointer shifting
    std::cout << "msg + 1: " << msg + 1 << '\n';
    std::cout << "msg + 2: " << msg + 2 << '\n';

    return 0;
}
```

---

# ⚙️ Output (Example)

```text
Full string: hello
Address (msg): 0x55f...
First char (*msg): h
Manual traversal: hello
msg + 1: ello
msg + 2: llo
```

---

# 🧠 What this proves

---

## 🔹 1. `msg`

```text
msg → 'h' இருக்கும் address ✔️
```

---

## 🔹 2. `*msg`

```text
*msg → 'h' மட்டும் ✔️
```

---

## 🔹 3. Full string எப்படி வந்தது?

```text
cout → msg addressல இருந்து \0 வரை read பண்ணுது ✔️
```

---

## 🔹 4. Pointer move

```cpp
msg + 1 → "ello"
msg + 2 → "llo"
```

👉 இது prove பண்ணுது:

```text
pointer → string start மட்டும்
memory → முழு string
```

---

# 📦 Visual

```text
memory:

h   e   l   l   o   \0
↑
msg

msg+1 →
    e   l   l   o   \0
```

---

# 💬 Simple Tamil Summary

👉 `msg`:

* address மட்டும் வைத்திருக்கும்

👉 memory:

* full string already இருக்கும்

👉 `cout`:

* அந்த memoryயை படித்து print பண்ணும்

---

# 🔥 One-line memory

👉

> “Pointer moves, string changes view — memory stays same”

---

🔥 நீ இப்ப pointer concept solidஆப் புரிஞ்சுட்டே
👉 next level: pointer vs array deep difference / memory layout diagram வேண்டும்னா சொல்லு 👍

*/