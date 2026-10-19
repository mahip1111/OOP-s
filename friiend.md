# C++ Friend Class vs Nested Class

## 1. Friend Class kya hoti hai?

C++ mein agar ek class ko doosri class ke **private aur protected members** access karne ki permission deni ho, toh hum `friend class` use kar sakte hain.

### Basic Syntax

```cpp
class A {
private:
    int x;

    friend class B;
};
```

Iska simple meaning:

> **"Class B meri friend hai, isliye B mere private/protected members access kar sakti hai."**

---

# 2. Simple Friend Class Example

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    int marks = 95;

    friend class Result;
};

class Result {
public:
    void showMarks(Student s) {
        cout << "Marks: " << s.marks << endl;
    }
};

int main() {

    Student s;

    Result r;

    r.showMarks(s);

    return 0;
}
```

### Output

```text
Marks: 95
```

Normally `marks` private hai:

```cpp
private:
    int marks = 95;
```

Toh `Result` normally ise access nahi kar sakti.

Lekin:

```cpp
friend class Result;
```

ki wajah se `Result` ko permission mil gayi.

---

# 3. Friend Class ko "declare" kya karna hai?

Jab hum likhte hain:

```cpp
friend class Result;
```

toh hum `Student` ko bata rahe hain:

> "Result naam ki class meri friend hai."

Ye **friend declaration** hai.

Actual class definition baad mein ho sakti hai:

```cpp
class Result {
public:
    void showMarks(Student s) {
        cout << s.marks;
    }
};
```

So:

```cpp
friend class Result;
```

= Friendship declare karna

```cpp
class Result {
    // ...
};
```

= Result class ko define karna

---

# 4. Kya Friend Class ko doosri class ke andar define kar sakte hain?

### Haan, lekin yahan ek important concept hai.

Agar hum:

```cpp
class Student {

    class Result {
        // ...
    };

};
```

likhte hain, toh `Result` **nested class** hai.

Matlab:

> `Result` class `Student` ke andar defined hai.

---

# 5. Nested Class Example

```cpp
#include <iostream>
using namespace std;

class Student {

public:

    class Result {
    public:

        void show() {
            cout << "Result class" << endl;
        }
    };
};

int main() {

    Student::Result r;

    r.show();

    return 0;
}
```

### Output

```text
Result class
```

Yahan:

```cpp
class Result
```

`Student` ke andar hai.

Isliye ye **nested class** hai.

---

# 6. Friend Class vs Nested Class

Ye dono same nahi hain.

## Friend Class

```cpp
class Student {
    friend class Result;
};
```

Meaning:

> `Result` ko `Student` ke private/protected members access karne ki permission hai.

---

## Nested Class

```cpp
class Student {

    class Result {
    };
};
```

Meaning:

> `Result` class `Student` ke andar defined hai.

---

# 7. Dono ko ek saath use kar sakte hain?

Haan.

Example:

```cpp
#include <iostream>
using namespace std;

class Student {

private:
    int marks = 95;

public:

    // Friendship
    friend class Result;

    // Nested class
    class Result {

    public:

        void showMarks(Student s) {
            cout << "Marks: " << s.marks << endl;
        }
    };
};

int main() {

    Student s;

    Student::Result r;

    r.showMarks(s);

    return 0;
}
```

### Output

```text
Marks: 95
```

Yahan `Result` ke saath **do concepts** hain:

```cpp
friend class Result;
```

➡️ Friendship

and

```cpp
class Result {
};
```

➡️ Nested class definition

---

# 8. Sabse important confusion

Tum ye mat sochna:

```cpp
friend class Result;
```

aur

```cpp
class Result {
};
```

same cheez hain.

### Nahi ❌

Dono ka kaam alag hai.

| Code                            | Meaning                                     |
| ------------------------------- | ------------------------------------------- |
| `friend class Result;`          | Result ko friendship/access permission dena |
| `class Result { };`             | Result class ko define karna                |
| `class Result` inside `Student` | Result ko nested class banana               |

---

# 9. "Declare" vs "Define" — Super Easy

## Declaration

Compiler ko batana:

> "Aisi cheez exist karti hai."

Example:

```cpp
friend class Result;
```

---

## Definition

Actual implementation/body dena:

```cpp
class Result {

public:

    void show() {
        cout << "Hello";
    }
};
```

Yahan actual class create/define ho rahi hai.

---

# 10. Kya dono ek hi jagah likh sakte hain?

Agar tumhara question hai:

> "Kya `friend class Result;` aur `class Result { ... };` ko ek hi statement mein combine kar sakte hain?"

### No ❌

Aise nahi:

```cpp
friend class Result {
    // ❌ invalid
};
```

Friend declaration ka syntax:

```cpp
friend class Result;
```

hota hai.

Aur class definition:

```cpp
class Result {
    // ...
};
```

hoti hai.

---

# 11. Ek important point

Agar `Result` ko `Student` ke andar define kar diya:

```cpp
class Student {

    class Result {
    };
};
```

toh `Result` **nested class** hai.

Sirf nested hone se ye automatically "friend class declaration" nahi ban jata.

### Yaad rakho:

```text
Nested
  ↓
Class kahan defined hai?
  ↓
Student ke andar
```

```text
Friend
  ↓
Kisko private/protected access ki permission hai?
  ↓
Result ko
```

---

# 12. Interview mein kaise explain karna hai?

Interviewer pooche:

### "What is a friend class?"

Tum bolo:

> **A friend class is a class that is given permission to access the private and protected members of another class. We declare it using the `friend` keyword.**

Example:

```cpp
class Student {
private:
    int marks;

    friend class Result;
};
```

---

### Agar interviewer pooche:

**"Is friend class the same as nested class?"**

Answer:

> **No. A friend class is about access permission, while a nested class is a class defined inside another class. They are two different concepts, although they can be used together.**

---

# 13. One-Line Memory Trick 🧠

### Friend = Permission 🔑

```cpp
friend class Result;
```

Means:

> **"Result ko mere private members access karne ki permission hai."**

### Nested = Location 📦

```cpp
class Student {
    class Result {
    };
};
```

Means:

> **"Result class Student ke andar hai."**

---

# Final Cheat Sheet

```cpp
class Student {

private:

    int marks = 95;

    // FRIEND → permission
    friend class Result;

    // NESTED → location
    class Result {

    public:

        void showMarks(Student s) {
            cout << s.marks;
        }
    };
};
```

### Remember:

```text
friend class
     ↓
ACCESS / PERMISSION 🔑

nested class
     ↓
LOCATION / INSIDE 📦

class definition
     ↓
ACTUAL CLASS BODY 🏗️
```

**Golden Rule:**

> **Friend class batati hai "kaun access kar sakta hai", aur nested class batati hai "class kahan defined hai".**
