## Full Flow — `(2+3)*4` Input

---

## Architecture முதலில் பாரு

```
expression()          → +, - handle பண்ணும்
    └── term()        → *, / handle பண்ணும்
         └── primary() → number, () handle பண்ணும்
```

**Rule:** உயர்ந்த precedence = deeper level.

---

## Step 1 — `main()` start

```cpp
double result = expression();  // expression() call
```

---

## Step 2 — `expression()` start

```cpp
double left = term();  // term() call
```

---

## Step 3 — `term()` start

```cpp
double left = primary();  // primary() call
```

---

## Step 4 — `primary()` — `(` பார்க்கும்

```
get_token() → '(' வருது
case '(' → expression() call! (recursive)
```

---

## Step 5 — Inner `expression()` — `2+3` calculate

```
term() → primary() → get_token() → '2'
         return 2

left = 2
get_token() → '+'

case '+':
  term() → primary() → get_token() → '3'
           return 3
  left = 2+3 = 5
  get_token() → ')'

default:
  putback(')')
  return 5          ← inner expression() ends
```

---

## Step 6 — `primary()` `)` check

```cpp
double d = expression();  // d = 5

t = get_token();          // ')' படிக்கும்
if (t.kind != ')')        // ')' match ✅
return d;                 // return 5
```

---

## Step 7 — `term()` தொடரும்

```
left = 5 (primary கொடுத்தது)

get_token() → '*'

case '*':
  primary() → get_token() → '4' → return 4
  left = 5 * 4 = 20
  get_token() → EOF / '\n'

default:
  putback(EOF)
  return 20
```

---

## Step 8 — outer `expression()` தொடரும்

```
left = 20 (term கொடுத்தது)
get_token() → EOF

default:
  putback(EOF)
  return 20
```

---

## Step 9 — `main()` print

```cpp
result = 20
cout << "Result = " << 20
```

---

## Full Call Stack Visual

```
main()
  └── expression()
        └── term()
              └── primary()        ← '(' பார்க்கும்
                    └── expression()  ← recursive! 2+3
                          └── term()
                                └── primary() → 2
                          └── term()
                                └── primary() → 3
                    ← returns 5
              └── primary() → 4
        ← returns 20
  ← result = 20
```

---

## `putback()` ஏன் வேணும்?

```
term() '+' படிக்கும் → அது term-ஓட வேலை இல்ல!
putback('+') → cin-ல திரும்ப வச்சுடும்
expression() அதை படிக்கும் → சரியான இடத்துல handle ஆகும்
```

---

## Token Flow — `(2+3)*4`

```
get_token() calls:
1. '('  → primary: recursive expression
2. '2'  → number 2
3. '+'  → expression: add
4. '3'  → number 3
5. ')'  → primary: close bracket
6. '*'  → term: multiply
7. '4'  → number 4
```

---

**Simple rule:**

> `expression()` → `term()` → `primary()` — layer by layer போகும். `()` வந்தா `primary()` recursive-ஆ `expression()` call பண்ணும் — bracket-க்குள்ள இருப்பதை முதலில் solve பண்ணும். `putback()` மூலம் token-ஐ திரும்ப வச்சு சரியான layer handle பண்ணும்.

----------
`char* `void error(const char* msg) {` char பயன்படுத்தலாமே எதற்காக char*பயன்படுத்துகிறோம் அப்படி பயன்படுத்துவதால் என்ன நடக்கும்`

## `char` vs `char*` — ஏன் `char*` வேணும்?

---

## `char` = Single Character மட்டும்

```cpp
void error(char msg) {
    std::cerr << msg << '\n';
}

error('E');        // ✅ ஒரே character
error("Error!");   // ❌ — string போட முடியாது!
```

`char` = 1 byte மட்டும் — "Error: divide by zero" மாதிரி message store பண்ண முடியாது.

---

## `char*` = Character Array-ஓட Address

```cpp
void error(const char* msg) {
    std::cerr << msg << '\n';
}

error("divide by zero");   // ✅ full string போகும்
error("')' expected");     // ✅
```

---

## Memory-ல என்ன நடக்குது?

```cpp
error("divide by zero");
```

```
Read-only memory (string literal):
[d][i][v][i][d][e][ ][b][y][ ][z][e][r][o][\0]
 ↑
 இந்த address மட்டும் char* msg-க்கு போகும்
```

`char*` = **pointer** — entire string copy ஆகாது, address மட்டும் போகும்.

---

## `const` ஏன் போட்டோம்?

```cpp
const char* msg   // ← const
```

```
"divide by zero" → read-only memory-ல இருக்கு
const இல்லன்னா → modify பண்ண try பண்ணலாம் → crash!
const போட்டா → compiler modify பண்ண allow பண்ணாது ✅
```

---

## Summary

| Type | என்ன store ஆகும் | Example |
|---|---|---|
| `char` | 1 character | `'E'` |
| `char*` | string address | `"Error!"` |
| `const char*` | read-only string address | `"divide by zero"` |

---

**Simple rule:**

> Single character → `char`. Full error message string → `const char*` — string-ஓட starting address போகும், `cout` அதிலிருந்து `\0` வரும் வரை print பண்ணும்.

---------------------

`நடுவில் இதை எதற்காக பயன்படுத்த வேண்டும் `// forward declarations
double expression();`வெட்டியாக?`

## Forward Declaration ஏன் வேணும்?

---

## Problem — Compiler Top to Bottom படிக்கும்

```cpp
double primary()
{
    ...
    double d = expression();  // ← expression() call பண்றோம்
    ...
}

double expression()  // ← ஆனா இது கீழே define ஆகியிருக்கு!
{
    ...
}
```

Compiler `primary()` படிக்கும்போது `expression()` இன்னும் பார்க்கலை — **"என்ன இது?" error வரும்!**

---

## Compiler எப்படி படிக்கும்?

```
Line 1 → Token struct ✅
Line 2 → error() ✅
Line 3 → get_token() ✅
Line 4 → primary() 
           └── expression() call? ❌ — இன்னும் தெரியாது!
```

---

## Forward Declaration — Solution

```cpp
double expression();  // "இந்த function exist ஆகும், 
                      //  கீழே define ஆகும்" — compiler-க்கு hint
```

இப்போ:

```
Line 1 → Token struct ✅
Line 2 → error() ✅
Line 3 → get_token() ✅
Line 4 → double expression(); ← "ok, தெரியும்" ✅
Line 5 → primary()
           └── expression() call? ✅ — already தெரியும்!
Line 6 → expression() define ✅
```

---

## இந்த Code-ல Circular Dependency இருக்கு

```
primary()    → expression() call பண்ணும்
expression() → term() call பண்ணும்
term()       → primary() call பண்ணும்
```

```
primary() ──► expression()
   ▲               │
   │               ▼
   └────── term() ◄─┘
```

ஒவ்வொன்னும் ஒன்னை ஒன்னு call பண்றது — **யாரையும் முதலில் define பண்ணினாலும்** மற்றதை தெரியாது!

---

## Forward Declaration இல்லன்னா?

```
error: 'expression' was not declared in this scope
```

---

**Simple rule:**

> Forward declaration = "இந்த function கீழே இருக்கு, நம்பு" — compiler-க்கு advance notice. Circular calls இருக்கும்போது கட்டாயம் வேணும் — வெட்டி இல்ல!