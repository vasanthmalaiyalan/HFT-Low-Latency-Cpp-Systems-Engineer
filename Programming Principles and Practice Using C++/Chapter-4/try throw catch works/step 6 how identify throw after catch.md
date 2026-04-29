அடிச்சி கேள்வி 🔥 — “throw ஆனதும் எப்படி **இந்த catch தான் handle பண்ணணும்** என்று systemக்கு தெரியும்?”

இதுக்கு short answer:
👉 **compiler முன்பே தகவல் (metadata) சேமிச்சிருக்கும்**
👉 runtime அதைப் பார்த்து **matching catch-ஐ தேடி jump ஆகும்**

இதை step-by-step பார்ப்போம் 👇

---

# 🧠 1. Compile நேரத்தில் என்ன நடக்கும்?

நீ எழுதுற code:

```cpp
try {
    func1();
}
catch (std::runtime_error& e) {
    ...
}
```

👉 Compiler இதை **simple if-else ஆக மாற்றாது** ❌
👉 அது instead:

```text
“exception table” + “type info” உருவாக்கும்
```

---

## 📦 Exception Table (concept)

```text
main()
 ├─ try block range (start → end)
 ├─ catch type: runtime_error
 └─ handler location (catch block address)
```

👉 இதை **binaryல embed பண்ணி வைச்சிருக்கும்**

---

# ⚙️ 2. Runtimeல் என்ன நடக்கும்?

## 🔴 Step 1: throw

```cpp
throw std::runtime_error("Error");
```

👉 runtime call:

```text
__cxa_throw(exception_object, type_info)
```

👉 இதில்:

* exception object
* அதன் type (`runtime_error`)

---

## 🔍 Step 2: Search starts

👉 runtime system:

```text
“யாராவது இந்த error-ஐ catch பண்ணுவாங்களா?”
```

---

👉 அது stackல இருந்து மேலே search பண்ணும்:

```text
func2 → func1 → main
```

---

# 🧠 3. எப்படி match பண்ணுது?

👉 runtime check:

```text
throw type == catch type ?
```

---

## Example:

```cpp
throw std::runtime_error("error");
```

---

```cpp
catch (std::runtime_error& e)
```

👉 match ✔️

---

👉 internally:

```text
typeid(runtime_error) == typeid(runtime_error)
```

---

# ⚠️ 4. Match இல்லனா?

```cpp
catch (int e)  // ❌
```

👉 skip பண்ணும்

---

👉 next catch தேடும்:

```cpp
catch (...)  // ✔️ fallback
```

---

# 🔥 5. Stack Unwinding + Matching Together

```text
func2 → throw
   ↓
func2 remove
   ↓
func1 remove
   ↓
main → check catch
   ↓
match found ✔️
   ↓
execute catch
```

---

# 🎯 6. முக்கிய Insight

👉 இது **compiler + runtime collaboration**:

---

## 🟢 Compiler:

* try block range தெரியும்
* catch types தெரியும்
* metadata உருவாக்கும்

---

## 🟢 Runtime:

* throw நடந்ததும்
* stack scan பண்ணும்
* matching catch கண்டுபிடிக்கும்

---

# 💻 7. Small Demo (Different cases)

```cpp
try {
    throw std::runtime_error("error");
}
catch (int e) {
    std::cout << "int\n";
}
catch (std::runtime_error& e) {
    std::cout << "runtime_error\n";
}
```

👉 Output:

```text
runtime_error
```

---

# 💬 Simple Tamil Summary

👉 throw ஆனதும்:

* runtime stack மேலே போய்
* catch blocks check பண்ணும்
* type match ஆனதும் stop

---

# 🔥 One-line truth

👉

> “Throw searches upward until it finds matching catch”

---

# 🚀 Next Level (if you want 🔥)

👉 நான் explain பண்ணலாம்:

* type matching எப்படி inheritanceல வேலை செய்கிறது
* catch order importance
* `catch(...)` danger

Just tell 👍
