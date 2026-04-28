#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    std::vector<std::string> words;

    for (std::string temp; std::cin >> temp; ) {
          if (temp == "quit") break; 
          words.push_back(temp);
    }
    std::cout << "Number of words: " << words.size() << '\n';
    
    std::sort(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i-1] != words[i]) // cancel dublicate
           std::cout << words[i] << '\n';
    }

    return 0;
}

/*
Super 🔥 — this is a **real-world style C++ program (vector + sorting + filtering)**.
நான் இதை **simple Tamil + step-by-step + logic breakdown + code understanding** explain பண்ணுறேன்.

---

# 📘 3.6.4 Text Example — Core Idea

👉 Goal:

```text
Input words → store → sort → remove duplicates → print
```

👉 Example:

```
Input:
a man a plan a canal panama

Output:
a
canal
man
panama
plan
```

---

# 💻 Full Code (Clean Version)

```cpp id="dict1"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> words;

    for (std::string temp; std::cin >> temp; )
        words.push_back(temp);

    std::cout << "Number of words: " << words.size() << '\n';

    std::sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i-1] != words[i])
            std::cout << words[i] << '\n';

    return 0;
}
```

---

# 🧠 Step-by-Step Explanation

---

# 🟢 1. Vector (Important 🔥)

```cpp id="v1"
std::vector<std::string> words;
```

👉 meaning:

* list of strings
* dynamic size

👉 example:

```text
["a", "man", "a", "plan"]
```

---

# 🟢 2. Input Loop

```cpp id="v2"
for (std::string temp; std::cin >> temp; )
```

👉 meaning:

* word by word read
* until input ends

👉 stop:

* Linux → Ctrl + D
* Windows → Ctrl + Z

---

# 🟢 3. Store Words

```cpp id="v3"
words.push_back(temp);
```

👉 add word to vector

---

## 🧪 Example

Input:

```
a man a
```

👉 vector:

```text
["a", "man", "a"]
```

---

# 🟢 4. Count Words

```cpp id="v4"
words.size()
```

👉 total words count

---

# 🟢 5. Sorting

```cpp id="v5"
std::sort(words.begin(), words.end());
```

👉 alphabetical order

---

## Example:

Before:

```text
["man", "a", "plan"]
```

After:

```text
["a", "man", "plan"]
```

---

# 🟢 6. Remove Repeated Words (CORE LOGIC 🔥)

```cpp id="v6"
if (i == 0 || words[i-1] != words[i])
```

---

## 🧠 Meaning

👉 print only if:

1. first word
   OR
2. previous word ≠ current

---

## 🧪 Example (after sorting)

```text
["a", "a", "a", "man"]
```

---

### Step-by-step:

| i | word | previous | print? |
| - | ---- | -------- | ------ |
| 0 | a    | -        | ✔️     |
| 1 | a    | a        | ❌      |
| 2 | a    | a        | ❌      |
| 3 | man  | a        | ✔️     |

---

👉 Result:

```text
a
man
```

---

# 🧠 7. Why sorting important?

👉 duplicates adjacent ஆகும்

```text
Before:
a man a

After sort:
a a man
```

👉 easy detect ✔️

---

# ⚠️ 8. Important Operators

👉 strings compare:

* `==`
* `!=`
* `<`
* `>`

👉 dictionary order

---

# 🧪 9. Try This — BLEEP Program

---

## 💻 Code:

```cpp id="bleep1"
#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::string disliked = "broccoli";

    while (std::cin >> word)
    {
        if (word == disliked)
            std::cout << "BLEEP ";
        else
            std::cout << word << " ";
    }

    return 0;
}
```

---

## 🧪 Input:

```
I like broccoli and apple
```

---

## Output:

```
I like BLEEP and apple
```

---

# 🎯 Final Understanding

👉 This program teaches:

✔️ vector usage
✔️ input loop
✔️ sorting
✔️ duplicate removal
✔️ condition logic

---

# 💬 Simple Tamil Summary

👉 words → vectorல store

👉 sort → order

👉 compare:

```cpp
words[i-1] != words[i]
```

👉 duplicate remove

---

# 🚀 Next Level (if you want)

👉 I can upgrade this:

* count frequency (word count 🔥)
* case-insensitive dictionary
* remove punctuation

Just tell 👍


*/