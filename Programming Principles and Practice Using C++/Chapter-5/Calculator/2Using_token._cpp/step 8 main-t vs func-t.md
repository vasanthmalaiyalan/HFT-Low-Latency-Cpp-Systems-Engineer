`இதில் இருக்கும் இந்த `Token t = get_token();` t-யும் , function உள்ள இருக்கும் இந்த `void print_tokens(const std::vector<Token>& tok)
{
    std::cout << "Tokens: ";
    for (const Token& t : tok) {` t-யும் ஒண்ணா?`

    நல்ல கேள்வி 🔥 — பெயர் ஒரே மாதிரி இருந்தாலும், **இரண்டும் ஒரே object அல்ல**.

---

# 🧠 Short Answer

```text
இரண்டு t-களும் வெவ்வேறு scope-ல இருக்கும் வேறு objects
```

---

# 🟢 1. முதல் `t`

```cpp
Token t = get_token();
```

👉 இது:

* `main()` function-ல இருக்கும் variable
* ஒவ்வொரு loop iteration-க்கும் புதிய `t` உருவாகும்

---

# 🟢 2. இரண்டாவது `t`

```cpp
for (const Token& t : tok)
```

👉 இது:

* `print_tokens()` function-ல உள்ள variable
* vector உள்ள ஒவ்வொரு element-ஐ reference ஆக point பண்ணும்

---

# 🧠 Important Difference

| Feature  | First `t`            | Second `t`                |
| -------- | -------------------- | ------------------------- |
| Location | `main()`             | `print_tokens()`          |
| Type     | `Token`              | `const Token&`            |
| Purpose  | store returned value | iterate over vector       |
| Memory   | separate object      | reference (no new object) |

---

# 🟢 3. Scope Concept

👉 C++ல:

```text
variable name same இருந்தாலும் scope வேறானால் problem இல்லை
```

---

# 🧪 Example

```cpp
int main() {
    int x = 10;

    {
        int x = 20;
        std::cout << x;  // 20
    }

    std::cout << x;      // 10
}
```

---

# 🟢 4. Visualization

```text
main():
   t → Token{'8', 12.5}

print_tokens():
   t → reference to tok[i]
```

👉 இரண்டு completely independent ✔️

---

# 🔥 Key Insight

👉 name (`t`) same ஆனாலும்:

```text
memory + scope + meaning = different
```

---

# 💬 Simple Tamil

👉 முதல் `t`:

* function return value store பண்ணுது

👉 இரண்டாவது `t`:

* vector உள்ள elements-ஐ iterate பண்ணுது

👉 இரண்டும்:

❌ same object இல்லை

---

# 🎯 Final Answer

```text
இரண்டு t-களும் பெயர் மட்டும் same, ஆனால் வேறு scope-ல இருக்கும் வேறு objects
```

---

# 🚀 One-line

```text
same name ≠ same variable (scope matters)
```

---

If you want 🔥

👉 reference vs value deep explanation
👉 range-based for எப்படி internally work ஆகுது

Just tell 👍
