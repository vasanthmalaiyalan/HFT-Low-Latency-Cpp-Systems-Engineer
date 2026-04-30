சரியான கேள்வி 🔥 — இதுக்கு clear answer:

---

# 🟢 Short Answer

👉 **ஆம் ✔️**

```text
Constructor உருவாக்கணும்னா → class பெயரே use பண்ணணும்
```

👉 இல்லையெனில் அது constructor இல்லை ❌
👉 அது ஒரு normal function தான்

---

# 🧠 Why?

👉 C++ rule:

```text
constructor = class name same இருக்கணும்
```

👉 compiler இதை பார்த்து தான் identify பண்ணும்:

* இது constructorஆ? ✔️
* இல்ல normal functionஆ? ❌

---

# 🟢 1. Correct Constructor

```cpp
class BankAccount {
public:
    BankAccount(double initial) {   // ✔️ constructor
        balance = initial;
    }

private:
    double balance;
};
```

👉 usage:

```cpp
BankAccount acc(1000);  // ✔️ auto call
```

---

# 🔴 2. Wrong (Not Constructor)

```cpp
class BankAccount {
public:
    void init(double initial) {   // ❌ normal function
        balance = initial;
    }

private:
    double balance;
};
```

👉 usage:

```cpp
BankAccount acc;   // object create
acc.init(1000);    // manual call
```

---

# 🔥 Difference

| Constructor        | Normal Function      |
| ------------------ | -------------------- |
| auto call ✔️       | manual call ❌        |
| class name same ✔️ | any name             |
| no return type ✔️  | return type வேண்டும் |

---

# ⚠️ Important Case

```cpp
class BankAccount {
public:
    void BankAccount(double initial) {  // ❌ NOT constructor
        balance = initial;
    }
};
```

👉 இது constructor இல்லை ❌
👉 இது ஒரு function மட்டும்

---

# 🧠 Tamil Explanation

👉 constructor:

```text
object உருவாகும் போது தானாக run ஆகும் function
```

👉 அதனால:

```text
class பெயரே use பண்ணுறோம்
```

---

# 🎯 Final Answer

👉

```text
constructor வேண்டும்னா → class பெயரே பயன்படுத்த வேண்டும் ✔️
```

👉

```text
வேற பெயர் வைத்தால் → அது constructor அல்ல ❌
```

---

# 🔥 Ultimate Insight

```text
constructor = special function
identify செய்ய → class name தான் key
```

---

If you want next 🔥

👉 multiple constructors எப்படி வேலை செய்கிறது
👉 default constructor auto எப்படி create ஆகுது
👉 destructor என்ன

Just tell 👍
