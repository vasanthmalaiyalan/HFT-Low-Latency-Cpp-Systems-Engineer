# 2.1.8 Logical Operations in C

## Bitwise vs Logical — core difference

```
Bitwise: &  |  ~  ^   → bit-by-bit operation, returns any value
Logical: && || !       → treats whole value as true/false, returns 0 or 1
```

**Logical operators-ரோட rules:**
- Any **nonzero** value = **true**
- **0** = **false**
- Return value: **1** (true) or **0** (false) — always, nothing else

---

## Book-ரோட exact examples — ஒவ்வொண்ணும் trace பண்ணலாம்

```
Expression      Result    Why
─────────────────────────────────────────────────
!0x41           0x00      0x41 = nonzero = true  → !true  = false = 0
!0x00           0x01      0x00 = zero    = false → !false = true  = 1
!!0x41          0x01      0x41 = nonzero = true  → !true=0 → !0=1
0x69 && 0x55    0x01      0x69=nonzero=true,
                          0x55=nonzero=true → true&&true = 1
0x69 || 0x55    0x01      0x69=nonzero=true → true||anything = 1
```

**Bitwise-ஓட comparison:**

```c
// Logical:
!0x41   = 0x00    // 0x41 nonzero → true → !true = 0

// Bitwise:
~0x41   = 0xBE    // 0100 0001 → 1011 1110 — completely different!

// Logical:
0x69 && 0x55 = 0x01   // true && true = 1

// Bitwise:
0x69 & 0x55  = 0x41   // 0110 1001
                       // 0101 0101
                       // ─────────
                       // 0100 0001 = 0x41 — different!
```

Book சொல்றது: "bitwise operation will match logical counterpart **only** when arguments restricted to 0 or 1."

```c
// Only case they match:
0 & 0 = 0   ==  0 && 0 = 0  ✓
0 & 1 = 0   ==  0 && 1 = 0  ✓
1 & 1 = 1   ==  1 && 1 = 1  ✓
// But:
2 & 1 = 0   ≠   2 && 1 = 1  ✗  (2 = nonzero = true)
```

---

## Short-circuit evaluation — book-ரோட second important point

`&&` and `||` = second argument evaluate பண்றதில்லை — result already determined-ஆ இருந்தா.

**Book-ரோட exact examples:**

**Example 1: `a && 5/a`**

```c
int a = 0;
a && 5/a     // division by zero ஆகாது!

Evaluation:
  a = 0 → false
  false && anything = false → second part evaluate பண்றதே இல்ல!
  5/a never executed → no division by zero ✓

// But bitwise:
a & 5/a      // BOTH sides always evaluated
             // a=0 → 5/0 → crash!
```

**Example 2: `p && *p++`**

```c
int *p = NULL;
p && *p++    // null pointer dereference ஆகாது!

Evaluation:
  p = NULL = 0 → false
  false && anything = false → *p++ never executed!
  NULL dereference never happens ✓

// Common pattern in C:
if (p && *p > 0) { ... }
// p null-ஆ இருந்தா → second condition check பண்றதில்லை — safe!
```

**`||` short-circuit:**

```c
// false || x → x evaluate பண்றது (first = false, result depends on second)
// true  || x → x evaluate பண்றதில்லை (first = true → already true)

int x = 0;
(x = 5) || (x = 10);
// x = 5 → nonzero → true → second part skipped!
// x remains 5, not 10
```

---

## Summary table

```
Operator  Type      Input treated as    Returns
────────────────────────────────────────────────
&         bitwise   raw bits            any value
|         bitwise   raw bits            any value
~         bitwise   raw bits            any value
^         bitwise   raw bits            any value
&&        logical   nonzero=T, 0=F      0 or 1 only
||        logical   nonzero=T, 0=F      0 or 1 only
!         logical   nonzero=T, 0=F      0 or 1 only
```

அடுத்து 2.1.9 (Shift Operations in C) போகலாமா?