இந்த பகுதி **“What You Can Learn in This Book”** — இந்த புத்தகம் படித்தால் என்ன கற்றுக்கொள்ளலாம் என்பதை சொல்கிறது. அதை மிகவும் **simple Tamil**-ல் விளக்குகிறேன்.

---

# 1️⃣ பழைய கால programmers எப்படி performance improve செய்தார்கள்?

1960–1970 காலத்தில் computers-க்கு ஒரு பெரிய problem இருந்தது:

👉 **Memory size மிகவும் குறைவு**

அதனால் programmers ஒரு rule follow செய்தார்கள்:

> **Memory usage குறைத்தால் program fast ஆகும்**

Example:

```
memory use ↓
speed ↑
```

---

# 2️⃣ இப்போது அந்த rule ஏன் போதாது?

இப்போது computers:

* RAM பெரியது
* storage பெரியது
* hardware fast

அதனால் performance problem வேறு இடத்தில் உள்ளது.

இப்போது programmers தெரிந்திருக்க வேண்டிய இரண்டு முக்கிய விஷயங்கள்:

### 1️⃣ Parallel Processing

ஒரே நேரத்தில் பல instructions run ஆகும்.

Example:

* multicore CPU
* GPU

---

### 2️⃣ Memory Hierarchy

Memory எல்லாம் same speed இல்லை.

Example:

```
Registers (fastest)
↓
Cache
↓
RAM
↓
SSD / Disk (slow)
```

Program speed இதைப் பொறுத்தே இருக்கும்.

---

# 3️⃣ இந்த புத்தகம் explain செய்யும் முக்கிய விஷயங்கள்

இந்த புத்தகம் படித்தால் நீ answer செய்ய முடியும்:

---

# ❓ Question 1

### High level language → hardware எப்படி execute செய்கிறது?

Example languages:

* C
* Java

Process:

```
C program
↓
Compiler
↓
Assembly
↓
Machine code
↓
CPU executes
```

இதைக் புரிந்தால்:

* program performance
* hardware behaviour

புரியும்.

---

# ❓ Question 2

### Software மற்றும் Hardware எப்படி communicate செய்கிறது?

Software hardware-க்கு எப்படி instruction கொடுக்கிறது?

இதற்கான interface:

👉 **Instruction Set Architecture (ISA)**

Example instruction:

```
ADD R1, R2
LOAD R3, 0x100
```

CPU இதை execute செய்கிறது.

---

# ❓ Question 3

### Program performance எப்படி தீர்மானிக்கப்படுகிறது?

Program speed மூன்று விஷயங்களால் முடிவு ஆகிறது.

```
Performance =
Algorithm
+ Software translation
+ Hardware execution
```

---

# 1️⃣ Algorithm

Example:

Sorting

```
Bubble Sort
O(n²)

Quick Sort
O(n log n)
```

Algorithm itself speed-ஐ பாதிக்கும்.

---

# 2️⃣ Software Translation

இதில்:

* programming language
* compiler

example:

```
C code → machine instructions
```

ஒரு line code → எத்தனை machine instructions?

இதுவும் performance-ஐ பாதிக்கும்.

---

# 3️⃣ Hardware

Hardware determine செய்யும்:

* instruction execution speed
* memory access speed
* cache efficiency

---

# ❓ Question 4

### Hardware designers performance எப்படி improve செய்கிறார்கள்?

Modern techniques:

* pipelining
* caching
* branch prediction
* out-of-order execution

இவை எல்லாம் இந்த book-ல் explain செய்யப்படும்.

---

# ❓ Question 5

### ஏன் sequential → parallel computing change நடந்தது?

பழைய CPU:

```
1 core
1 instruction at a time
```

இப்போது:

```
Multicore CPU
multiple instructions simultaneously
```

இதுதான்:

👉 **Multicore microprocessor**

Meaning:

ஒரே chip-ல் பல processors.

---

Example CPUs:

* Intel i7
* AMD Ryzen
* Apple M series

---

# 4️⃣ இந்த புத்தகம் சொல்லும் ஒரு முக்கிய truth

Program speed என்பது **ஒரு factor மட்டும் இல்ல**.

இந்த எல்லாம் சேர்ந்து முடிவு செய்கிறது:

| Component            | Effect               |
| -------------------- | -------------------- |
| Algorithm            | எத்தனை operations    |
| Programming language | instructions count   |
| Compiler             | machine code quality |
| Processor            | execution speed      |
| Memory system        | data access speed    |
| I/O system           | input/output speed   |

---

# 5️⃣ Example

Suppose program slow.

Reason இருக்கலாம்:

### Algorithm problem

```
O(n²) algorithm
```

---

### Compiler problem

compiler inefficient code generate.

---

### Hardware problem

CPU slow

---

### I/O problem

Disk read slow.

---

# 6️⃣ இந்த chapter இன்னும் என்ன introduce செய்கிறது?

இந்த chapter explain செய்யும்:

* computer components
* performance measurement
* power consumption
* integrated circuits
* multicore processors

---

# 7️⃣ Acronyms (Computer short forms)

Computer engineers short forms அதிகம் use செய்வார்கள்.

Example:

| Acronym | Meaning                                   |
| ------- | ----------------------------------------- |
| CPU     | Central Processing Unit                   |
| RAM     | Random Access Memory                      |
| BIOS    | Basic Input Output System                 |
| DIMM    | Dual Inline Memory Module                 |
| DRAM    | Dynamic RAM                               |
| PCIe    | Peripheral Component Interconnect Express |
| SATA    | Serial ATA                                |

---

# 8️⃣ Program Performance formula

இந்த புத்தகத்தின் முக்கிய concept:

```
Program Performance =
Algorithm
+ Compiler
+ Architecture
+ Processor
+ Memory
+ I/O
```

---

# 9️⃣ ஒரு முக்கிய insight

Good programmers:

❌ Just coding மட்டும் செய்ய மாட்டார்கள்.

✔ Understand:

* hardware
* memory
* CPU architecture
* compiler behaviour

---

💡 அதனால் தான்:

இந்த புத்தகம்

> **Hardware + Software bridge**

என்று சொல்லப்படுகிறது.

---

நீ விரும்பினால் நான் அடுத்ததாக இதையும் explain செய்யலாம்:

**இந்த புத்தகத்தின் most famous concept**

```
7 Levels of Computer Abstraction
```

```
Application
↓
OS
↓
Compiler
↓
Instruction Set Architecture
↓
Microarchitecture
↓
Logic circuits
↓
Transistors
```

இந்த ஒரு diagram புரிந்தால்:

> Computer science முழு structure புரிந்து விடும்.
