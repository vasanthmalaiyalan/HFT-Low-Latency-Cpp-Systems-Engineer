ஒவ்வொன்னா deep-ஆ பார்க்கலாம்!

---

## 1️⃣ Stack vs Heap — என்ன வித்தியாசம்?

```
RAM Layout:
┌─────────────────────────┐ High address
│      OS / Kernel        │
├─────────────────────────┤
│                         │
│   Stack  ↓ கீழே வளரும் │ ← automatic, fast
│   ┌─────────────────┐   │
│   │ function frames │   │
│   │ local variables │   │
│   │ return address  │   │
│   └─────────────────┘   │
│         (empty)         │
│   ┌─────────────────┐   │
│   │ malloc() memory │   │
│   │ dynamic data    │   │
│   └─────────────────┘   │
│   Heap   ↑ மேலே வளரும் │ ← manual, flexible
├─────────────────────────┤
│   .rodata               │ ← "Hello, World!" இங்கே
│   .data                 │ ← global variables
│   .text (code)          │ ← assembly instructions
└─────────────────────────┘ Low address
```

---

## Stack என்றால்:

```c
void main() {
    int x = 10;        // Stack-ல் போகும்
    char name[20];     // Stack-ல் போகும்
}
// function முடிந்தால் → automatic-ஆ free!
```

**யார் manage பண்றது?** CPU தானே — push/pop automatically.

**எது போகும்:**
- Local variables
- Function arguments
- Return address
- Saved registers (rbp போன்றவை)

---

## Heap என்றால்:

```c
void main() {
    int *p = malloc(100);  // Heap-ல் போகும்
    // நீயே free பண்ணணும்!
    free(p);
}
```

**யார் manage பண்றது?** Programmer — manually `malloc` / `free`.

**எது போகும்:**
- Runtime-ல் size தெரியும் data
- Big data
- Long-lived data (function முடிந்தாலும் இருக்கணும்)

---

## Stack vs Heap — Quick table:

| | Stack | Heap |
|---|---|---|
| Size | Fixed, small (~8MB) | Large, flexible |
| Speed | Very fast | Slower |
| Manage | CPU automatic | Programmer manual |
| Life | Function உள்ளே மட்டும் | நீ free பண்ணும் வரை |
| Error | Stack overflow | Memory leak |

---

## 2️⃣ `#include` binary/hex → Assembly-ல் என்ன ஆனது?

**நம்ம hello.c-ல் இருந்தது:**

```
Disk-ல் bytes:
# i  n  c  l  u  d  e     < s  t  d  i  o  .  h  >
23 69 6e 63 6c 75 64 65 20 3c 73 74 64 69 6f 2e 68 3e
```

**Assembly-ல் வந்ததா?** ❌ வரவே இல்லை!

```
#include <stdio.h>  →  Preprocessor-ல் உபயோகப்பட்டது
                    →  stdio.h contents copy ஆச்சு
                    →  hello.i-ல் declarations வந்தது
                    →  Compiler அந்த declarations படித்தது
                    →  Assembly-ல் trace இல்லை — gone!
```

---

## 3️⃣ hello.c → Assembly — எல்லாம் என்ன ஆனது?

```
┌─────────────────────────────────────────────────────────────────┐
│                    hello.c (disk-ல் bytes)                      │
├──────────────────┬──────────────────────────────────────────────┤
│ Code             │ Disk bytes (hex)                             │
├──────────────────┼──────────────────────────────────────────────┤
│ #include<stdio.h>│ 23 69 6e 63 6c 75 64 65 ...                 │
│ int main() {     │ 69 6e 74 20 6d 61 69 6e ...                 │
│ printf(          │ 70 72 69 6e 74 66 28 ...                    │
│ "Hello, World!"  │ 48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 ... │
│ return 0;        │ 72 65 74 75 72 6e 20 30 ...                 │
│ }                │ 7d                                           │
└──────────────────┴──────────────────────────────────────────────┘
         ↓ Preprocessing
┌─────────────────────────────────────────────────────────────────┐
│                         hello.i                                 │
├──────────────────┬──────────────────────────────────────────────┤
│ #include gone!   │ stdio.h-ஓட 800 lines paste ஆச்சு           │
│ extern printf(..)│ ← இது வந்தது (declaration)                  │
│ int main()...    │ ← உன் code same                             │
└──────────────────┴──────────────────────────────────────────────┘
         ↓ Compilation (cc1)
┌─────────────────────────────────────────────────────────────────┐
│                         hello.s                                 │
├──────────────────┬──────────────────────────────────────────────┤
│ C code           │ Assembly-ல் என்ன ஆனது                       │
├──────────────────┼──────────────────────────────────────────────┤
│ #include         │ ❌ GONE — no trace                           │
│ "Hello, World!"  │ ✅ .rodata → .string "Hello, World!"        │
│ int main()       │ ✅ main: label ஆனது                         │
│ printf(...)      │ ✅ call puts@PLT ஆனது                       │
│ return 0         │ ✅ movl $0, %eax ஆனது                       │
│ { }              │ ✅ pushq/popq/ret ஆனது                      │
└──────────────────┴──────────────────────────────────────────────┘
```

---

## 4️⃣ "Hello, World!" string — எங்கே போனது?

**இது most important!** String-ஓட journey:

```
hello.c disk-ல்:
"Hello, World!\n"
48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 0a 00
H  e  l  l  o  ,     W  o  r  l  d  !  \n \0

         ↓ Compiler பார்க்கும்

hello.s-ல்:
.section .rodata        ← read-only data section-ல் வை
.LC0:
    .string "Hello, World!"  ← same string, label கொடு

         ↓ Assembler (step 4)

hello.o binary-ல்:
.rodata section-ல் exact bytes:
48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21 0a 00
↑ இதுவே disk-ல் இருந்த same bytes — RAM-ல் load ஆகும்!
```

---

## 5️⃣ Complete Journey — ஒரே diagram:

```
┌────────────────────────────────────────────────────────┐
│  hello.c (Text file — disk)                            │
│  '#','i','n','c'... = ASCII bytes                      │
│  'H','e','l','l','o'... = ASCII bytes                  │
└───────────────┬────────────────────────────────────────┘
                │ gcc -E (Preprocessor)
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.i (Text file — disk)                            │
│  #include → GONE                                       │
│  stdio.h contents → PASTED (800 lines)                 │
│  printf declaration → இருக்கு                          │
│  உன் code → same                                       │
└───────────────┬────────────────────────────────────────┘
                │ gcc -S (Compiler cc1)
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.s (Text file — disk)                            │
│  C syntax → GONE                                       │
│  "Hello,World!" → .rodata section-ல்                  │
│  main() → main: label                                  │
│  printf() → call puts@PLT                              │
│  return 0 → movl $0,%eax                               │
│  இன்னும் TEXT — binary இல்லை!                         │
└───────────────┬────────────────────────────────────────┘
                │ as (Assembler) — Step 4
                ▼
┌────────────────────────────────────────────────────────┐
│  hello.o (Binary file — disk)                          │
│  .text:   f3 0f 1e fa 55 48 89 e5 ...  ← opcodes      │
│  .rodata: 48 65 6c 6c 6f 2c 20 57 ...  ← string bytes │
│  இப்போது BINARY — human படிக்க முடியாது!              │
└───────────────┬────────────────────────────────────────┘
                │ ld (Linker) — Step 5
                ▼
┌────────────────────────────────────────────────────────┐
│  hello (Executable — disk)                             │
│  puts@PLT → libc.so connected                         │
│  addresses → resolved                                  │
└───────────────┬────────────────────────────────────────┘
                │ ./hello (Run)
                ▼
┌────────────────────────────────────────────────────────┐
│  RAM (Memory)                                          │
│  Stack:  main() frame, return address                  │
│  Heap:   (நம்ம program use பண்றதில்லை)                │
│  .text:  f3 0f 1e fa ... ← CPU execute பண்றது         │
│  .rodata: "Hello, World!" bytes ← CPU படிக்கும்        │
└───────────────┬────────────────────────────────────────┘
                │
                ▼
        Terminal: Hello, World! ✅
```

இப்போது `#include` முதல் terminal வரை எல்லாம் clear-ஆ புரிஞ்சதா? 🎯