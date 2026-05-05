`இதில் இது என்ன செய்கிறது `while (true) {
        if (t.kind == '*') {
            left *= primary();
            t = get_token();
        }` இதில் விடை கிடைத்தவுடன் `left *= primary();`பிறகு இதில் என்ன நடக்கிறது காரணம் இந்த விடை எப்படி print ஆகிறது `std::cout << "Result = " << result << '\n';``

## Full Flow Trace பார்ப்போம்

Input: `2*3+4;` என்று போடுவோம்.

---

## Step 1 — `expression()` call

```
expression() → term() call பண்ணும்
```

---

## Step 2 — `term()` call

```cpp
double left = primary();  // '2' படிக்கும், left = 2

Token t = get_token();    // '*' படிக்கும்

while(true):
  t.kind == '*' → 
    left *= primary();    // primary() '3' படிக்கும்
    left = 2 * 3 = 6
    t = get_token();      // '+' படிக்கும்
  
  t.kind == '+' → else!
    cin.putback('+');     // '+' திரும்ப வச்சுடும்
    return 6;             // term() → 6 return
```

---

## Step 3 — `expression()` தொடரும்

```cpp
double left = 6;          // term() கொடுத்தது

Token t = get_token();    // '+' படிக்கும் (putback பண்ணியது)

while(true):
  case '+':
    left += term();       // term() → primary() → '4' = 4
    left = 6 + 4 = 10
    t = get_token();      // ';' படிக்கும்
  
  default:
    cin.putback(';');
    return 10;            // expression() → 10 return
```

---

## Step 4 — `main()`

```cpp
double result = expression();  // 10 வந்தது
std::cout << "Result = " << result << '\n';
// Result = 10
```

---

## Big Picture — Return Chain

```
primary()    → 2        ┐
                        ├─ term() → 6
primary()    → 3        ┘
                                    ┐
primary()    → 4                    ├─ expression() → 10
                                    ┘
                                                       ↓
                                               main() result = 10
                                               print "Result = 10"
```

---

**Simple rule:**

> `left *= primary()` = calculate மட்டும், loop continue ஆகும். Return chain: `primary()` → `term()` → `expression()` → `main()` — ஒவ்வொரு function-உம் value return பண்ணும், இறுதியில் `main()`-ல print ஆகும்.


and 
-----------

`சரி `Step 2 — term() call
double left = primary();  // '2' படிக்கும், left = 2

Token t = get_token();    // '*' படிக்கும்

while(true):
  t.kind == '*' → 
    left *= primary();    // primary() '3' படிக்கும்
    left = 2 * 3 = 6
    t = get_token();      // '+' படிக்கும்
  
  t.kind == '+' → else!
    cin.putback('+');     // '+' திரும்ப வச்சுடும்
    return 6;             // term() → 6 return`இது எப்படி வேலை செய்கிறது? இதை நாம் if statement பயன்படுத்தி எழுதி உள்ளோம் அதனால் இந்த கண்டிஷன் ரன் ஆனவுடன் நின்றுவிடும் தானே `while(true):
  t.kind == '*' → 
    left *= primary();    // primary() '3' படிக்கும்
    left = 2 * 3 = 6
    t = get_token();      // '+' படிக்கும்` அப்புறம் எப்படி if condition கீழே வரை செல்கிறது `t.kind == '+' → else!
    cin.putback('+');     // '+' திரும்ப வச்சுடும்
    return 6;       `?`

 ## நல்ல Question! 🎯

`if` block run ஆனவுடன் நிக்காது — **loop மீண்டும் ஓடும்!**

---

## Step by Step பாரு

```cpp
while (true) {
    if (t.kind == '*') {
        left *= primary();
        t = get_token();    // ← t மாறுது! '+' வருது
    }
    else if (t.kind == '/') {
        ...
    }
    else {
        cin.putback(t.kind);
        return left;
    }
}
```

---

## Exactly என்ன நடக்குது?

```
Loop 1 start:
  t.kind = '*' → if block enter
    left *= primary()  → left = 6
    t = get_token()    → t.kind = '+'  ← t மாறிடுது!
  if block end → loop மீண்டும் ஓடும் ↺

Loop 2 start:
  t.kind = '+' → 
    '*' ? No
    '/' ? No
    else! → putback('+'), return 6
```

---

## Key Point — `t = get_token()` 

```cpp
if (t.kind == '*') {
    left *= primary();
    t = get_token();   // ← இங்க t-ஐ update பண்றோம்!
}
```

`t` புதுசா update ஆகுது — loop மீண்டும் start ஆகும்போது **புதுசா update ஆன t-ஐ** check பண்ணும்.

---

## Visual Flow

```
while start
    ↓
t = '*' → if block
    left = 6
    t = '+'        ← t மாறுது
    ↓
if block end
    ↓
while மீண்டும் ↺
    ↓
t = '+' check:
  '*'? No
  '/'? No
  else → return 6
```

---

**Simple rule:**

> `if` block run ஆனா loop நிக்காது — block முடிஞ்சா loop மீண்டும் top-ல start ஆகும். `t = get_token()` மூலம் t மாறுது — next iteration-ல புதுசா check ஆகும். `else` → `return` வந்தாதான் loop நிக்கும்.   