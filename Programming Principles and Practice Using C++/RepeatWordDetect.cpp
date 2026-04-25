#include <iostream>
#include <string>

int main() {

    std::string previous; // empty ""
    std::string current;

    while (std::cin >> current) {
        if (previous == current) {
           std::cout << "repeated word: " << current << '\n';
        }
    previous = current;
    }
    return 0;
}

/*
Super 🔥 — this example is **VERY IMPORTANT**
👉 இது first real “logic program” (pattern detection)

நான் இதை **step-by-step Tamil + dry run (play computer)** explain பண்ணுறேன்.

---

# 💻 Full Code (clean version)

```cpp id="8m9t4p"
#include <iostream>
#include <string>

int main()
{
    std::string previous;   // empty ""
    std::string current;

    while (std::cin >> current)
    {
        if (previous == current)
            std::cout << "repeated word: " << current << '\n';

        previous = current;
    }

    return 0;
}
```

---

# 🧠 1. Program Idea

👉 Goal:

```text id="goal1"
consecutive repeated words கண்டுபிடிக்க
```

👉 Example input:

```text id="inp1"
this is is a test test program
```

👉 Output:

```text id="out1"
repeated word: is
repeated word: test
```

---

# ⚙️ 2. Important Concepts

---

## 🟢 `previous`

👉 previous word store பண்ணும்

👉 initially:

```text id="p1"
previous = ""
```

---

## 🟢 `current`

👉 current input word

---

## 🟢 while loop

```cpp id="loop1"
while (std::cin >> current)
```

👉 meaning:

* word read ஆகும் வரை loop run ஆகும்
* input முடிந்ததும் stop

---

# 🔥 3. “Play Computer” (VERY IMPORTANT)

👉 Let’s simulate step-by-step 👇

---

## 🧪 Input:

```text id="inp2"
this is is a test test
```

---

## 🟢 Step 1

```text id="s1"
current = "this"
previous = ""
```

👉 compare:

```text id="s1c"
"" == "this" → false
```

👉 update:

```text id="s1u"
previous = "this"
```

---

## 🟢 Step 2

```text id="s2"
current = "is"
previous = "this"
```

👉 compare:

```text id="s2c"
this == is → false
```

👉 update:

```text id="s2u"
previous = "is"
```

---

## 🟢 Step 3 🔥

```text id="s3"
current = "is"
previous = "is"
```

👉 compare:

```text id="s3c"
is == is → true ✔️
```

👉 output:

```text id="s3o"
repeated word: is
```

👉 update:

```text id="s3u"
previous = "is"
```

---

## 🟢 Step 4

```text id="s4"
current = "a"
previous = "is"
```

👉 no match

---

## 🟢 Step 5

```text id="s5"
current = "test"
previous = "a"
```

👉 no match

---

## 🟢 Step 6 🔥

```text id="s6"
current = "test"
previous = "test"
```

👉 match ✔️

👉 output:

```text id="s6o"
repeated word: test
```

---

# 🧠 4. KEY LOGIC

👉 Every loop:

```text id="logic1"
1. current read
2. previous compare
3. if same → print
4. previous = current
```

---

# ⚠️ 5. Important Trick

👉 First iteration:

```text id="trick1"
previous = ""
```

👉 So:

```text id="trick2"
"" == first_word → false
```

👉 safe start ✔️

---

# 🔥 6. Why assignment needed?

👉 This line:

```cpp id="assign1"
previous = current;
```

👉 இல்லையெனில்:

* next comparison work ஆகாது ❌

👉 இது தான் loop memory 🔥

---

# 🎯 7. Real-world meaning

👉 This logic used in:

* grammar checkers
* text processing
* duplicate detection

---

# 💬 Simple Tamil Summary

👉 previous → last word
👉 current → current word

👉 compare → sameனா print

👉 update:

```cpp
previous = current;
```

👉 loop repeat

---

# 🚀 Next Level (if you want)

👉 I can upgrade this program:

* count repeated words
* ignore case (Apple == apple)
* detect non-adjacent duplicates

Just tell 👍

*/