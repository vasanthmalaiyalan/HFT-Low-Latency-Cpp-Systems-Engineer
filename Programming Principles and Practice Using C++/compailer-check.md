சூப்பர் 🔥 இது **Compilation section** — compiler எப்படி வேலை செய்கிறது + errors எப்படி வரும் என்பதைக் deepஆ explain பண்ணுது.
நான் book styleல முழுக்க clearஆ explain பண்ணுறேன் 👇 (very important 💯)

---

# 🧠 1. Compilationன்னா என்ன?

👉 C++ ஒரு **compiled language**

👉 அதாவது:

```text
Source Code (நாம் எழுதுறது)
        ↓
Compiler
        ↓
Machine Code (computer புரிஞ்சுக்குறது)
```

---

## 📌 Terms (முக்கியம்)

👉

* Source code → `.cpp` file
* Object code → `.o` (Linux) / `.obj` (Windows)

👉 Compiler:

👉 **நாம் எழுதிய code → machine language convert பண்ணும்** 

---

# ⚙️ 2. Compiler என்ன check பண்ணும்?

👉 Compiler வேலை:

### 🔍 3 main checks:

1. Grammar (syntax சரியா?)
2. Meaning (variables / names validஆ?)
3. Obvious errors

---

👉 Example:

* `;` miss → error ❌
* spelling mistake → error ❌

👉 Compiler:

👉 **“zero tolerance” 😅** 

---

# ❌ 3. Common errors (Book examples)

👉 இவை மிகவும் important 🔥

---

## 🚫 Error 1: `std::cout` தெரியாது

```cpp
int main() {
    std::cout << "Hello";
}
```

👉 Problem:

👉 `import std;` இல்ல

👉 Solution:

```cpp
import std;
```

---

## 🚫 Error 2: `cout` மட்டும் use பண்ணினால்

```cpp
cout << "Hello";
```

👉 Problem:

👉 `std::` missing

👉 Solution:

```cpp
std::cout
```

---

## 🚫 Error 3: String close பண்ணல

```cpp
"Hello
```

👉 Problem:

👉 `"` missing

---

## 🚫 Error 4: Wrong keyword

```cpp
integer main()
```

👉 Problem:

👉 `int` தான் correct

---

## 🚫 Error 5: Wrong operator

```cpp
std::cout < "Hello";
```

👉 Problem:

👉 `<` ❌
👉 `<<` ✔️

---

## 🚫 Error 6: Single quotes

```cpp
'Hello'
```

👉 Problem:

👉 single quotes → char only

👉 stringக்கு:

```cpp
"Hello"
```

---

## 🚫 Error 7: Semicolon missing

```cpp
std::cout << "Hello"
```

👉 Problem:

👉 `;` இல்ல

---

## ⚠️ Rule:

👉
**“ஒவ்வொரு statement முடிவிலும் ; வை”**

---

# 😮 4. Surprise (Important)

👉 இது work ஆகும்:

```cpp
int main() {
    std::cout << "Hello";
}
```

👉 `return 0;` இல்லையென்றாலும் OK

👉 ஏன்?

👉 main()ல் default:

👉 return 0 assume பண்ணும்

---

# 🧠 5. Big truth (Book message)

👉 Author சொல்றார்:

👉
**“Programmingல அதிக நேரம் errors fix பண்ணுவதில தான் போகும்”** 

---

## 😅 Reality:

* code எழுதுறது easy
* debug பண்ணுறது தான் main வேலை

---

# 🤝 6. Compiler பற்றி mindset

---

## ❗ Important advice

👉 Compiler sometimes annoying 😤

👉 ஆனால்:

👉 **Compiler usually right ✔️** 

---

## ⚠️ Warning

👉 Compiler:

* common sense இல்ல ❌
* guess பண்ணாது ❌

👉 strict rules follow பண்ணும்

---

## 💡 Good thing

👉 Compiler:

👉
**நம்ம mistakes prevent பண்ணும் best friend 🔥** 

---

# 🚀 Full flow (simple)

```text
Code எழுதுறோம்
   ↓
Compiler check பண்ணும்
   ↓
Errors இருந்தா → stop ❌
   ↓
Correctனா → machine code ✔️
```

---

# 💥 Final summary

👉 Compilation:

* code translate பண்ணும்
* syntax check பண்ணும்
* errors detect பண்ணும்

---

## 💥 One line takeaway

👉 **“Compiler strictஆ இருக்கும்… ஆனா அது தான் உங்க best friend 💪”**

---

🔥 நீங்க இதை புரிஞ்சுக்கிட்டீங்கனா
👉 debugging half easy ஆகிடும்

---

வேணும்னா 👉
நான் உங்களுக்கு **real compiler errors + எப்படி fix பண்ணணும் (practice set)** கொடுக்கலாம் 😄
