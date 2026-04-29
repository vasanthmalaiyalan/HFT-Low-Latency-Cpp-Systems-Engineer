சூப்பர் 🔥 — இது தான் exception handlingல **core usage point**.

நீ கேட்டது மூன்று விஷயம்:

* `e` என்ன?
* `what()` என்ன?
* `e.what()` என்ன செய்கிறது?

நாம் clearஆ பார்ப்போம் 👇

---

# 🧠 1. `e` என்ன?

```cpp
catch (std::runtime_error& e)
```

👉 `e` என்பது:

```text
throw செய்யப்பட்ட exception object-க்கு ஒரு பெயர் (variable)
```

---

## Example:

```cpp
throw std::runtime_error("Error happened");
```

👉 இதுல:

```text
runtime_error object உருவாகும்
```

👉 அதை catch பண்ணும்போது:

```cpp
catch (std::runtime_error& e)
```

👉 அந்த object → `e` variableக்கு assign ஆகும் ✔️

---

## Simple analogy:

```text
throw → parcel அனுப்பு 📦
catch → parcel receive பண்ணுறது
e → parcel content
```

---

# 🧠 2. `what()` என்ன?

👉 இது `std::runtime_error` classல இருக்கும் function

---

## Definition (conceptually)

```cpp
class runtime_error {
public:
    const char* what() const noexcept;
};
```

👉 meaning:

```text
error message return பண்ணும் function
```

---

# 🧠 3. `e.what()` என்ன?

👉 இது:

```text
exception object-ல இருக்கும் error message-ஐ retrieve பண்ணும்
```

---

## Example:

```cpp
throw std::runtime_error("Invalid input");
```

👉 inside:

```text
message = "Invalid input"
```

---

👉 catch:

```cpp
catch (std::runtime_error& e)
```

---

👉 call:

```cpp
e.what()
```

👉 returns:

```text
"Invalid input"
```

---

# 💻 Full Example

```cpp
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        throw std::runtime_error("Something went wrong");
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}
```

---

## Output:

```text
Error: Something went wrong
```

---

# 🔍 Breakdown

```cpp
e        → exception object
e.what() → அந்த objectல உள்ள message
```

---

# ⚠️ Why `& e` (reference)?

```cpp
catch (std::runtime_error& e)
```

👉 காரணம்:

* copy avoid பண்ண
* original object use பண்ண

👉 best practice ✔️

---

# 🧠 4. Internal idea

👉 `runtime_error` object:

```cpp
runtime_error obj("Error happened");
```

👉 inside:

```text
msg = "Error happened"
```

👉 `what()`:

```cpp
return msg.c_str();
```

---

# 💬 Simple Tamil Summary

👉 `e`:

* error object

👉 `what()`:

* error message function

👉 `e.what()`:

* அந்த error message return பண்ணும்

---

# 🎯 One-line memory

👉

> “e = error object, what() = அதன் message”

---

# 🔥 Final Insight

👉 Without `what()`:

```cpp
catch (...) {
    std::cout << "Error";
}
```

👉 With `what()`:

```cpp
Error: Invalid input  ✔️ clear
```

---

# 🚀 If you want next

👉 custom exception class எப்படி எழுதுவது
👉 `std::exception` hierarchy
👉 real-world error design

Just tell 👍
