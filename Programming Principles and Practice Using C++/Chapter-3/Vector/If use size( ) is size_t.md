## `size_t` என்றால் என்ன?

`size_t` என்பது ஒரு **type alias** — அதாவது வேற ஒரு பெயரில் இருக்கற type-க்கு shortcut பெயர்.

```cpp
// உள்ளுக்குள்ள இப்படி define ஆகியிருக்கு:
typedef unsigned long int size_t;
```

So `size_t` == `unsigned long int` — same thing, வேற பெயர்.

---

## `size()` என்ன return பண்ணும்?

```cpp
numbers.size(); // இது size_t return பண்ணும்
```

`size()` function-ஓட return type **`size_t`** — negative size என்று concept-யே இல்ல, so unsigned மட்டும் போதும்.

---

## அதனால `size_t` use பண்ண வேண்டுமா?

**ஆமா — ஏன்னா types match ஆகணும்:**

```cpp
size_t i = 0;
i < numbers.size(); // size_t < size_t — same type, no warning ✅

int i = 0;
i < numbers.size(); // int < size_t — different types, warning ❌
```

Compiler compare பண்ணும்போது **இரண்டும் same type-ஆ இருக்கணும்** — அதுக்காக `size_t` use பண்றோம்.

---

## Memory-ல என்ன வித்தியாசம்?

| Type | Bits | Range |
|------|------|-------|
| `int` | 32-bit | -2,147,483,648 to +2,147,483,647 |
| `size_t` | 64-bit | 0 to 18,446,744,073,709,551,615 |

`size_t` 64-bit unsigned — memory address-ஐ hold பண்ண போதுமான size. அதனால container sizes-க்கு இதுவே standard.

---

**One line summary:**

> `size_t` = unsigned type, `size()` அதையே return பண்ணும், so loop variable-உம் `size_t` போட்டா types match ஆகும், warning வராது.

-------

## Sign-Compare Error — என்ன நடக்குது?

**பிரச்சனை என்னன்னா:**

`numbers.size()` return பண்றது `size_t` — இது **unsigned long int** (negative value வராது, always 0 or positive).

ஆனா உன் loop variable `i` — இது **int** (signed, negative போகலாம்).

Compiler கிட்ட இந்த இரண்டையும் compare பண்ண சொன்னா அது warn பண்ணும் — "ஏன்னா இந்த இரண்டும் different type, danger இருக்கு!"

உன்கிட்ட `-Werror` flag இருக்கு — அதனால warn = error ஆகிடுது.

---

**CPU level-ல என்ன ஆகும் (why it matters):**

`i` negative ஆனா, அதை unsigned-ஓட compare பண்ணும்போது அது **மிகவும் பெரிய positive number**-ஆ மாறிடும். Loop ஓடாத இடத்துல ஓடும் — memory crash ஆகலாம்.

---

## 3 Fix Options

**Option 1 — `size_t` use பண்ணு (best fix)**
```cpp
for (size_t i = 0; i < numbers.size(); ++i) {
```

**Option 2 — `size()`-ஐ int-ஆ cast பண்ணு**
```cpp
for (int i = 0; i < (int)numbers.size(); ++i) {
```

**Option 3 — Range-based loop (modern C++, மிகவும் clean)**
```cpp
for (int n : numbers) {
    std::cout << n << ' ';
}
```
Index-யே வேண்டாம், problem-யே இல்ல!

---

## Simple Rule

> Container-ஐ loop பண்ணும்போது index-க்கு **`size_t`** use பண்ணு, அல்லது **range-based for** use பண்ணு — `int` போடாத.

உன்னோட `-Wall -Wextra -Werror` flags மிகவும் strict — இது நல்லது. இந்த mistakes-ஐ runtime-ல கண்டுபிடிக்காம compile time-லயே catch பண்ணும்!