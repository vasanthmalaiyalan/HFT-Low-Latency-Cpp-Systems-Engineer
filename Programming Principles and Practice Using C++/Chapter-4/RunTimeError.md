## ஏன் Ratio Print ஆகல?

Step by step trace பண்ணோம்:

```
test(-1, 2, 3) call ஆகுது
  x = -1, y = 2, z = 3
```

---

### area1 calculation:

```cpp
area1 = area(-1, 2)
  → length = -1  ← 0-ஐ விட சிறியது!
  → return 0
area1 = 0
```

---

### area3 calculation:

```cpp
area3 = framed_area(2, 3)
  → area(2-2, 3-2)
  → area(0, 1)
  → length = 0  ← 0-ஐ விட சிறியதில்லை, ஆனா equal!
  → return 0
area3 = 0
```

---

### if check:

```cpp
if (area3 == 0)  // true!
    std::cout << "Error: division by zero\n";
    return;      // இங்கயே function exit ஆகிடுது
```

`area3 = 0` ஆனதால் division by zero check trigger ஆகுது — ratio line-யே reach ஆகல!

---

## Fix — Guard Condition சரி பண்ணு

```cpp
int area(int length, int width) {
    if (length <= 0 || width <= 0)  // 0-உம் invalid-ஆ treat பண்றோம்
        return 0;
    return length * width;
}
```

`length <= 0` இருக்கு — so `area(0, 1)` = 0 வருது. இது correct behaviour — 0 width-க்கு area இல்ல.

**Ratio பார்க்கணும்னா valid values போடணும்:**

```cpp
int main() {
    test(4, 5, 6);  // valid values
}
```

```
area1 = area(4, 5)        = 20
area3 = framed_area(5, 6) = area(3, 4) = 12
ratio = 20.0 / 12         = 1.66667
```

**Output:**
```
1.66667
```

---

**Simple rule:**

> `-1, 2, 3` போட்டதால் இரண்டு areas-உமே `0` ஆச்சு — division by zero guard trigger ஆச்சு, ratio print ஆகல. Valid positive values போட்டா ratio வரும்.