சூப்பர் கேள்வி 🔥 — இது அடிப்படை ஆனால் மிகவும் முக்கியமான concept.

---

# 🧠 1. Why `int main()`?

👉 `main()` = program start point

👉 OS (Operating System) program run பண்ணும்போது:

```text
main() function-ஐ call பண்ணும்
```

---

# 🎯 முக்கிய காரணம்

👉 `int` return type use பண்ணுறது:

> program முடிந்ததும் OS-க்கு ஒரு **status code** அனுப்பணும்

---

# 🟢 2. Return value meaning

```cpp id="r1"
int main()
{
    return 0;
}
```

👉 `return 0;` means:

```text
program successfully finished ✔️
```

---

## ❌ Non-zero

```cpp id="r2"
return 1;
```

👉 meaning:

```text
error / abnormal exit ❌
```

---

# 🧠 3. OS perspective

👉 OS expect பண்ணும்:

```text
program → exit status
```

👉 அது check பண்ணும்:

* success?
* failure?

---

# 🧪 Real Example (Linux)

```bash id="b1"
./a.out
echo $?
```

👉 output:

```text
0   → success
1   → error
```

---

# ⚠️ 4. What if no return?

```cpp id="r3"
int main()
{
}
```

👉 modern C++:

```text
automatically return 0 ✔️
```

---

# ❓ 5. Why not `void main()`?

👉 ❌ standard C++ல allowed இல்லை

👉 காரணம்:

* OSக்கு status return செய்ய முடியாது

---

# 🧠 6. Full Example

```cpp id="full1"
#include <iostream>

int main()
{
    std::cout << "Hello\n";

    return 0;
}
```

---

# 💬 Simple Tamil Summary

👉 `main()`:

* program start

👉 `int`:

* OSக்கு result அனுப்ப

👉 `return 0`:

* success ✔️

---

# 🎯 One-line memory

👉

> “main returns status to OS”

---

# 🔥 Real Developer Insight

👉 production systemsல:

* return code important
* scripts, automation இதை use பண்ணும்

---

If you want 🔥

👉 `argc, argv` explain
👉 program exit codes deep
👉 OS interaction

Just tell 👍
