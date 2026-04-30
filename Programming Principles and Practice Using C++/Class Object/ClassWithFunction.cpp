#include <iostream>

class Student {
    private: 
        int id;
        double marks;

    public:
        void set(int i, double m) {
            id = i;
            marks = m;
        }    

        void show() {
            std::cout << "ID: " << id << "\n";
            std::cout << "Marks: " << marks << "\n";
        }
};

int main() {
    Student s1;
    s1.set(101, 90.0);
    s1.show();
}

/*
சரி 🔥 — class vs struct concept நன்றாக புரியணும்னா **ஒரே problem-க்கு இரண்டு style code** பார்த்தா தான் clear ஆகும்.
நாம் simple example எடுக்கலாம்: **“Student” data + behavior”**

---

# 🟢 1. C style (`struct` மாதிரி – data மட்டும்)

👉 File: `student_struct.cpp`

```cpp id="st1"
#include <iostream>

struct Student {
    int id;
    double marks;
};

int main() {
    Student s1;

    s1.id = 101;
    s1.marks = 85.5;

    std::cout << "ID: " << s1.id << "\n";
    std::cout << "Marks: " << s1.marks << "\n";

    return 0;
}
```

---

## 🧠 Tamil Explanation

👉 இது என்ன?

* `struct` → data container
* functions இல்லை
* logic outside

---

👉 Example:

```text id="st2"
Student = data மட்டும்
```

---

# 🔴 Problem (Why not enough?)

👉 Suppose:

* marks update பண்ணணும்
* pass/fail check பண்ணணும்

👉 இப்ப எப்படி?

```cpp id="st3"
if (s1.marks >= 50) ...
```

👉 logic separate ஆகும் ❌

---

# 🟢 2. C++ Class (Data + Behavior)

👉 File: `student_class.cpp`

```cpp id="st4"
#include <iostream>

class Student {
public:
    int id;
    double marks;

    void show() {
        std::cout << "ID: " << id << "\n";
        std::cout << "Marks: " << marks << "\n";
    }

    void check_pass() {
        if (marks >= 50)
            std::cout << "Pass\n";
        else
            std::cout << "Fail\n";
    }
};

int main() {
    Student s1;

    s1.id = 101;
    s1.marks = 85.5;

    s1.show();
    s1.check_pass();

    return 0;
}
```

---

# 🧠 Difference Clear ஆகணும் 🔥

| Feature       | struct (C style) | class (C++) |
| ------------- | ---------------- | ----------- |
| Data          | ✔️               | ✔️          |
| Functions     | ❌                | ✔️          |
| Encapsulation | ❌                | ✔️          |

---

# 🟢 3. Real World Analogy

```text id="st5"
struct = data box 📦
class = smart object 🤖
```

---

# 🟢 4. Best Practice Version (Real C++)

👉 Data hide பண்ணி safeஆ எழுதலாம்:

```cpp id="st6"
#include <iostream>

class Student {
private:
    int id;
    double marks;

public:
    void set(int i, double m) {
        id = i;
        marks = m;
    }

    void show() {
        std::cout << "ID: " << id << "\n";
        std::cout << "Marks: " << marks << "\n";
    }
};

int main() {
    Student s1;
    s1.set(101, 90.0);
    s1.show();
}
```

---

# 💥 BIG CONCEPT (IMPORTANT)

👉 Class gives:

* control
* safety
* structure

---

# 🎯 Simple Tamil Summary

👉 struct:

* data மட்டும்

👉 class:

* data + function
* safe
* organized

---

# 🚀 Final Takeaway

```text id="st7"
struct → simple data
class → real programming tool
```

---

If you want next 🔥

👉 Token class example (your calculator code connect பண்ணி explain)
👉 memory layout diagram
👉 `this` pointer deep

Just tell 👍

*/