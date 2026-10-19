# C++ Friend Function

## 📌 What is a Friend Function?

A **friend function** is a normal function that is **not a member of a class**, but it is given special permission to access the class's **private and protected members**.

Normally, a function outside the class cannot access private members.

But if we declare that function using the `friend` keyword, it gets special access.

### Simple Example

Think of a class as a private room:

```text
Private Room
----------------
salary

❌ Normal outside function
❌ Other functions

✅ Friend function
```

A friend function is like a trusted friend who is allowed to enter the private room.

---

# 📖 Complete Example

```cpp
#include <iostream>
using namespace std;

class Employee {
private:
    int salary;

public:
    Employee(int s) {
        salary = s;
    }

    // Declare friend function
    friend void displaySalary(Employee emp);
};

void displaySalary(Employee emp) {
    cout << "Salary: " << emp.salary;
}

int main() {
    Employee myEmp(50000);

    displaySalary(myEmp);

    return 0;
}
```

### Output

```text
Salary: 50000
```

---

# 🔍 Line-by-Line Explanation

## 1. Creating the Class

```cpp
class Employee {
```

We create a class named `Employee`.

A class can be thought of as a **blueprint** for creating objects.

```text
Employee
---------
salary
constructor
```

At this point, we are only defining the structure.

---

## 2. `private:`

```cpp
private:
```

`private` is an **access specifier**.

Anything declared below `private:` can normally be accessed only from inside the class.

---

## 3. Private Variable

```cpp
int salary;
```

We create an integer variable called `salary`.

Because it is under `private:`, code outside the class cannot directly access it.

For example:

```cpp
Employee e;

cout << e.salary;   // ❌ Error
```

Why?

Because `salary` is private.

---

# 4. `public:`

```cpp
public:
```

Anything declared below `public:` can be accessed from outside the class, subject to the normal rules of C++.

---

# 5. Constructor

```cpp
Employee(int s) {
    salary = s;
}
```

This is a **constructor**.

A constructor is a special function that is automatically called when an object is created.

For example:

```cpp
Employee myEmp(50000);
```

When this object is created, the constructor runs automatically.

---

## 6. Assigning the Salary

```cpp
salary = s;
```

Suppose we write:

```cpp
Employee myEmp(50000);
```

Then:

```text
s = 50000
```

So:

```cpp
salary = s;
```

becomes conceptually:

```cpp
salary = 50000;
```

The object now contains:

```text
myEmp
---------
salary = 50000
```

---

# ⭐ 7. Declaring the Friend Function

```cpp
friend void displaySalary(Employee emp);
```

This is the **most important line**.

It declares `displaySalary()` as a **friend function** of the `Employee` class.

Normally, an outside function cannot access:

```cpp
emp.salary
```

because `salary` is private.

But because we declared:

```cpp
friend void displaySalary(Employee emp);
```

the function gets special permission to access private members.

---

# ⚠️ Important: Friend Function is NOT a Member Function

This is a very important interview point.

A friend function:

* is declared inside the class using `friend`
* is defined outside the class
* is **not a member function** of the class
* can access the class's private and protected members

So:

```cpp
friend void displaySalary(Employee emp);
```

does **not** make `displaySalary()` a member function.

It only gives the function special access.

---

# 8. Defining the Friend Function

Outside the class we write:

```cpp
void displaySalary(Employee emp) {
    cout << "Salary: " << emp.salary;
}
```

Notice that we **do not write `friend` again** here.

The `friend` keyword is used when declaring the function inside the class.

---

# 9. Function Parameter

```cpp
Employee emp
```

This means the function receives an `Employee` object.

When we call:

```cpp
displaySalary(myEmp);
```

the `myEmp` object is passed to the function.

Conceptually:

```text
myEmp
  ↓
displaySalary(emp)
```

The function can then use:

```cpp
emp.salary
```

---

# 10. Accessing the Private Variable

```cpp
cout << "Salary: " << emp.salary;
```

Normally this would cause an error because:

```cpp
salary
```

is private.

But `displaySalary()` is a friend of `Employee`.

Therefore it has permission to access:

```cpp
emp.salary
```

and prints:

```text
Salary: 50000
```

---

# 11. `main()`

```cpp
int main() {
```

The program starts execution from `main()`.

---

# 12. Creating the Object

```cpp
Employee myEmp(50000);
```

An object named `myEmp` is created.

The constructor is automatically called:

```cpp
Employee(50000);
```

Inside the constructor:

```cpp
salary = s;
```

Therefore:

```text
salary = 50000
```

---

# 13. Calling the Friend Function

```cpp
displaySalary(myEmp);
```

The `displaySalary()` function is called.

The `myEmp` object is passed to it.

Then inside the function:

```cpp
emp.salary
```

is accessed.

Normally this would be illegal, but `displaySalary()` is a friend function.

---

# 14. `return 0`

```cpp
return 0;
```

This indicates that the program finished successfully.

---

# 🔄 Complete Program Flow

The complete flow is:

```text
Program starts
      ↓
main()
      ↓
Employee myEmp(50000)
      ↓
Constructor runs
      ↓
salary = 50000
      ↓
displaySalary(myEmp)
      ↓
Friend function receives Employee object
      ↓
Accesses private salary
      ↓
Prints "Salary: 50000"
      ↓
return 0
      ↓
Program ends
```

---

# 🧠 Visual Understanding

```text
              Employee Class
        ┌───────────────────────┐
        │                       │
        │ private:              │
        │     salary            │
        │                       │
        │ public:               │
        │     Employee()        │
        │                       │
        │ friend:               │
        │     displaySalary()   │
        │                       │
        └───────────┬───────────┘
                    │
                    │ special permission
                    ↓
           displaySalary()
                    │
                    ↓
              emp.salary
                    │
                    ↓
                 50000
                    │
                    ↓
              Printed
```

---

# ❓ Why Do We Need a Friend Function?

Without `friend`:

```cpp
class Employee {
private:
    int salary;
};

void displaySalary(Employee emp) {
    cout << emp.salary;   // ❌ Error
}
```

This produces an error because `salary` is private.

But if we write:

```cpp
class Employee {
private:
    int salary;

public:
    friend void displaySalary(Employee emp);
};
```

then:

```cpp
void displaySalary(Employee emp) {
    cout << emp.salary;   // ✅ Allowed
}
```

The function now has special permission.

---

# 🎯 Key Concept

Think of it like this:

```text
private member
     ↓
Normally inaccessible
     ↓
friend keyword
     ↓
Special permission
     ↓
Friend function can access it
```

---

# 📌 Important Interview Points

### 1. Is a friend function a member function?

**No.**

A friend function is **not a member function** of the class.

It is an outside/normal function that has been given special access.

---

### 2. Can a friend function access private members?

**Yes.**

A friend function can access the private members of the class that declared it as a friend.

---

### 3. Can a friend function access protected members?

**Yes.**

A friend function can access both:

```text
private
protected
```

members of the class that declared it as a friend.

---

### 4. Where is the `friend` keyword used?

The function is declared as a friend **inside the class**:

```cpp
friend void displaySalary(Employee emp);
```

The function is normally defined outside:

```cpp
void displaySalary(Employee emp) {
    ...
}
```

---

### 5. Does `friend` make the function a class member?

**No.**

It only gives the function special access.

---

### 6. Is friendship automatically mutual?

**No.**

Friendship is **one-way**.

If class `A` makes a function a friend:

```cpp
friend void someFunction();
```

then `someFunction()` gets access to `A`'s private/protected members.

It does not automatically give access to another class's private members.

---

# 📝 Quick Revision

```text
Friend Function
      │
      ├── Not a member function
      │
      ├── Declared using `friend`
      │
      ├── Usually defined outside the class
      │
      ├── Can access private members
      │
      ├── Can access protected members
      │
      └── Friendship is one-way
```

---

# 💡 One-Line Definition for Interview

> **A friend function is a non-member function that is granted special permission by a class to access its private and protected members.**

---

# ⭐ Easy Memory Trick

Remember:

**Friend = Outside function + Special Permission**

```text
Outside Function
       +
Special Permission
       ↓
 Friend Function
```
