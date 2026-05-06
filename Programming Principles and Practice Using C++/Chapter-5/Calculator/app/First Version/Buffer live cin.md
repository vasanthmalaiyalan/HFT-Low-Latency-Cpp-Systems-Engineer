## ஆமா! Exactly!

---

## `while(std::cin)` — ஒரே ஒரு Check மட்டும்

```
cin உயிரோட இருக்கா? (live?)
    ✅ Yes → loop தொடரும்
    ❌ No  → loop நிக்கும்
```

---

## எப்போ "Dead" ஆகும்?

```
Ctrl+D    → EOF → cin dead ❌
Bad read  → fail → cin dead ❌
```

---

## எப்போ "Live" ஆகும்?

```
Normal input → cin live ✅
எதுவும் type பண்ணல → cin live ✅ (wait பண்ணும்)
```

---

## Read பண்றதில்ல — Just Check

```cpp
while(std::cin) {          // live? check மட்டும்
    expression();          // actual read இங்க நடக்கும்
}
```

---

**Simple rule:**

> `while(std::cin)` = "cin உயிரோட இருக்கா?" — அவ்வளவுதான். Read பண்றதில்ல, buffer தொடறதில்ல. EOF or error வந்தா dead — loop நிக்கும்.