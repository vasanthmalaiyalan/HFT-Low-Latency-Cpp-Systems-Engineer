## `std::exception` என்றால் என்ன?

---

## Exception — Base Class

C++-ல எல்லா standard errors-உம் `std::exception`-ஓட **children:**

```
std::exception          ← parent (base class)
    ├── std::runtime_error   ← runtime problems
    ├── std::logic_error     ← logic problems
    ├── std::bad_alloc       ← memory fail
    └── std::overflow_error  ← overflow
```

---

## இந்த Code-ல என்ன நடக்குது?

```cpp
void error(const std::string& msg)
{
    throw std::runtime_error(msg);  // ← இது throw ஆகுது
}
```

```cpp
catch (std::exception& e)  // ← இது catch பண்ணுது
{
    std::cerr << e.what() << '\n';  // error message print
}
```

`runtime_error` — `exception`-ஓட child, so **parent catch பண்ணும்!**

---

## ஏன் `std::exception&` — Parent Type?

```cpp
// இப்படி பண்ணலாம்:
catch (std::runtime_error& e) { }  // ஒரே type மட்டும்

// இப்படி பண்ணினா better:
catch (std::exception& e) { }      // எல்லா children-உம் catch ஆகும்!
```

```
throw runtime_error  ─────► catch (std::exception&) ✅
throw logic_error    ─────► catch (std::exception&) ✅
throw bad_alloc      ─────► catch (std::exception&) ✅
```

One catch — எல்லாத்தையும் பிடிக்கும்!

---

## `&` ஏன் போட்டோம்?

```cpp
catch (std::exception& e)  // reference
```

```
& இல்லன்னா → object copy ஆகும் — slow, info loss ஆகலாம்
& போட்டா  → original object reference — fast, info safe ✅
```

---

## `e.what()` என்ன செய்யும்?

```cpp
throw std::runtime_error("divide by zero");
//                        ^^^^^^^^^^^^^^^^
//                        இந்த message

catch (std::exception& e) {
    e.what();  // → "divide by zero" return பண்ணும்
}
```

`what()` = throw பண்ணும்போது போட்ட **error message return பண்ணும்.**

---

## `catch(...)` என்னன்னா?

```cpp
catch (std::exception& e) { }  // standard exceptions
catch (...) {                  // ← எந்த type-உம் catch ஆகும்!
    std::cerr << "Unknown exception\n";
}
```

`...` = wildcard — `int`, `char*`, custom class — எதை throw பண்ணினாலும் பிடிக்கும்.

---

**Simple rule:**

> `std::exception` = எல்லா standard errors-ஓட parent. அதை catch பண்ணினா children எல்லாம் பிடிபடும். `e.what()` throw பண்ணும்போது போட்ட message-ஐ தரும். `&` போடுவது reference — copy avoid பண்ண.