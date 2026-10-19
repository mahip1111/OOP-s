# C++ OOP --- Super Easy Interview Notes

> Ye README C++ OOP ke un concepts ko **super easy Hinglish** me explain
> karta hai jo humne ab tak padhe hain.\
> Goal: **concept samajhna + code likhna + interviewer ke follow-up
> questions handle karna**.

------------------------------------------------------------------------

# 📚 Table of Contents

1.  [Class and Object](#1-class-and-object)
2.  [Data Members and Member
    Functions](#2-data-members-and-member-functions)
3.  [Access Modifiers](#3-access-modifiers)
4.  [Constructor](#4-constructor)
5.  [Default Constructor](#5-default-constructor)
6.  [Parameterized Constructor](#6-parameterized-constructor)
7.  [Constructor Overloading](#7-constructor-overloading)
8.  [Destructor](#8-destructor)
9.  [Constructor vs Destructor](#9-constructor-vs-destructor)
10. [this Pointer](#10-this-pointer)
11. [Dot Operator vs this-\>](#11-dot-operator-vs-this-)
12. [Stack vs Heap Objects](#12-stack-vs-heap-objects)
13. [Object Memory](#13-object-memory)
14. [Static Data Members](#14-static-data-members)
15. [Static Member Functions](#15-static-member-functions)
16. [Static vs Non-Static](#16-static-vs-non-static)
17. [const in OOP](#17-const-in-oop)
18. [Const Data Members](#18-const-data-members)
19. [Const Member Functions](#19-const-member-functions)
20. [Const Objects](#20-const-objects)
21. [this and const](#21-this-and-const)
22. [Inheritance](#22-inheritance)
23. [Polymorphism](#23-polymorphism)
24. [Compile-Time Polymorphism](#24-compile-time-polymorphism)
25. [Run-Time Polymorphism](#25-run-time-polymorphism)
26. [Function Overloading vs
    Overriding](#26-function-overloading-vs-overriding)
27. [Virtual Function](#27-virtual-function)
28. [Virtual Destructor](#28-virtual-destructor)
29. [RAII](#29-raii)
30. [Important Interview Questions](#30-important-interview-questions)
31. [One-Page Revision](#31-one-page-revision)

------------------------------------------------------------------------

# 1. Class and Object

## 🧠 Class kya hai?

Class ek **blueprint/template** hai.

Real-life example:

``` text
Class = House ka blueprint
Object = Blueprint se bana actual house
```

C++:

``` cpp
class Student {
public:
    string name;
    int age;
};
```

Yahan `Student` ek class hai.

------------------------------------------------------------------------

## 🧠 Object kya hai?

Class se jo actual entity banti hai usko object bolte hain.

``` cpp
Student s1;
Student s2;
```

Yahan:

``` text
Student → class
s1      → object
s2      → object
```

Har object ke paas apna data hota hai.

``` cpp
s1.name = "Rahul";
s2.name = "Shivam";
```

------------------------------------------------------------------------

# 2. Data Members and Member Functions

Class ke andar mainly do important cheezein hoti hain:

### Data Members

Object ka data:

``` cpp
string name;
int age;
```

### Member Functions

Object ka behavior:

``` cpp
void sleep() {
    cout << name << " is sleeping";
}
```

Simple:

``` text
Data member   → object kya hai
Member function → object kya kar sakta hai
```

------------------------------------------------------------------------

# 3. Access Modifiers

C++ me commonly:

``` text
public
private
protected
```

## public

Bahar se access kar sakte ho:

``` cpp
Student s1;
s1.name = "Rahul";
```

`class` me members by default `private` hote hain. Isliye agar `name`
ke pehle `public:` na likhen, to bahar se:

``` cpp
s1.name = "Rahul";
```

error dega. `public:` ka use un members ko class ke bahar accessible
banane ke liye hota hai.

## private

Bahar se directly access nahi kar sakte.

``` cpp
class Student {
private:
    int age;
};
```

Then:

``` cpp
Student s1;
s1.age = 20;   // ❌ Error
```

## protected

Class aur derived classes ke andar access hota hai.

------------------------------------------------------------------------

## ⭐ Important

`class` me default access modifier:

``` cpp
private
```

`struct` me default:

``` cpp
public
```

------------------------------------------------------------------------

# 4. Constructor

Constructor ek **special member function** hai jo object create hote hi
automatically call hota hai.

Example:

``` cpp
class Student {
public:
    Student() {
        cout << "Constructor called";
    }
};
```

Object:

``` cpp
Student s1;
```

Automatically:

``` text
Object created
     ↓
Constructor called
```

------------------------------------------------------------------------

## Constructor ki properties

Constructor:

-   Class ke same naam ka hota hai.
-   Return type nahi hota.
-   `void` bhi nahi likhte.
-   Object creation ke time automatically call hota hai.
-   Overload ho sakta hai.
-   Constructor virtual nahi ho sakta.

Correct:

``` cpp
Student() {
}
```

Wrong:

``` cpp
void Student() {
}
```

------------------------------------------------------------------------

# 5. Default Constructor

Jis constructor me koi parameter nahi hota:

``` cpp
Student() {
    cout << "Hello";
}
```

Ye default constructor hai.

Call:

``` cpp
Student s1;
```

------------------------------------------------------------------------

# 6. Parameterized Constructor

Jis constructor me parameters hote hain:

``` cpp
class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }
};
```

Object:

``` cpp
Student s1("Rahul", 20);
```

------------------------------------------------------------------------

## Better way: Initializer List

``` cpp
Student(string n, int a)
    : name(n), age(a) {
}
```

Ye especially `const` data members aur references ke liye important hai.

------------------------------------------------------------------------

# 7. Constructor Overloading

Ek class me multiple constructors ho sakte hain, bas parameter list
different honi chahiye.

``` cpp
class Student {
public:

    Student() {
    }

    Student(string name) {
    }

    Student(string name, int age) {
    }
};
```

This is:

> Constructor Overloading

Ye **compile-time polymorphism** ka example hai.

------------------------------------------------------------------------

# 8. Destructor

Destructor object destroy hone par automatically call hota hai.

Syntax:

``` cpp
~Student() {
    cout << "Destructor called";
}
```

Notice:

``` text
Constructor → Student()
Destructor  → ~Student()
```

Destructor ke naam ke aage `~` hota hai.

------------------------------------------------------------------------

## Destructor kab call hota hai?

Stack object ke case me jab object scope se bahar chala jata hai.

``` cpp
int main() {
    Student s1;
}
```

Flow:

``` text
s1 created
   ↓
constructor
   ↓
s1 use
   ↓
main/scope end
   ↓
destructor
```

## Destructor ke andar data members

Destructor body execute hote waqt object ke data members abhi available
rehete hain. Isliye destructor ke andar:

``` cpp
~Student() {
    cout << name;
}
```

`name` print ho sakta hai. Destructor complete hone ke baad object ke
members destroy hote hain aur object ki lifetime end hoti hai.

## Kya destructor manually call kar sakte hain?

Normally destructor ko manually call nahi karte. Compiler scope ke end par
automatically call karta hai.

Technically ye possible hai:

``` cpp
s1.~Student();
```

Lekin stack object ke liye generally aisa nahi karna chahiye. Manual call
ke baad object ki lifetime end ho jati hai, aur scope ke end par compiler
dobara destructor call kar sakta hai. Isse undefined behavior ho sakta hai.

## Agar destructor na likhen to?

Agar class me destructor declare nahi kiya gaya, to compiler normally ek
implicit destructor generate karta hai. Simple class jisme manual resource
management nahi hai, uske liye ye destructor usually enough hota hai.

## Destructor ki limitations

Destructor:

-   Parameters nahi le sakta.
-   Return type nahi hota.
-   Overload nahi ho sakta; ek class ka sirf ek destructor hota hai.
-   `virtual` ho sakta hai.

Destructor ke parameters na hone aur overload na hone ka reason C++
language rule hai.

------------------------------------------------------------------------

# 9. Constructor vs Destructor

  Constructor                   Destructor
  ----------------------------- ------------------------------
  Object create hone par call   Object destroy hone par call
  `Student()`                   `~Student()`
  Parameters ho sakte hain      Parameters nahi hote
  Overload ho sakta hai         Overload nahi ho sakta
  Virtual nahi ho sakta         Virtual ho sakta hai

------------------------------------------------------------------------

# 10. this Pointer

`this` ka simple meaning:

> **Current object ka address.**

Example:

``` cpp
class Student {
public:
    string name;

    void sleep() {
        cout << this->name;
    }
};
```

Agar:

``` cpp
Student s1;
s1.sleep();
```

to inside `sleep()`:

``` text
this → s1 ka address
```

Agar:

``` cpp
Student s2;
s2.sleep();
```

to:

``` text
this → s2 ka address
```

## Function Call Internally

Jab hum likhte hain:

``` cpp
s1.sleep();
```

to compiler isse roughly aise samajh sakta hai:

``` cpp
Student::sleep(&s1);
```

Yahan `s1` ka address hidden argument ke roop me pass hota hai. Function
ke andar:

``` cpp
this = &s1;
```

Isliye `this->name` current object, yani `s1`, ke `name` member ko refer
karta hai.

------------------------------------------------------------------------

# 11. Dot Operator vs this-\>

Ye bahut important distinction hai.

## Object ke bahar

``` cpp
Student s1;

s1.name = "Rahul";
```

Use:

``` text
object.member
```

So:

``` cpp
s1.name
```

is correct.

------------------------------------------------------------------------

## Class ke member function ke andar

``` cpp
void sleep() {
    cout << this->name;
}
```

Use:

``` text
this->member
```

Lekin:

``` cpp
void sleep() {
    cout << name;
}
```

bhi usually same member ko refer karta hai.

------------------------------------------------------------------------

## ⭐ Important rule

``` text
Outside class:
s1.name

Inside member function:
name
or
this->name
```

`this` ko `main()` me use nahi kar sakte, kyunki `main()` Student ka
member function nahi hai.

So:

``` cpp
this->name = "Rahul";   // ❌ inside main

s1.name = "Rahul";      // ✅
```

------------------------------------------------------------------------

# 12. Stack vs Heap Objects

## Stack

``` cpp
Student s1;
```

Usually stack object.

Constructor automatically call.

Destructor automatically call.

------------------------------------------------------------------------

## Heap

``` cpp
Student* s1 = new Student();
```

Object dynamically allocated hota hai.

Destructor normally tab call hota hai jab:

``` cpp
delete s1;
```

likhte ho.

Flow:

``` text
new
 ↓
constructor

delete
 ↓
destructor
```

`new` se banaye object ko release karne ke liye matching `delete` zaroori
hai:

``` cpp
Student* s = new Student();
delete s;
```

`delete s` destructor call karta hai aur allocated memory release karta hai.
`delete` bhoolne par memory leak ho sakta hai. Modern C++ me raw `new` aur
`delete` ki jagah smart pointers prefer kiye jate hain.

## Object kahan store hota hai?

``` cpp
Student s1;
```

Ye automatic object hai aur commonly stack storage me hota hai.

``` cpp
Student* s = new Student();
```

Is example me `Student` object dynamically allocated storage, commonly
heap, me hota hai. Pointer variable `s` khud alag storage me ho sakta hai;
pointer aur object ko same cheez nahi samajhna chahiye.

## Object lifetime

``` text
Student s1;
    ↓
constructor called
    ↓
object alive and usable
    ↓
destructor called
    ↓
object lifetime ends and storage is released
```

------------------------------------------------------------------------

# 13. Object Memory

Example:

``` cpp
class Student {
public:
    string name;
    int age;

    void sleep() {
    }
};
```

Object ke andar data members ke liye storage hota hai:

``` text
Student object

+----------------+
| name           |
+----------------+
| age            |
+----------------+
| padding        |
+----------------+
```

Member function ka code har object ke andar separately copy nahi hota.

Isliye:

``` text
s1 → data
s2 → data

sleep() → shared function code
```

------------------------------------------------------------------------

## `sizeof(Student)`

Exact size compiler/platform/alignment par depend karta hai.

``` cpp
cout << sizeof(Student);
```

Padding aur alignment ki wajah se simple addition karna reliable nahi
hai.

Example:

``` cpp
cout << sizeof(Student);
```

Class me `string` aur `int` hone par size simply:

``` cpp
sizeof(string) + sizeof(int)
```

nahi hota. Alignment, padding aur implementation details ki wajah se
result compiler aur platform par depend karta hai. Kuch 64-bit systems par
ye 40 bytes ho sakta hai, lekin 40 guaranteed nahi hai.

## Kya member function object ke size me include hota hai?

Nahi. Member function ka code har object ke andar copy nahi hota. Objects
mainly non-static data members, padding aur compiler ke kuch hidden details
store karte hain; member function code separately shared hota hai.

## Conceptual memory layout

``` text
s1

+----------------+
| string name    |
+----------------+
| int age        |
+----------------+
| padding (if any)|
+----------------+
```

------------------------------------------------------------------------

# 14. Static Data Members

Normal data member:

``` cpp
class Student {
public:
    int age;
};
```

Har object ka apna `age`:

``` text
s1.age
s2.age
```

alag-alag.

------------------------------------------------------------------------

## Static data member

``` cpp
class Student {
public:
    static int count;
};
```

Static member **class ka common member** hota hai.

Conceptually:

``` text
Student class
     |
     ↓
 one shared count
     |
  ----------
  |        |
 s1       s2
```

`count` har object ke liye separate nahi hota.

------------------------------------------------------------------------

## Static member ko define karna

Traditional C++:

``` cpp
class Student {
public:
    static int count;
};

int Student::count = 0;
```

------------------------------------------------------------------------

# 15. Static Member Functions

Example:

``` cpp
class Student {
public:
    static int count;

    static void showCount() {
        cout << count;
    }
};
```

Call kar sakte ho:

``` cpp
Student::showCount();
```

Ye sabse clear/preferred syntax hai.

------------------------------------------------------------------------

## Kya object se bhi call kar sakte hain?

C++ me technically:

``` cpp
Student s1;
s1.showCount();
```

allowed hai.

But static function class se related hai, kisi particular object se
nahi.

Therefore:

``` cpp
Student::showCount();
```

is clearer.

------------------------------------------------------------------------

# 16. Static vs Non-Static

  -----------------------------------------------------------------------
  Static                              Non-static
  ----------------------------------- -----------------------------------
  Class se related                    Object se related

  One shared member                   Har object ka separate member

  `Student::showCount()`              `s1.sleep()`

  `this` pointer nahi hota            `this` available hota hai

  Directly non-static member access   Object members access kar sakta hai
  nahi kar sakta                      
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## ⭐ Interview Trap

Static function me:

``` cpp
static void show() {
    cout << name;   // ❌
}
```

Why?

Because static function ke paas **`this` pointer nahi hota**, aur `name`
non-static member hai.

Static function directly static members access kar sakta hai:

``` cpp
static int count;

static void show() {
    cout << count;   // ✅
}
```

------------------------------------------------------------------------

# 17. const in OOP

`const` ka basic meaning:

> **Is cheez ko modify nahi karna.**

Example:

``` cpp
const int x = 10;
```

Then:

``` cpp
x = 20;   // ❌
```

------------------------------------------------------------------------

# 18. Const Data Members

Class:

``` cpp
class Student {
public:
    const int id;

    Student(int x) : id(x) {
    }
};
```

Important:

`const` member ko constructor body me assign nahi karna chahiye:

``` cpp
Student(int x) {
    id = x;   // ❌
}
```

Instead initializer list:

``` cpp
Student(int x) : id(x) {
}
```

Reason:

> `const` member ko initialize karna hota hai; baad me assign nahi.

------------------------------------------------------------------------

# 19. Const Member Functions

Function ke end me `const`:

``` cpp
void show() const {
}
```

Meaning:

> Ye member function object ke normal data members ko modify nahi
> karega.

Example:

``` cpp
class Student {
public:
    string name;

    void show() const {
        cout << name;
    }
};
```

Inside this function:

``` cpp
name = "Rahul";   // ❌
```

not allowed.

------------------------------------------------------------------------

# 20. Const Objects

``` cpp
const Student s1;
```

Const object ke liye generally sirf const member functions call kar
sakte ho.

Example:

``` cpp
class Student {
public:

    void show() const {
        cout << "Student";
    }

    void change() {
    }
};

const Student s1;

s1.show();     // ✅
s1.change();   // ❌
```

------------------------------------------------------------------------

# 21. this and const

Normal member function me:

``` cpp
this
```

current object ko refer karta hai.

Const member function me current object ko modify nahi kar sakte.

Conceptually:

``` text
normal function
this → Student* const

const function
this → const Student* const
```

Easy way:

``` text
normal function → object ko modify kar sakta hai
const function  → object ko modify nahi kar sakta
```

------------------------------------------------------------------------

# 22. Inheritance

Inheritance ka simple meaning:

> Ek class doosri class ke features use karti hai.

Example:

``` cpp
class Animal {
public:
    void eat() {
        cout << "Eating";
    }
};

class Dog : public Animal {
};
```

Now:

``` cpp
Dog d;
d.eat();
```

Dog ne Animal se `eat()` inherit kiya.

------------------------------------------------------------------------

## Terms

``` text
Animal → Base/Parent class
Dog    → Derived/Child class
```

------------------------------------------------------------------------

# 23. Polymorphism

Poly = many

Morphism = forms

Simple meaning:

> Same interface/name, different behavior.

C++ me mainly:

``` text
Polymorphism
     |
     +---- Compile-time
     |
     +---- Run-time
```

------------------------------------------------------------------------

# 24. Compile-Time Polymorphism

Decision compile time par hota hai.

Main examples:

1.  Function overloading
2.  Operator overloading

------------------------------------------------------------------------

## Function Overloading

Same function name, different parameter list.

``` cpp
class Calculator {
public:

    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

Call:

``` cpp
Calculator c;

c.add(2, 3);
c.add(2, 3, 4);
```

Compiler parameter list dekhkar decide karta hai kaunsa function call
karna hai.

------------------------------------------------------------------------

## ⭐ Important

Sirf return type change karke overloading nahi hoti.

Wrong:

``` cpp
int add(int a);
double add(int a);   // ❌
```

------------------------------------------------------------------------

# 25. Run-Time Polymorphism

Run time par decide hota hai ki kaunsa overridden function execute hoga.

Iske liye commonly:

``` text
Inheritance
+
Function overriding
+
virtual function
```

Example:

``` cpp
class Animal {
public:
    virtual void animalSound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void animalSound() override {
        cout << "Dog barks";
    }
};
```

Now:

``` cpp
Animal* a = new Dog();

a->animalSound();
```

Output:

``` text
Dog barks
```

Because function is virtual.

------------------------------------------------------------------------

# 26. Function Overloading vs Overriding

## Overloading

Same class usually:

``` cpp
add(int, int)
add(int, int, int)
```

Parameter list different.

Compile-time polymorphism.

------------------------------------------------------------------------

## Overriding

Parent-child relationship:

``` cpp
class Animal {
public:
    virtual void sound() {
    }
};

class Dog : public Animal {
public:
    void sound() override {
    }
};
```

Same function signature.

Run-time polymorphism when used through a base
interface/reference/pointer with virtual dispatch.

------------------------------------------------------------------------

# 27. Virtual Function

`virtual` tells C++:

> Runtime par actual object ka function choose karo.

Example:

``` cpp
class Animal {
public:
    virtual void sound() {
        cout << "Animal";
    }
};
```

Derived:

``` cpp
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog";
    }
};
```

Then:

``` cpp
Animal* ptr = new Dog();

ptr->sound();
```

Output:

``` text
Dog
```

Without `virtual`, base pointer se call karne par base version can be
selected for a non-virtual member.

------------------------------------------------------------------------

# 28. Virtual Destructor

Inheritance me base class ka destructor virtual banana important ho
sakta hai.

``` cpp
class Animal {
public:
    virtual ~Animal() {
    }
};
```

Then:

``` cpp
Animal* ptr = new Dog();
delete ptr;
```

Virtual destructor ensures proper derived-to-base destruction.

Base pointer se derived object delete karte waqt virtual destructor zaroori
ho sakta hai:

``` cpp
class Student {
public:
    virtual ~Student() {}
};
```

Isse derived class ka destructor pehle aur base class ka destructor baad me
call hota hai. Agar base class ko polymorphic base ki tarah use karna ho,
to destructor ko virtual banana common best practice hai.

------------------------------------------------------------------------

# 29. RAII

RAII:

> Resource Acquisition Is Initialization.

Simple idea:

``` text
Resource acquire
      ↓
Constructor/object setup

Resource release
      ↓
Destructor
```

C++ me resource management ke liye bahut important concept hai.

Examples of resources:

-   Dynamic memory
-   File handles
-   Locks
-   Sockets

Modern C++ me RAII ki wajah se smart pointers aur standard library
containers bahut useful hain.

Is example me manually resource manage nahi ho raha, phir bhi constructor
aur destructor object lifetime dikhate hain. General idea:

``` text
Constructor → resource acquire/initialize
Destructor  → resource release/cleanup
```

Examples:

-   `std::unique_ptr` object destroy hone par memory release karta hai.
-   `std::lock_guard` scope end par lock release karta hai.
-   `std::fstream` object destroy hone par file close kar sakta hai.

RAII ka fayda ye hai ki cleanup exception ya early return ke case me bhi
object ke scope ke saath automatically hota hai.

------------------------------------------------------------------------

# 30. Important Interview Questions

## Class/Object

### Q1. What is a class?

> Class is a blueprint/user-defined type used to create objects.

### Q2. What is an object?

> Object is an instance of a class.

### Q3. Class aur object me difference?

``` text
Class  → blueprint
Object → actual instance
```

------------------------------------------------------------------------

## Constructor

### Q4. Constructor kya hai?

> Special member function automatically called when an object is
> initialized/created.

### Q5. Constructor ka return type?

> No return type, not even `void`.

### Q6. Constructor overload ho sakta hai?

> Yes.

### Q7. Constructor virtual ho sakta hai?

> No.

Reason:

> Constructor object create karta hai, jabki virtual function ke liye
> object ka pehle se exist karna zaroori hota hai.

### Q8. Constructor inherit hota hai?

> Constructors are not inherited as ordinary member functions.

Simple answer:

> No. Har class ka apna constructor hota hai.

------------------------------------------------------------------------

## Destructor

### Q9. Destructor kya hai?

> Special member function used when an object is destroyed.

### Q10. Destructor overload ho sakta hai?

> No. A class has one destructor.

### Q11. Destructor virtual ho sakta hai?

> Yes.

### Q12. Destructors kis order me call hote hain?

Local automatic objects generally **reverse order of construction** me
destroy hote hain.

Example:

``` cpp
Student s1;
Student s2;
```

Destruction:

``` text
s2
↓
s1
```

### Destructor and Memory Follow-up Questions

#### Destructor ke andar `name` kyun print kar sakte hain?

Destructor body execute hone tak object ke members available rehte hain.
Isliye `s2.name` ya simply `name` destructor ke andar print ho sakta hai.
Destructor complete hone ke baad members destroy hote hain aur storage
release hota hai.

#### Kya destructor manually call kar sakte hain?

Technically possible:

``` cpp
s1.~Student();
```

Lekin stack object ke liye normally nahi karna chahiye. Object ki lifetime
manual call se end ho sakti hai, aur scope ke end par automatic destructor
call hone par undefined behavior ho sakta hai.

#### Destructor absent ho to kya hota hai?

Compiler normally implicit destructor generate karta hai. Simple class jisme
manual resource management nahi hai, uske liye compiler-generated
destructor enough hota hai.

#### Destructor parameters kyun nahi leta?

Ye C++ language rule hai. Destructor parameters nahi le sakta aur overload
bhi nahi ho sakta. Har class ka sirf ek destructor hota hai.

#### Kya destructor virtual ho sakta hai?

Yes. Base pointer se derived object delete karte waqt proper destruction ke
liye virtual destructor important hota hai:

``` cpp
virtual ~Student() {}
```

#### `Student s1;` kahan store hota hai?

Normally automatic local object stack storage me hota hai.

#### Dynamic allocation kaise hoti hai?

``` cpp
Student* s = new Student();
```

Object commonly heap storage me hota hai. `delete s;` destructor call
karta hai aur allocated memory release karta hai.

#### Object ka size kaise check karte hain?

``` cpp
cout << sizeof(Student);
```

Size simply `sizeof(string) + sizeof(int)` nahi hota. Alignment, padding,
compiler aur platform ke according size change ho sakta hai.

#### Kya member function object ke size me hota hai?

No. Member function code separately stored/shared hota hai. Object me
mainly data members, padding aur kuch hidden implementation details hote
hain.

#### RAII kya hai?

RAII me resource acquisition/initialization constructor ke saath aur
resource cleanup destructor ke saath tie hota hai. Isse scope end par
cleanup automatically ho jata hai.

------------------------------------------------------------------------

# `this` Pointer Interview Questions

### Q13. What is `this`?

> `this` is a pointer that refers to the current object in a non-static
> member function.

### Why use `this`?

Both forms work inside a member function:

``` cpp
cout << name;
cout << this->name;
```

> `this` removes ambiguity and explicitly refers to the current object's
> members.

### What is the type of `this` inside `Student`?

``` cpp
Student* const
```

Meaning:

> `this` is a constant pointer. It cannot point to another object.

### Q14. `this` static function me hota hai?

> No. Static member functions don't have a `this` pointer.

### Q15. `s1.name` vs `this->name`?

``` text
s1.name      → object ke bahar
this->name   → current object ko member function ke andar refer karne ke liye
```

### Q16. Kya `this->name` `main()` me use kar sakte hain?

> No. `main()` Student ka member function nahi hai.

------------------------------------------------------------------------

# Static Interview Questions

### Q17. Static variable kya hai?

> Class ke objects ke beech shared class-level data.

### Q18. Static function kya hai?

> Class-level member function jiske paas `this` pointer nahi hota.

### Q19. Static function non-static member ko directly access kar sakta hai?

> No.

### Q20. Static function call ka preferred way?

``` cpp
Student::showCount();
```

------------------------------------------------------------------------

# const Interview Questions

### Q21. `const` ka meaning?

> Something cannot be modified through that const access.

### Q22. Const object kya hai?

``` cpp
const Student s1;
```

Object ko modify nahi kar sakte.

### Q23. Const member function kya hai?

``` cpp
void show() const;
```

Function normal object state ko modify nahi karta.

### Q24. Const data member ko kaise initialize karte hain?

Initializer list:

``` cpp
Student(int x) : id(x) {
}
```

------------------------------------------------------------------------

# Polymorphism Interview Questions

### Q25. Polymorphism kya hai?

> Same interface/name can represent different behavior.

### Q26. Compile-time polymorphism examples?

``` text
Function overloading
Operator overloading
```

### Q27. Run-time polymorphism kaise achieve karte hain?

Commonly:

``` text
Inheritance
+
Overriding
+
Virtual function
```

### Q28. Overloading vs overriding?

``` text
Overloading:
same name
different parameters
compile time

Overriding:
parent-child
same function signature
runtime dispatch when virtual
```

------------------------------------------------------------------------

# 31. One-Page Revision

## 🔥 C++ OOP Cheat Sheet

``` text
CLASS
↓
Blueprint

OBJECT
↓
Class ka actual instance

DATA MEMBER
↓
Object ka data

MEMBER FUNCTION
↓
Object ka behavior

CONSTRUCTOR
↓
Object initialize/create hone par automatically called

DESTRUCTOR
↓
Object destroy hone par automatically called

this
↓
Current object ka pointer

.
↓
Object ke member ko access karna

->
↓
Pointer ke through member access

STATIC MEMBER
↓
Class ke objects ke beech shared

STATIC FUNCTION
↓
Class-level function
No this pointer

const DATA MEMBER
↓
Initialize once

const MEMBER FUNCTION
↓
Object state modify nahi karta

INHERITANCE
↓
Child class parent ke features use karti hai

POLYMORPHISM
↓
One interface, multiple behavior

COMPILE-TIME
↓
Overloading

RUN-TIME
↓
Overriding + virtual dispatch

VIRTUAL
↓
Runtime par correct overridden function choose karne me help

RAII
↓
Resource lifetime ko object lifetime se tie karna
```

------------------------------------------------------------------------

# 🧪 Complete Example

Ye code almost saare basic concepts ko ek saath connect karta hai:

``` cpp
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;

    static int count;

    Student() {
        count++;
        cout << "Constructor called\n";
    }

    Student(string name, int age)
        : name(name), age(age) {
        count++;
        cout << "Parameterized constructor called\n";
    }

    void sleep() {
        cout << this->name << " is sleeping\n";
    }

    void show() const {
        cout << name << " " << age << "\n";
    }

    static void showCount() {
        cout << "Students: " << count << "\n";
    }

    ~Student() {
        cout << this->name << " destructor called\n";
    }
};

int Student::count = 0;

int main() {

    Student s1;

    s1.name = "Rahul";
    s1.age = 20;

    s1.sleep();
    s1.show();

    Student s2("Shivam", 21);

    s2.sleep();
    s2.show();

    Student::showCount();

    return 0;
}
```

------------------------------------------------------------------------

# 🎯 Interview Mindset

Interviewer code dekar sirf output nahi puchta.

Wo ek line se multiple concepts test kar sakta hai.

For example:

``` cpp
Student s1;
```

Is ek line se questions:

``` text
What is Student?
What is s1?
Where is s1 stored?
Which constructor is called?
When will destructor be called?
What is object's lifetime?
```

Similarly:

``` cpp
s1.sleep();
```

se:

``` text
What is member function?
What is this?
What does this->name mean?
What happens internally?
```

And:

``` cpp
static void showCount();
```

se:

``` text
What is static?
Does it have this?
Can it access non-static members?
How do you call it?
```

------------------------------------------------------------------------

# ⭐ Most Important Rules to Memorize

### Rule 1

``` cpp
Student s1;
```

means:

> Create a Student object.

------------------------------------------------------------------------

### Rule 2

``` cpp
s1.name
```

means:

> Access `name` using object `s1`.

------------------------------------------------------------------------

### Rule 3

``` cpp
this->name
```

means:

> Current object ke `name` member ko access karo.

------------------------------------------------------------------------

### Rule 4

``` cpp
Student::showCount();
```

means:

> Student class ka static function call karo.

------------------------------------------------------------------------

### Rule 5

Static function:

``` text
No this pointer
```

------------------------------------------------------------------------

### Rule 6

Const member function:

``` cpp
void show() const
```

means:

> Function object ki normal state modify nahi karega.

------------------------------------------------------------------------

### Rule 7

Constructor:

``` cpp
Student()
```

Destructor:

``` cpp
~Student()
```

------------------------------------------------------------------------

### Rule 8

Objects generally:

``` text
Create → Constructor
Use
Destroy → Destructor
```

------------------------------------------------------------------------

### Rule 9

Local objects:

``` text
First created → Last destroyed
```

Example:

``` cpp
Student s1;
Student s2;
```

Destruction:

``` text
s2
↓
s1
```

------------------------------------------------------------------------

### Rule 10

Polymorphism:

``` text
Compile-time → Overloading
Run-time    → Virtual overriding
```

------------------------------------------------------------------------

# 🚀 Final Learning Order

OOP ko isi order me strong karo:

``` text
1. Class
      ↓
2. Object
      ↓
3. Data Members
      ↓
4. Member Functions
      ↓
5. Constructor
      ↓
6. Destructor
      ↓
7. this Pointer
      ↓
8. Access Modifiers
      ↓
9. Static
      ↓
10. const
      ↓
11. Inheritance
      ↓
12. Polymorphism
      ↓
13. Overloading
      ↓
14. Overriding
      ↓
15. Virtual Function
      ↓
16. Virtual Destructor
      ↓
17. RAII
```

> **Golden idea:** Har concept ko sirf definition se mat padho. Pehle
> code dekho, phir `memory + object + lifetime` samjho, aur last me
> interviewer ke "why?" wale questions practice karo.
