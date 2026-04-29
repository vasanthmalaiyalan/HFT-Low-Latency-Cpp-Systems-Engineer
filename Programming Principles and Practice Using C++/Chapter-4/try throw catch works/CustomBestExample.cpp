#include <iostream>

// function
void check_age(int age) {

    if (age < 0)
       throw "Age cannot be negative"; // custom throw (const char*) that throw internally which one waiting for receive string type or char so throw it

    if (age > 120)
       throw "Age seems unrealistic";  // another custom error   
}

int main() {

    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    try {
        check_age(age);   // risky call
        std::cout << "Valid age entered \n";
    }

    catch (const char* msg) {        // catch custom type waiting for string
        std::cout << "Error: " << msg << '\n';
    }

    std::cout << "Program continues.....\n";
    return 0;
}


/*
சரி 🔥 — இப்ப **`try–throw–catch` (custom style, `const char*`)** use பண்ணி ஒரு **clean + practical example** பார்ப்போம்.

---

# 💻 🧪 Best Example (.cpp) — Custom Exception (string)

👉 Scenario:
User வயது (age) enter பண்ணுவார்
👉 invalid age (negative / >120) இருந்தா error throw

```cpp id="custom1"
#include <iostream>

// function
void check_age(int age)
{
    if (age < 0)
        throw "Age cannot be negative";        // 🔥 custom throw (const char*)

    if (age > 120)
        throw "Age seems unrealistic";         // 🔥 another custom error
}

int main()
{
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    try {
        check_age(age);                        // risky call
        std::cout << "Valid age entered ✔️\n";
    }
    catch (const char* msg) {                  // 🔥 catch custom type
        std::cout << "Error: " << msg << '\n';
    }

    std::cout << "Program continues...\n";
    return 0;
}
```

---

# ⚙️ Execution Flow

---

## 🟢 Case 1: Valid input

```text
Input: 25
```

```text
try → check_age(25)
→ no throw ✔️
→ normal output
```

👉 Output:

```text
Valid age entered ✔️
Program continues...
```

---

## 🔴 Case 2: Negative age

```text
Input: -5
```

```text
try → check_age(-5)
→ throw "Age cannot be negative"
→ try STOP ❗
→ catch match ✔️
```

👉 Output:

```text
Error: Age cannot be negative
Program continues...
```

---

## 🔴 Case 3: Too large age

```text
Input: 200
```

👉 Output:

```text
Error: Age seems unrealistic
Program continues...
```

---

# 🧠 Role Breakdown

---

## 🔹 `throw`

```cpp id="th1"
throw "Age cannot be negative";
```

👉 simple string error throw

---

## 🔹 `catch`

```cpp id="ct1"
catch (const char* msg)
```

👉 அந்த string message receive பண்ணும்

---

## 🔹 `msg`

```cpp id="msg1"
msg
```

👉 error message itself

---

# 🎯 Visual Flow

```text
try
 ↓
check_age()
 ↓
throw "message"
 ↓
catch(const char*)
 ↓
print message
```

---

# ⚠️ Important Insight

👉 இது **simple & beginner-friendly** ✔️
👉 ஆனால்:

❌ advanced projectsல usually use பண்ண மாட்டாங்க

👉 reason:

* no structured info
* no hierarchy
* no `what()`

---

# 🧠 Better (industry)

```cpp id="better1"
throw std::runtime_error("message");
```

👉 more powerful ✔️

---

# 💬 Simple Tamil Summary

👉 `throw "text"`:

* custom error message

👉 `catch (const char*)`:

* அந்த message handle பண்ணும்

---

# 🔥 One-line memory

👉

> “string throw simple, runtime_error professional”

---

# 🚀 If you want next

👉 custom class exception create பண்ணுவது
👉 runtime_error vs custom difference
👉 real-world error design

Just tell 👍

*/