#include <iostream>
#include <stdexcept> // for runtime_error

// function 
double divide(int a, int b) { 

    if (b == 0) {
        throw std::runtime_error("Cannot divide by zero"); // throw
    }
    return (double)a / b;
}

int main() {

    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    try {
        double result = divide(x, y); // risky call
        std::cout << "Result = " << result << '\n';
    }

    catch (std::runtime_error& e) { // catch
        std::cout << "Error: " << e.what() << '\n';
    }

    std::cout << "Program continues......\n";
    return 0;
} 

/*
சரி 🔥 — இப்ப **try–throw–catch மூன்றும் எப்படி சேர்ந்து வேலை செய்கிறது** என்பதை ஒரு **clear, real example** கொண்டு பார்க்கலாம்.

---

# 💻 🧪 Best Example (.cpp)

👉 Scenario:
User இரண்டு number கொடுக்கிறார் → division செய்கிறோம்
👉 **0னால் divide பண்ணினா error throw**

```cpp id="full1"
#include <iostream>
#include <stdexcept>   // for runtime_error

// function
double divide(int a, int b)
{
    if (b == 0) {
        throw std::runtime_error("Cannot divide by zero"); // 🔥 throw
    }
    return (double)a / b;
}

int main()
{
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    try {
        double result = divide(x, y);   // risky call
        std::cout << "Result = " << result << '\n';
    }
    catch (std::runtime_error& e) {     // 🔥 catch
        std::cout << "Error: " << e.what() << '\n';
    }

    std::cout << "Program continues...\n";
    return 0;
}
```

---

# ⚙️ Execution Flow (Step-by-step)

## 🟢 Case 1: Normal input

```
Input: 10 2
```

👉 flow:

```text
try start
→ divide(10,2)
→ no error
→ result print
→ catch skip
```

👉 Output:

```
Result = 5
Program continues...
```

---

## 🔴 Case 2: Error input

```
Input: 10 0
```

👉 flow:

```text
try start
→ divide(10,0)
→ throw runtime_error ❗
→ try STOP
→ catch match ✔️
→ print error
→ continue program
```

👉 Output:

```
Error: Cannot divide by zero
Program continues...
```

---

# 🧠 Role Breakdown

---

## 🔹 `try`

```cpp
try {
    divide(x, y);
}
```

👉 risky code run பண்ணும்
👉 error வந்தா catchக்கு அனுப்பும்

---

## 🔹 `throw`

```cpp
throw std::runtime_error("Cannot divide by zero");
```

👉 error உருவாக்கும்
👉 normal flow stop

---

## 🔹 `catch`

```cpp
catch (std::runtime_error& e)
```

👉 error receive பண்ணும்
👉 handle பண்ணும்

---

# 🎯 Visual Flow

```text
try
 ↓
divide()
 ↓
throw ❗
 ↓
catch ✔️
 ↓
program continues
```

---

# ⚠️ Important Insight

👉 Without try-catch:

```cpp
divide(10,0);
```

👉 result:

```text
program crash ❌
```

---

# 💬 Simple Tamil Summary

👉 `try`:

* risky code

👉 `throw`:

* error signal

👉 `catch`:

* error handle

---

# 🔥 One-line memory

👉

> “try run பண்ணும், throw error அனுப்பும், catch அதை handle பண்ணும்”

---

# 🚀 If you want next

👉 file handling errors
👉 multiple catch advanced
👉 custom exception class

Just tell 👍


*/