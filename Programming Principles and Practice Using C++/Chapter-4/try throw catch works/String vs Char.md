## `throw` எப்படி `catch`-க்கு போகுது?

உன் question சரியானது — `"Age cannot be negative"` string மாதிரி தெரியுது, ஆனா actually அது `const char*`!

---

## Double Quotes = `const char*` in C++

```cpp
"Age cannot be negative"  // இது std::string இல்ல!
                          // இது const char* — character array
```

C++-ல double quotes போட்டா அது **string literal** — type is `const char*`.

```cpp
"hello"        // const char*  ✅
std::string s = "hello";  // இங்க explicitly string-ஆ convert பண்றோம்
```

---

## Memory-ல என்ன நடக்குது?

```
"Age cannot be negative"

Memory (Read-only segment):
[A][g][e][ ][c][a][n][n][o][t]...[\0]
 ↑
const char* — இந்த address-ஐ throw பண்றோம்
```

`throw` பண்றது value-ஐ இல்ல — **pointer-ஐ** (address-ஐ).

---

## throw → catch எப்படி Match ஆகுது?

```cpp
throw "Age cannot be negative";
//     ^^^^^^^^^^^^^^^^^^^^^^^^
//     type: const char*

catch (const char* msg) {
//     ^^^^^^^^^^^^^^
//     same type: const char* → MATCH!
```

Compiler **type-based matching** பண்ணும்:

```
throw type    ==    catch type    → catch பிடிக்கும்
const char*   ==    const char*   ✅
```

---

## Type Mismatch ஆனா என்ன ஆகும்?

```cpp
throw "hello";              // const char*

catch (std::string msg) {   // string — different type!
    // ❌ இங்க வராது!
}
catch (const char* msg) {   // const char* — match!
    // ✅ இங்க வரும்
}
```

---

## `std::string` throw பண்ணணும்னா?

```cpp
throw std::string("Age cannot be negative");  // explicit string

catch (const std::string& msg) {  // string catch
    std::cout << msg << '\n';
}
```

---

## Summary

| Literal | Type |
|---|---|
| `"hello"` | `const char*` |
| `std::string("hello")` | `std::string` |
| `42` | `int` |
| `3.14` | `double` |

**Simple rule:**

> `throw`-`catch` **type matching** மட்டும் பார்க்கும். `"text"` என்பது C++-ல `const char*` — so `catch(const char* msg)` match ஆகும். `std::string` இல்ல!