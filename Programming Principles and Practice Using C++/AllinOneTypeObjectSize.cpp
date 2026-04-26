#include <iostream>
#include <string>
#include <vector>

class AllinOneTypeObjectSize {
    public:
        int x;
        double y;
};

int main() {

    // Basic type
    char c = 'a';
    bool b = true;
    short s = 10;
    int i = 100;
    long l = 100000;
    long long ll = 1000000000;
    float f = 3.14f;
    double d = 3.14159;

    std::string str = "Hello";

    // Intermediate
    int arr[8] = {1,2,3,4,5,6,7,89}; // 1 int is 4 bytes so 32 bytes
    int x = 10;
    int* ptr = &x;

    // Advanced
    AllinOneTypeObjectSize obj{1, 2.5};
    std::vector<int> v = {1,2,3,4,5};

    std::cout << "======== BASIC TYPES ==========\n";
    std::cout << "char size: " << sizeof(c) << "\n";
    std::cout << "bool size: " << sizeof(b) << "\n";
    std::cout << "short size: " << sizeof(s) << "\n";
    std::cout << "int size: " << sizeof(i) << "\n";
    std::cout << "long size: " << sizeof(l) << "\n";
    std::cout << "long long size: " << sizeof(ll) << "\n";
    std::cout << "float size: " << sizeof(f) << "\n";
    std::cout << "double size: " << sizeof(d) << "\n";
    
    std::cout << "\n========== STRING =============\n";
    std::cout << "string object size: " << sizeof(str) << "\n";
    std::cout << "string length: " << str.size() << "\n";

    std::cout << "\n ========== ARRAY ==========\n";
    std::cout << "array size: " << sizeof(arr) << "\n";
    std::cout << "array length: " << sizeof(arr)/sizeof(arr[0]) << "\n";

    std::cout << "\n======== POINTER ==========\n";
    std::cout << "pointer size: " << sizeof(ptr) << "\n";

    std::cout << "\n========= CLASS ==========\n";
    std::cout << "class object size: " << sizeof(obj) << "\n";

    std::cout << "\n========== VECTOR ==========\n";
    std::cout << "vector object size: " << sizeof(v) << "\n";
    std::cout << "vector length: " << v.size() << "\n";

    return 0;
}


/*
Ahh now I understand clearly 🔥 —
👉 நீ **ALL common C++ data types** size + length (where possible) ஒரே programல பார்க்கணும்.

👉 Important truth first:

* ❌ எல்லா typeக்கும் “length” இருக்காது
* ✔️ “length” only for:

  * string
  * array
  * vector

👉 மற்ற எல்லா types → **size மட்டும் தான் meaningful**

---

# 💻 FULL “ALL TYPES” PROGRAM (size + length where possible)

```cpp
#include <iostream>
#include <string>
#include <vector>

class Demo {
public:
    int x;
    double y;
};

int main()
{
    // 🔰 Basic types
    char c = 'a';
    bool b = true;
    short s = 10;
    int i = 100;
    long l = 100000;
    long long ll = 1000000000;
    float f = 3.14f;
    double d = 3.14159;

    std::string str = "Hello";

    // ⚙️ Intermediate
    int arr[4] = {1,2,3,4};
    int x = 10;
    int* ptr = &x;

    // 🚀 Advanced
    Demo obj{1, 2.5};
    std::vector<int> v = {1,2,3,4,5};

    std::cout << "===== BASIC TYPES =====\n";
    std::cout << "char size: " << sizeof(c) << "\n";
    std::cout << "bool size: " << sizeof(b) << "\n";
    std::cout << "short size: " << sizeof(s) << "\n";
    std::cout << "int size: " << sizeof(i) << "\n";
    std::cout << "long size: " << sizeof(l) << "\n";
    std::cout << "long long size: " << sizeof(ll) << "\n";
    std::cout << "float size: " << sizeof(f) << "\n";
    std::cout << "double size: " << sizeof(d) << "\n";

    std::cout << "\n===== STRING =====\n";
    std::cout << "string object size: " << sizeof(str) << "\n";
    std::cout << "string length: " << str.size() << "\n";

    std::cout << "\n===== ARRAY =====\n";
    std::cout << "array size: " << sizeof(arr) << "\n";
    std::cout << "array length: " << sizeof(arr)/sizeof(arr[0]) << "\n";

    std::cout << "\n===== POINTER =====\n";
    std::cout << "pointer size: " << sizeof(ptr) << "\n";

    std::cout << "\n===== CLASS =====\n";
    std::cout << "class object size: " << sizeof(obj) << "\n";

    std::cout << "\n===== VECTOR =====\n";
    std::cout << "vector object size: " << sizeof(v) << "\n";
    std::cout << "vector length: " << v.size() << "\n";

    return 0;
}
```

---

# 🧪 Typical Output (64-bit system)

```text
===== BASIC TYPES =====
char size: 1
bool size: 1
short size: 2
int size: 4
long size: 8
long long size: 8
float size: 4
double size: 8

===== STRING =====
string object size: 32
string length: 5

===== ARRAY =====
array size: 16
array length: 4

===== POINTER =====
pointer size: 8

===== CLASS =====
class object size: 16

===== VECTOR =====
vector object size: 24
vector length: 5
```

---

# 🧠 VERY IMPORTANT UNDERSTANDING

## 🔴 Why some types don’t have “length”?

👉 Example:

```cpp
int x = 10;
```

👉 இது single value
👉 length concept கிடையாது ❌

---

## 🟢 Only these have “length”

| Type   | Length Meaning     |
| ------ | ------------------ |
| string | characters count   |
| array  | number of elements |
| vector | number of elements |

---

# ⚠️ Important Differences

👉 `sizeof()`:

* memory usage

👉 `.size()`:

* number of elements

---

# 💬 Simple Tamil Summary

👉 எல்லா types:

* size ✔️ இருக்கும்
* length ❌ இல்லை (except collections)

👉 length இருக்கும்:

* string
* array
* vector

---

# 🔥 Final Truth

👉

> “All types have size
> Only collections have length”

---

If you want next 🔥

👉 memory layout (stack vs heap)
👉 why `long` size differs OS-wise
👉 deep internals (interview level)

Just tell 👍

*/