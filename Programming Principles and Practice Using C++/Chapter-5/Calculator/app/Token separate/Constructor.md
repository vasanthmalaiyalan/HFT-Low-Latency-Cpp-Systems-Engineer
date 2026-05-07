## Constructor எப்படி Call ஆகும்?

---

## Object Create ஆகும்போது Auto Call!

```cpp
int main() {
    Token_stream ts;  // ← இந்த line-லயே constructor auto call!
}
```

Compiler இதை பார்க்கும்போது:

```
"Token_stream object create பண்றோம்
 → Token_stream() constructor இருக்கா? 
 → ஆமா இருக்கு → auto call பண்ணு!"
```

---

## என்ன நடக்கும்?

```
Token_stream ts;

Step 1: Stack-ல 'ts'-க்கு memory reserve
┌─────────────────────┐
│ full   = garbage ❌  │
│ buffer = garbage ❌  │
└─────────────────────┘

Step 2: Constructor auto call!
Token_stream() : full{false}, buffer{'0'} {}

Step 3: Initialize ஆகும்
┌─────────────────────┐
│ full   = false  ✅   │
│ buffer.kind='0' ✅   │
│ buffer.value=0  ✅   │
└─────────────────────┘
```

---

## Garbage ஏன் வரும்?

```cpp
// Constructor இல்லன்னா:
Token_stream ts;
// full = 1 or 0 (random!) ← garbage
// buffer = random chars   ← garbage

if (full) {         // full = garbage → unpredictable!
    return buffer;  // buffer = garbage → crash!
}
```

---

## Constructor போட்டா:

```cpp
Token_stream() : full{false}, buffer{'0'} {}
// full = false   → buffer empty, safe ✅
// buffer = '0'   → dummy safe value ✅
```

---

**Simple rule:**

> `Token_stream ts;` எழுதும்போதே compiler constructor auto call பண்ணும் — `ts` ready ஆகும் முன்னாடியே garbage clear ஆகும். Constructor இல்லன்னா garbage values → unpredictable behavior!