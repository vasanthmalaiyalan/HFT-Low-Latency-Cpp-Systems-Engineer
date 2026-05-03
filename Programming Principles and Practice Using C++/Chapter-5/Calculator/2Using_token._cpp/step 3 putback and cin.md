சூப்பர் — நீ இப்ப கேக்குறது **I/O stream internals** 🔥
“putback actually உள்ளே என்ன நடக்குது?” — இதை clearஆ explain பண்ணுறேன்.

---

# 🧠 1. First: cin எப்படி வேலை செய்கிறது?

👉 `std::cin` நேராக keyboard-ல இருந்து படிக்காது
👉 அது ஒரு **buffer (memory)** use பண்ணும்

---

## 🟢 Example buffer

Input:

```text
12.5+3
```

👉 memory (buffer):

```text
[ '1' ][ '2' ][ '.' ][ '5' ][ '+' ][ '3' ]
   ↑
 read pointer
```

👉 pointer = “next read position”

---

# 🟢 2. `std::cin >> ch`

```cpp
char ch;
std::cin >> ch;
```

👉 என்ன நடக்கும்?

```text
ch = '1'
pointer → next இடம் move ஆகும்
```

---

## 🧠 Buffer now:

```text
[ '1' ][ '2' ][ '.' ][ '5' ][ '+' ][ '3' ]
          ↑
       pointer
```

👉 `'1'` read ஆகி pointer முன்னேறி இருக்கு

---

# 🔥 3. Now `putback(ch)`

```cpp
std::cin.putback(ch);
```

👉 இது என்ன செய்கிறது?

👉 pointer-ஐ **ஒரு step பின்னால் move பண்ணும்**

---

## 🧠 Buffer after putback:

```text
[ '1' ][ '2' ][ '.' ][ '5' ][ '+' ][ '3' ]
   ↑
pointer
```

👉 மீண்டும் `'1'` read செய்ய ready ✔️

---

# 🧠 IMPORTANT

👉 putback:

```text
character change பண்ணாது ❌
pointer மட்டும் move பண்ணும் ✔️
```

---

# 🟢 4. Why pass `ch` then?

👉 `putback(ch)`ல `ch` use பண்ணுவது:

✔️ safety check

👉 compiler check பண்ணும்:

```text
“நீ திருப்பி வைக்குற character sameதானா?”
```

---

# ⚠️ If mismatch

```cpp
std::cin.putback('X'); // wrong
```

👉 stream error ஆகலாம் ❌

---

# 🟢 5. Now next step

```cpp
std::cin >> val;
```

👉 pointer மீண்டும் `'1'`ல இருக்கிறது

👉 so:

```text
val = 12.5 ✔️
```

---

# 🧪 Without putback

```text
pointer already at '2'
```

👉 so:

```text
val = 2.5 ❌
```

---

# 🔥 6. Internal (low-level idea)

👉 cin uses something like:

```text
buffer + read pointer
```

👉 putback does:

```text
pointer--
```

---

# 🧠 Visualization (clear)

## Before read:

```text
1  2  .  5  +  3
↑
```

## After read `'1'`:

```text
1  2  .  5  +  3
   ↑
```

## After putback:

```text
1  2  .  5  +  3
↑
```

---

# 🟢 7. Important rules

👉 putback:

✔️ only one character safe
✔️ works only if buffer supports it

---

# 🟢 8. Related functions

```cpp
std::cin.get()       // read one char
std::cin.putback()   // undo one char
std::cin.unget()     // move pointer back (no check)
```

---

# 💬 Simple Tamil Summary

👉 `putback(ch)`:

* read பண்ணிய character-ஐ மீண்டும் unread ஆக்குது
* pointer-ஐ பின்னால் move பண்ணுது
* buffer change ஆகாது

---

# 🎯 Final Answer

```text
putback = input stream read pointer-ஐ ஒரு இடம் பின்னால் move பண்ணுவது
```

---

# 🚀 One-line

```text
putback = undo last read (pointer rewind)
```

---

If you want next 🔥

👉 cin buffer full internal structure
👉 file streams எப்படி வேலை செய்கிறது
👉 unget vs putback difference deep

Just tell 👍
