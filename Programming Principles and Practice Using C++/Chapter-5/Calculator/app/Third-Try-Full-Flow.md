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
