## `constexpr` என்றால் என்ன?

**"Compile time-லயே calculate பண்ணிடு"** என்று compiler-க்கு சொல்வது.

---

## Normal const vs constexpr

```cpp
int x = 5;
const int y = x * 2;      // runtime-ல calculate ஆகும்

constexpr int z = 10 * 2; // compile time-லயே 20 ஆகிடும்
```

`constexpr` போட்டா program run ஆகும் முன்னாடியே value தெரியும் — **faster**.

---

## Function-ல constexpr

```cpp
constexpr int area(int l, int w) {
    return l * w;
}

int main() {
    constexpr int a = area(3, 4); // compile time-லயே 12 ஆகிடும்
    int b = area(3, 4);           // runtime-ல calculate ஆகும்
}
```

`constexpr` function — compile time values கொடுத்தா compile time-ல, runtime values கொடுத்தா runtime-ல calculate ஆகும். **Flexible.**

---

## Assembly-ல என்ன நடக்குது?

```cpp
constexpr int x = 10 * 2;
```

Compiler இதை assembly-ல இப்படி போடும்:

```asm
mov eax, 20    ; 10*2 calculate பண்ணலையே — directly 20 போட்டுடுது
```

Runtime-ல கணக்கே இல்ல — **pure hardcoded value.**

---

## எங்க Use பண்றோம்?

```cpp
constexpr double PI = 3.14159;        // constant values
constexpr int MAX_SIZE = 100;         // array size
constexpr int square(int x) {        // math functions
    return x * x; 
}
```

---

**Simple rule:**

> `constexpr` = **compile time guarantee.** Runtime-ல calculate பண்ண வேண்டாம் என்று தெரிஞ்சா போடு — program faster ஆகும்.