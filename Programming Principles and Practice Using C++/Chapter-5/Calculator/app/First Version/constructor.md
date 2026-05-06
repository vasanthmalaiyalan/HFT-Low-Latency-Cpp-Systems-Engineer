`இது என்ன வேலை செய்கிறது `public:
    Token_stream()
        : full{false}, buffer{'0'}
    {
    }``

    ## `Token_stream()` Constructor — என்ன செய்யும்?

---

## இது Constructor!

`Token_stream` object create ஆகும்போது **auto call** ஆகும்.

---

## Line-by-Line பாரு

```cpp
Token_stream()        // constructor — no parameters
    : full{false},    // full = false (buffer empty)
      buffer{'0'}     // buffer = dummy Token('0')
{
}                     // body empty
```

---

## ஏன் Initialize வேணும்?

### `full = false`
```
object create ஆகும்போது buffer empty-ஆ இருக்கணும்
full = false → "buffer-ல எதுவும் இல்ல" ✅

initialize இல்லன்னா:
full = garbage value ← true-ஆ இருந்தா bug! ❌
```

### `buffer{'0'}`
```
buffer = Token{'0', 0}  ← dummy value

initialize இல்லன்னா:
buffer = garbage ← undefined behavior! ❌
```

---

## Memory-ல என்ன நடக்கும்?

```
Token_stream ts; // global object create

Stack/Global:
┌─────────────────────────┐
│ full   = false          │ ← safe ✅
│ buffer.kind  = '0'      │ ← dummy ✅
│ buffer.value = 0        │ ← dummy ✅
└─────────────────────────┘
```

---

## `buffer{'0'}` — ஏன் `'0'`?

```cpp
Token buffer{'0'};
// Token constructor call:
Token(char k) : kind{k}, value{0} {}
// kind = '0', value = 0
```

`'0'` = dummy placeholder — `full=false` இருக்கும்வரை buffer use ஆகவே மாட்டாது. எந்த value போட்டாலும் பரவாயில்ல — `full` flag தான் control பண்ணும்.

---

**Simple rule:**

> Constructor = object create ஆகும்போது safe initial state செட் பண்ணும். `full=false` → buffer empty, `buffer{'0'}` → dummy safe value. Initialize இல்லன்னா garbage value → unpredictable behavior!