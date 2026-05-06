## `putback` எப்படி நடக்குது?

---

## `term()` code பாரு

```cpp
double term()
{
    double left = primary();  // '1' படிக்கும்

    Token t = ts.get();       // '+' படிக்கும்

    while (true) {
        switch (t.kind) {

        case '*':
            ...
        case '/':
            ...
        default:
            ts.putback(t);   // ← இங்க putback நடக்கும்
            return left;
        }
    }
}
```

---

## Step-by-Step

### 1. `ts.get()` — '+' படிக்கும்
```
cin: [+][2][)]

Token t = ts.get()
  full = false → cin-லிருந்து படிக்கும்
  ch = '+'
  return Token{'+', 0}

t.kind = '+'
cin: [2][)]    ← '+' போச்சு
```

### 2. `switch(t.kind)` — '+' match ஆகாது
```
case '*' ? No
case '/' ? No
default  → ts.putback(t) call!
```

### 3. `ts.putback(t)` உள்ளே என்ன நடக்கும்?
```cpp
void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");

    buffer = t;    // buffer.kind  = '+'
                   // buffer.value = 0
    full = true;   // "buffer-ல token இருக்கு"
}
```

```
Token_stream:
┌─────────────────────┐
│ buffer.kind  = '+'  │ ← save ஆச்சு
│ buffer.value = 0    │
│ full = true         │ ← flag set ஆச்சு
└─────────────────────┘
```

### 4. `term()` return பண்ணும்
```
return 1   ← '+' cin-ல இல்ல, buffer-ல இருக்கு
```

### 5. `expression()` `get()` call பண்ணும்
```cpp
Token Token_stream::get()
{
    if (full) {          // full = true!
        full = false;    // flag reset
        return buffer;   // '+' திரும்ப கொடு
    }
    // cin தொடவே மாட்டோம்!
}
```

```
Token_stream:
┌─────────────────────┐
│ buffer.kind  = '+'  │
│ full = false        │ ← reset ஆச்சு
└─────────────────────┘

return Token{'+', 0}  ← expression() கிட்ட போகும்
```

---

## Visual Summary

```
term():
  get()  → cin-லிருந்து '+' எடுக்கும்
  default → putback('+')
              buffer = '+'
              full = true
  return 1

expression():
  get()  → full=true! 
            buffer-லிருந்து '+' எடுக்கும்
            full = false
  case '+' → handle பண்ணும் ✅
```

---

**Simple rule:**

> `putback()` = buffer-ல save பண்ணி `full=true` போடும். Next `get()` call-ல `full=true` பார்க்கும் — cin தொடாம buffer-லிருந்து எடுக்கும். Token "போகலை, திரும்பி வந்துச்சு" மாதிரி!