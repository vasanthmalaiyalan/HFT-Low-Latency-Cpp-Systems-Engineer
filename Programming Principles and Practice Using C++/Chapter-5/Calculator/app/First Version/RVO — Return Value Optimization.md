## RVO — Return Value Optimization

---

## Without RVO (Normal)

```
get() stack frame:
┌─────────────────────┐
│ temp Token          │  ← create
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
        ↓ copy
primary() stack frame:
┌─────────────────────┐
│ t                   │  ← copy ஆகும்
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
temp destroy ❌
```

**2 objects** — temp + t.

---

## With RVO (Compiler Optimization)

```
primary() stack frame:
┌─────────────────────┐
│ t                   │  ← இங்கயே directly create!
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
```

Compiler `get()`-க்கு சொல்லும்:

```
"temp object உன் stack-ல create பண்ணாத,
 directly caller-ஓட t address-ல create பண்ணு!"
```

---

## How Compiler Does It?

```cpp
// நீ எழுதுவது:
Token t = ts.get();

// Compiler generate பண்றது (roughly):
// get() function-க்கு t-ஓட address pass பண்ணும்
ts.get(&t);  // "இந்த address-ல directly போடு"

// get() உள்ளே:
// temp create பண்றதில்ல
// directly t-ல போடும்
```

---

## Simple Visual

```
Without RVO:
get()     → temp create → copy to t → temp destroy
[create]     [copy]         [destroy]   = 3 steps ❌

With RVO:
get()     → directly t-ல create
[create]                            = 1 step ✅
```

---

**Simple rule:**

> RVO = compiler "temp object வேண்டாம், directly caller-ஓட variable-ல create பண்ணிடு" என்று optimize பண்ணும். Copy-யே நடக்காது — faster, cleaner. C++17-ல இது **guaranteed**!


----------------

## RVO — Return Value Optimization

---

## Without RVO (Normal)

```
get() stack frame:
┌─────────────────────┐
│ temp Token          │  ← create
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
        ↓ copy
primary() stack frame:
┌─────────────────────┐
│ t                   │  ← copy ஆகும்
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
temp destroy ❌
```

**2 objects** — temp + t.

---

## With RVO (Compiler Optimization)

```
primary() stack frame:
┌─────────────────────┐
│ t                   │  ← இங்கயே directly create!
│ kind  = '8'         │
│ value = 3.14        │
└─────────────────────┘
```

Compiler `get()`-க்கு சொல்லும்:

```
"temp object உன் stack-ல create பண்ணாத,
 directly caller-ஓட t address-ல create பண்ணு!"
```

---

## How Compiler Does It?

```cpp
// நீ எழுதுவது:
Token t = ts.get();

// Compiler generate பண்றது (roughly):
// get() function-க்கு t-ஓட address pass பண்ணும்
ts.get(&t);  // "இந்த address-ல directly போடு"

// get() உள்ளே:
// temp create பண்றதில்ல
// directly t-ல போடும்
```

---

## Simple Visual

```
Without RVO:
get()     → temp create → copy to t → temp destroy
[create]     [copy]         [destroy]   = 3 steps ❌

With RVO:
get()     → directly t-ல create
[create]                            = 1 step ✅
```

---

**Simple rule:**

> RVO = compiler "temp object வேண்டாம், directly caller-ஓட variable-ல create பண்ணிடு" என்று optimize பண்ணும். Copy-யே நடக்காது — faster, cleaner. C++17-ல இது **guaranteed**!