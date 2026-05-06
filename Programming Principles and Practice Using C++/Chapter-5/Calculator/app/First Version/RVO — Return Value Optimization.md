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

``return Token{'8', val} = invisible temp object create → t-க்கு copy → temp destroy. Modern compiler RVO மூலம் temp-யே skip பண்ணி directly t-ல create பண்ணும்.`அது எப்படி?`


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

--------

`return ஆகக்கூடிய இது வந்து `return Token{'8', val};` temp object கிரியேட் ஆகி கண்ணுக்கே தெரியாத object ஆக ரிட்டன் ஆகுமா  அப்படியாக கூடியது `double primary()
{
    Token t = ts.get();` t என்கின்ற object -க்கு assign ஆகுமா?`

 ## ஆமா! Exactly சரிதான்! 🎯

---

## என்ன நடக்குது?

```cpp
// Token_stream::get() உள்ளே:
return Token{'8', val};  // temp object create → return
```

```cpp
// primary() உள்ளே:
Token t = ts.get();      // temp object → t-க்கு copy
```

---

## Step-by-Step

### Step 1 — `get()` உள்ளே temp object create
```
Token{'8', 3.14}
┌─────────────────────┐
│ kind  = '8'         │  ← invisible temp object
│ value = 3.14        │
└─────────────────────┘
```

### Step 2 — return ஆகும்
```
temp object → caller-க்கு போகும்
```

### Step 3 — `t`-க்கு assign ஆகும்
```cpp
Token t = ts.get();
┌─────────────────────┐
│ kind  = '8'         │  ← t object (stack-ல)
│ value = 3.14        │
└─────────────────────┘
temp object → destroy ❌
```

---

## Modern C++ — RVO (Return Value Optimization)

Actually compiler இன்னும் smart-ஆ பண்ணும்:

```
Temp object create-யே பண்றதில்ல!
directly t-ல உள்ளே create பண்ணும் ✅
copy-யே நடக்காது — faster!
```

---

**Simple rule:**

> `return Token{'8', val}` = invisible temp object create → `t`-க்கு copy → temp destroy. Modern compiler RVO மூலம் temp-யே skip பண்ணி directly `t`-ல create பண்ணும்.   