# எனக்கு புரியல unsignedஎன்பது only positive தானே? அதே மாதிரி signed என்பது both positive and negative தானே அப்படி இருக்கும்போது unsigned-க்கு நீ 0 add செய்கிறாய்?

நல்ல question Jarvis! புரிஞ்சுக்க easy-ஆ explain பண்றேன்.

---

## Unsigned vs Signed — basic idea

```
unsigned char:  0 to 255        (only positive + zero)
signed char:  -128 to 127       (negative + zero + positive)
```

உன் confusion: "unsigned-க்கு ஏன் 0 fill பண்றோம்?"

---

## இது sign-ஓட connection இல்ல — இது space-ரோட question!

Right shift பண்ணும்போது left-ல bits "காலி" ஆகுது. அந்த காலி இடத்துல என்ன போடுறது?

```
Original 8 bits:  1 0 0 1 0 1 0 1
                  ↑
                  இந்த bit shift-ஆகி போகுது

>> 1 shift பண்ண:
  ? 1 0 0 1 0 1 0
  ↑
  இந்த இடம் காலி — என்ன போடுவது?
```

**Two choices:**
- **0 போடு** → logical shift
- **MSB copy பண்ணு** → arithmetic shift

---

## ஏன் unsigned = always 0 fill?

```c
unsigned char x = 0x95;  // 10010101 = 149

x >> 1:
  0 1 0 0 1 0 1 0  = 74

149 / 2 = 74.5 → integer = 74 ✓

// 0 fill பண்ணதால correct answer வந்தது!
```

Unsigned number-க்கு MSB = value-ரோட part (sign இல்ல). அதை copy பண்ணா wrong answer வரும்:

```c
// MSB copy பண்ணினா (wrong for unsigned):
unsigned char x = 0x95;  // 10010101 = 149
// MSB = 1, so fill with 1:
  1 1 0 0 1 0 1 0  = 202  ← wrong! 149/2 ≠ 202
```

---

## ஏன் signed = MSB fill?

```c
signed char x = 0x95;  // 10010101 = -107

// Signed-ல MSB = sign bit
// MSB = 1 → negative number

x >> 1:
  1 1 0 0 1 0 1 0  = -54

-107 / 2 = -53.5 → integer = -54 ✓

// MSB(1) copy பண்ணதால correct answer வந்தது!
// Sign preserve ஆச்சு — still negative
```

MSB copy பண்ணாம 0 fill பண்ணினா:

```c
// 0 fill பண்ணினா (wrong for negative signed):
  0 1 0 0 1 0 1 0  = +74  ← wrong! -107/2 ≠ +74
// Negative → Positive ஆகிவிட்டது — sign lost!
```

---

## Simple summary

```
Unsigned >> k:
  MSB = value bit (sign இல்ல)
  0 fill → correct division by 2^k

Signed >> k:
  MSB = sign bit (1=negative, 0=positive)
  MSB copy → sign preserve → correct division by 2^k

Rule:
  Positive signed (MSB=0) → 0 fill = MSB copy → same result
  Negative signed (MSB=1) → 1 fill (MSB copy) → sign preserved
  Unsigned (MSB=1 possible) → 0 fill always → correct
```

புரிஞ்சுதா Jarvis?

# இப்ப Unsigned புரிஞ்சது , ஆனா இது மட்டும் புரியவில்லை `signed char x = 0x95;  // 10010101 = -107`எதன் அடிப்படையில் -107 வந்தது like minus? அப்புறம் இது புரியவில்லை `Signed-ல MSB = sign bit
// MSB = 1 → negative number` 1 என்பது பாஸிட்டிவ் நம்பர் தானே அது எப்படி நெகட்டிவ்?

நல்ல question Jarvis! இது Two's complement concept — இதை புரிஞ்சுக்கணும்.

---

## முதல்ல — ஏன் MSB=1 → negative?

Computer-ல negative numbers store பண்ண ஒரு convention decide பண்ணாங்க: **MSB = sign bit.**

```
8-bit signed char:
  MSB = 0 → positive number  (0xxxxxxx)
  MSB = 1 → negative number  (1xxxxxxx)

இது just a rule — hardware இப்படி interpret பண்றது.
```

"1 is positive" — அது decimal-ல. Binary representation-ல MSB-ரோட role different.

---

## 0x95 = -107 எப்படி?

**Two's complement** method — signed numbers இப்படி store ஆகும்.

```
0x95 = 1001 0101

MSB = 1 → negative number என்று தெரியுது.
Value என்ன என்று கண்டுபிடிக்க:
```

**Step 1:** எல்லா bits-ஐயும் flip பண்ணு (NOT):

```
1001 0101
↓ flip
0110 1010
```

**Step 2:** 1 add பண்ணு:

```
0110 1010
+        1
─────────
0110 1011  =  107
```

**Step 3:** MSB=1 இருந்தது → negative:

```
Result = -107
```

**Verify:** `0x95 = -107` ✓

---

## ஏன் இந்த மாதிரி complex system?

Simple-ஆ MSB=sign மட்டும் வச்சிருந்தா problem வரும்:

```
Simple sign-magnitude (naive approach):
  0000 0001 = +1
  1000 0001 = -1

Problem:
  +1 + (-1) = ?
  0000 0001
+ 1000 0001
───────────
  1000 0010 = -2  ← WRONG! Should be 0!
```

Two's complement-ல:

```
  0000 0001  = +1
  1111 1111  = -1  (two's complement of 1)

  0000 0001
+ 1111 1111
───────────
1 0000 0000  → overflow bit drop → 0000 0000 = 0 ✓
```

Addition automatic-ஆ work ஆகுது — extra hardware வேண்டாம்!

---

## Full 8-bit signed range

```
Binary      Unsigned    Signed
─────────────────────────────
0000 0000      0           0
0000 0001      1          +1
0000 0010      2          +2
...
0111 1110    126        +126
0111 1111    127        +127   ← max positive
────────────────────────────── (MSB flips here)
1000 0000    128        -128   ← most negative
1000 0001    129        -127
...
1111 1110    254          -2
1111 1111    255          -1
```

Same bits, different interpretation:
- Unsigned: `1000 0000` = 128
- Signed:   `1000 0000` = -128

---

## Quick two's complement trick

Negative number-ரோட two's complement கண்டுபிடிக்க:

```
+107 = 0110 1011

Step 1: flip all bits
        1001 0100

Step 2: add 1
        1001 0101 = 0x95 = -107 ✓
```

அல்லது formula:

```
signed value = -(MSB × 2^(w-1)) + rest of bits

0x95 = 1001 0101
     = -(1 × 2^7) + (0×64 + 0×32 + 1×16 + 0×8 + 1×4 + 0×2 + 1×1)
     = -128 + (16 + 4 + 1)
     = -128 + 21
     = -107 ✓
```

இப்ப புரிஞ்சுதா Jarvis? Two's complement-ஐ 2.2-ல book deep-ஆ cover பண்ணும்.

# MSB அப்படின்னா என்ன? நாம left, right,shift பத்தி தானே பேசிக் கொண்டிருந்தோம் `flip`எங்கிருந்து வந்தது

சரி Jarvis! Basic-லிருந்து clear-ஆ போகிறேன்.

---

## MSB என்னது?

MSB = **Most Significant Bit** = leftmost bit.

```
8-bit number: 1 0 0 1 0 1 0 1
              ↑               ↑
             MSB             LSB
        (Most Significant)  (Least Significant)
        (leftmost bit)      (rightmost bit)
```

"Most significant" ஏன்னா — அந்த bit-ரோட value மிகவும் பெரிசு:

```
1 0 0 1 0 1 0 1
↑
இந்த bit = 2^7 = 128  ← மிகவும் பெரிய value

              ↑
         இந்த bit = 2^0 = 1  ← மிகவும் சிறிய value
```

---

## Flip எங்கிருந்து வந்தது?

Shift topic-லிருந்து வரவில்லை. உன் question "0x95 = -107 எப்படி?" னு கேட்டதால் நான் Two's complement explain பண்ண போனேன் — அது different topic.

```
Shift    → bits-ஐ left/right move பண்றது
Flip     → Two's complement-ல negative number கண்டுபிடிக்க
           (இது 2.2 chapter topic)
```

இப்ப நாம் shift-லேயே இருக்கோம் — shift-க்கு flip தேவையில்லை.

---

## Shift-க்கு திரும்பி வரலாம்

Shift-ல MSB matter ஆகுறது ஒரே ஒரு இடத்துல மட்டும்:

```
Right shift பண்ணும்போது left-ல காலி இடம் வருது.
அந்த காலி இடத்துல என்ன போடுவது?

unsigned → 0 போடு (logical shift)
signed   → MSB-ஓட value copy பண்ணு (arithmetic shift)
```

```
unsigned: 1001 0101 >> 1
          0 1001 010  ← 0 fill
        = 0100 1010

signed:   1001 0101 >> 1
          1 1001 010  ← MSB(1) copy
        = 1100 1010
```

---

## Two's complement — separate topic

`0x95 = -107` புரிஞ்சுக்க Two's complement தெரியணும் — அது 2.2 section-ல book explain பண்ணும். அப்போ flip concept properly வரும், இப்போ skip பண்ணலாம்.

இப்போ shift மட்டும் clear-ஆச்சா?


------------------

சரி Jarvis! Step by step, very basic-லிருந்து போகிறேன்.

---

## முதல்ல — Unsigned என்றால் என்ன?

Unsigned = **only positive numbers + zero**.

```
8 bits இருந்தால்:
Unsigned range: 0 to 255

1001 0101 = ?

= 1×2^7 + 0×2^6 + 0×2^5 + 1×2^4 + 0×2^3 + 1×2^2 + 0×2^1 + 1×2^0
= 128   +   0   +   0   +  16   +   0   +   4   +   0   +   1
= 149

Simple! எல்லா bits-உம் value மட்டும்.
Minus இல்லவே இல்ல.
```

---

## Unsigned >> 1 — ஏன் 0 fill?

```
149 >> 1 = 149 ÷ 2 = 74 (integer division)

149 = 1001 0101
       ↓
>> 1:  ? 1001 010   ← left-ல ஒரு இடம் காலி

காலி இடத்துல என்ன போடுவது?
```

**0 போட்டால்:**

```
0 1001 010 = 0100 1010

= 0×128 + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= 0 + 64 + 0 + 0 + 8 + 0 + 2 + 0
= 74 ✓

149 ÷ 2 = 74 — correct!
```

**1 போட்டால்:**

```
1 1001 010 = 1100 1010

= 1×128 + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= 128 + 64 + 0 + 0 + 8 + 0 + 2 + 0
= 202 ✗

149 ÷ 2 ≠ 202 — wrong!
```

**Conclusion:** Unsigned-ல left-ல 0 fill பண்ணினால் மட்டுமே division correct-ஆ வருது.

---

## இப்போ Signed — இங்கே minus எங்கிருந்து வருது?

Signed-ல computer **MSB-ஐ special-ஆ treat பண்றது:**

```
8-bit signed:
MSB = 0 → positive → normal calculate பண்ணு
MSB = 1 → negative → value-ஐ differently calculate பண்ணு
```

**MSB = 0 example:**

```
0100 1010
↑
MSB = 0 → positive

= 0×(-128) + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= 0        + 64   + 0    + 0    + 8   + 0   + 2   + 0
= +74
```

**MSB = 1 example:**

```
1100 1010
↑
MSB = 1 → negative

MSB-ரோட weight = -128 (negative! இதுதான் minus-ரோட source)

= 1×(-128) + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= -128      + 64   + 0    + 0    + 8   + 0   + 2   + 0
= -128 + 74
= -54
```

**Key point:** MSB-ரோட weight = **-128** (signed-ல). அதனால MSB=1 → negative number வருது.

---

## இப்போ signed >> 1 — ஏன் MSB copy?

```
signed char x = 1001 0101
                ↑
                MSB = 1, weight = -128

Value = -128 + 0 + 0 + 16 + 0 + 4 + 0 + 1 = -107
```

**>> 1 பண்ணினால் = -107 ÷ 2 = -54 வரணும்.**

**MSB copy (1 fill) பண்ணினால்:**

```
1001 0101 >> 1:
1 100 1010 = 1100 1010
↑
MSB copy (1)

= 1×(-128) + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= -128 + 64 + 8 + 2
= -128 + 74
= -54 ✓

-107 ÷ 2 = -54 — correct!
```

**0 fill பண்ணினால்:**

```
1001 0101 >> 1:
0 100 1010 = 0100 1010
↑
0 fill

= 0×(-128) + 1×64 + 0×32 + 0×16 + 1×8 + 0×4 + 1×2 + 0×1
= 0 + 64 + 8 + 2
= +74 ✗

-107 ÷ 2 ≠ +74 — wrong! Negative → Positive ஆகிவிட்டது!
```

---

## Final summary — simple-ஆ

```
Unsigned:
  MSB = just a value bit (no special meaning)
  >> shift → 0 fill → correct division

Signed:
  MSB = special bit, weight = -128 (negative!)
  MSB=1 → number negative
  >> shift → MSB copy →
     negative stay negative → correct division
  >> shift → 0 fill →
     negative become positive → WRONG!
```

இப்ப புரிஞ்சுதா Jarvis?

# why this ` LEFT SHIFT = multiply by 2`,`RIGHT SHIFT = divide by 2 `

நல்ல question! Basic-லிருந்து போகிறேன்.

---

## முதல்ல decimal-ல பாரு

Decimal-ல ஒரு number-ஐ 10-ஆல் multiply பண்ண என்ன பண்றோம்?

```
23 × 10 = 230   ← right-ல 0 add பண்றோம்
230 × 10 = 2300 ← right-ல 0 add பண்றோம்
```

**Right-ல 0 add = ×10** — ஏன்னா decimal = base 10.

---

## Binary-ல same logic

Binary = base 2. அதனால:

```
Right-ல 0 add = × 2
```

```
0000 0011 = 3
          ↓ right-ல 0 add (= left shift)
0000 0110 = 6   ← 3 × 2 ✓
          ↓ right-ல 0 add again
0000 1100 = 12  ← 6 × 2 ✓
          ↓ right-ல 0 add again
0001 1000 = 24  ← 12 × 2 ✓
```

Left shift = right side-ல 0 add = × 2.

---

## ஏன் mathematically சரி?

```
Binary number value:

0000 0011 = 1×2^1 + 1×2^0
          = 2 + 1
          = 3

Left shift 1:
0000 0110 = 1×2^2 + 1×2^1
          = 4 + 2
          = 6

என்ன ஆச்சு?
  2^1 → 2^2  (power +1)
  2^0 → 2^1  (power +1)

Every bit-ரோட power 1 கூடுது = × 2!
```

---

## Right shift = ÷ 2 — same logic

```
Right shift = left side-ல bit add, right-லிருந்து bit drop

0001 1000 = 24
          ↓ right shift 1
0000 1100 = 12  ← 24 ÷ 2 ✓

என்ன ஆச்சு?
  2^4 → 2^3  (power -1)
  2^3 → 2^2  (power -1)

Every bit-ரோட power 1 குறையுது = ÷ 2!
```

---

## Decimal analogy-ஓட compare

```
Decimal (base 10):
  23 → 230   = right-ல 0 add = × 10
  230 → 23   = right-ல 0 remove = ÷ 10

Binary (base 2):
  011 → 110  = right-ல 0 add = × 2  (left shift)
  110 → 011  = right-ல bit remove = ÷ 2  (right shift)

Base மாறினாலும் same pattern!
```

---

## Simple proof with code

```c
#include <stdio.h>

int main() {
    int x = 1;

    printf("=== LEFT SHIFT = × 2 ===\n");
    printf("x      = %d\n", x);        // 1
    printf("x << 1 = %d\n", x << 1);  // 2  = 1×2
    printf("x << 2 = %d\n", x << 2);  // 4  = 1×4
    printf("x << 3 = %d\n", x << 3);  // 8  = 1×8
    printf("x << 4 = %d\n", x << 4);  // 16 = 1×16
    printf("x << 5 = %d\n", x << 5);  // 32 = 1×32

    printf("\n=== RIGHT SHIFT = ÷ 2 ===\n");
    int y = 32;
    printf("y      = %d\n", y);        // 32
    printf("y >> 1 = %d\n", y >> 1);  // 16 = 32÷2
    printf("y >> 2 = %d\n", y >> 2);  // 8  = 32÷4
    printf("y >> 3 = %d\n", y >> 3);  // 4  = 32÷8
    printf("y >> 4 = %d\n", y >> 4);  // 2  = 32÷16
    printf("y >> 5 = %d\n", y >> 5);  // 1  = 32÷32

    printf("\n=== k times shift = 2^k ===\n");
    printf("x << 1 = x × 2^1 = x × %d\n", 1<<1);   // 2
    printf("x << 2 = x × 2^2 = x × %d\n", 1<<2);   // 4
    printf("x << 3 = x × 2^3 = x × %d\n", 1<<3);   // 8
    printf("x << 4 = x × 2^4 = x × %d\n", 1<<4);   // 16

    return 0;
}
```

**Output:**

```
=== LEFT SHIFT = × 2 ===
x      = 1
x << 1 = 2   = 1 × 2^1
x << 2 = 4   = 1 × 2^2
x << 3 = 8   = 1 × 2^3
x << 4 = 16  = 1 × 2^4
x << 5 = 32  = 1 × 2^5

=== RIGHT SHIFT = ÷ 2 ===
y      = 32
y >> 1 = 16  = 32 ÷ 2^1
y >> 2 = 8   = 32 ÷ 2^2
y >> 3 = 4   = 32 ÷ 2^3
y >> 4 = 2   = 32 ÷ 2^4
y >> 5 = 1   = 32 ÷ 2^5

=== k times shift = 2^k ===
x << 1 = x × 2^1 = x × 2
x << 2 = x × 2^2 = x × 4
x << 3 = x × 2^3 = x × 8
x << 4 = x × 2^4 = x × 16
```

---

## One line summary

```
Decimal: right-ல 0 add = ×10  (base 10)
Binary:  right-ல 0 add = ×2   (base 2)

Left shift  = right-ல 0 add    = ×2
Right shift = right-லிருந்து drop = ÷2
```

புரிஞ்சுதா Jarvis?