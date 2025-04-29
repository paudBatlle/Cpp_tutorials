# Phase 1: C++ Fundamentals - Theory & Exercises

This phase focuses on building a solid foundation in modern C++ syntax, object-oriented principles, memory management, and the standard library.

## Module 1.1: Transition & Core Syntax

### Goal
Get comfortable with the basic syntax, compilation process, data types, control flow, functions, and I/O in C++.

---

### Theory

#### Basic Structure & Compilation

- **Headers (`#include`)**:  
  Unlike Python's `import`, C++ uses `#include` to bring in declarations of functions, classes, etc., from standard libraries (e.g., `<iostream>`) or other files (`"myheader.h"`). This happens during the preprocessing stage before actual compilation.

- **Namespaces (`namespace`)**:  
  Used to prevent naming conflicts. The `std` namespace contains the standard library components.  
  - `using namespace std;` imports all names from `std` into the current scope (convenient for small programs/learning, but avoid in header files of larger projects).  
  - A better practice is to qualify names explicitly (e.g., `std::cout`) or use specific `using` declarations (e.g., `using std::cout;`).

- **`main` Function**:  
  The entry point of every C++ program. It must return an `int` (0 typically indicates success).

```cpp
#include <iostream> // Include standard input/output stream library

int main() { // Program entry point
    std::cout << "Hello, World!" << std::endl; // Output to console
    return 0; // Indicate successful execution
}
```

---

### Compilation Model

C++ is compiled, not interpreted like Python.

- **Preprocessor**: Handles directives like `#include`, `#define`.
- **Compiler**: Translates C++ code into machine-specific assembly/object code (.o or .obj files). Checks syntax and type errors.
- **Linker**: Combines your object code with code from libraries (like the standard library) to create a final executable file.

Contrast: Python code is typically executed line-by-line by an interpreter (though compilation to bytecode happens behind the scenes). C++ compilation is explicit and produces a standalone executable.

---

### Basic Data Types & Variables

- **Static Typing**: You must declare the type of a variable before using it, and this type generally cannot change. Contrast with Python's dynamic typing.

```cpp
int age = 30;          // Integer
double price = 19.99;  // Double-precision floating point
float temperature = 25.5f; // Single-precision float (note the 'f')
char grade = 'A';      // Single character
bool is_active = true; // Boolean (true/false)
// age = "hello"; // ERROR: Cannot assign string to int
```

- **Modifiers**: `signed`, `unsigned`, `short`, `long` can modify integer types. `const` makes a variable read-only after initialization.

```cpp
const double PI = 3.14159;
// PI = 3.14; // ERROR: Cannot assign to const variable
unsigned int positive_count = 100;
```

- **Operators**:  
  Includes most operators you know from Python/C (arithmetic `+`, `-`, `*`, `/`, `%`; logical `&&`, `||`, `!`; comparison `<`, `>`, `<=`, `>=`, `==`, `!=`).

- **Bitwise Operators** (`&`, `|`, `^`, `~`, `<<`, `>>`): More commonly used in C++ than in typical high-level Python, especially for systems programming, performance optimization, or hardware interaction.

- **Increment/Decrement** (`++`, `--`): Pre-increment (`++x`) vs. Post-increment (`x++`).

---

### Control Flow

- **if/else if/else**: Similar to Python/C.
- **switch**: Efficiently handles multiple conditions based on the value of an integer or enum.

```cpp
int option = 2;
switch (option) {
    case 1:
        std::cout << "Option 1 selected." << std::endl;
        break; // IMPORTANT: exits the switch
    case 2:
        std::cout << "Option 2 selected." << std::endl;
        break;
    default:
        std::cout << "Invalid option." << std::endl;
        break;
}
```

---

### Loops

- `while (condition) { ... }`
- `do { ... } while (condition);` (Executes the body at least once).
- `for (initialization; condition; update) { ... }` (Classic C-style loop).
- **Range-based for loop** (C++11): Much cleaner for iterating over collections (like Python's `for item in list:`).

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int number : numbers) { // Iterate over each element
        std::cout << number << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

### Functions

- **Declaration (Prototype) vs. Definition**: You can declare a function's signature (return type, name, parameters) before defining its body. This allows you to call functions defined later in the file or in other files.

```cpp
// Declaration (prototype)
int add(int a, int b);

int main() {
    int sum = add(5, 3); // Call the function
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}

// Definition (implementation)
int add(int a, int b) {
    return a + b;
}
```

- **Pass-by-Value**: A copy of the argument is passed. Changes inside the function don't affect the original. (Default for basic types).

- **Pass-by-Reference (`&`)**: An alias (reference) to the original variable is passed. Changes inside the function do affect the original. More efficient for large objects as it avoids copying.

```cpp
void increment(int& value) { // Note the '&'
    value++;
}
int main() {
    int x = 10;
    increment(x);
    std::cout << x << std::endl; // Output: 11
    return 0;
}
```

- **Pass-by-Pointer (`*`)**: The memory address of the variable is passed. The function can modify the original value via the address. Feels more like C. References are often preferred in modern C++ for non-null parameters.

```cpp
void increment_ptr(int* value_ptr) {
    if (value_ptr != nullptr) { // Always check pointers!
         (*value_ptr)++; // Dereference and increment
    }
}
int main() {
    int x = 10;
    increment_ptr(&x); // Pass the address of x
    std::cout << x << std::endl; // Output: 11
    return 0;
}
```

- **const Correctness**: Use `const` to indicate that a function won't modify a parameter passed by reference or pointer, or that a member function won't modify the object's state. This improves safety and clarity.

```cpp
void print_value(const int& value) { // Promises not to change value
   std::cout << value << std::endl;
   // value++; // ERROR: Cannot modify const reference
}
```

---

### Input/Output (`iostream`)

- **`std::cout`**: Standard output stream (usually the console). Uses the insertion operator (`<<`).
- **`std::cin`**: Standard input stream (usually the keyboard). Uses the extraction operator (`>>`).
- **`std::cerr`**: Standard error stream (unbuffered, for errors).
- **`std::endl`**: Inserts a newline character and flushes the output buffer. `'\n'` just inserts a newline (often more efficient if immediate flushing isn't needed).

- **File I/O (`fstream`)**: Include `<fstream>`. Use `std::ofstream` for writing files, `std::ifstream` for reading files. Similar `<<` and `>>` operators apply. Remember to `close()` files (or let RAII handle it, see Module 1.3).

---

### Exercises

- **Setup**: Install a C++ compiler (`g++` or `clang` recommended for Linux/macOS/WSL, MSVC via Visual Studio on Windows), a text editor/IDE (VS Code is great), and learn how to compile and run a simple "Hello, World!" program from your terminal/command line (`g++ my_program.cpp -o my_program` then `./my_program`).

- **Calculator**: Write a program that takes two numbers and an operator (`+`, `-`, `*`, `/`) as input from the user and prints the result. Handle potential division by zero.

- **Number Guessing Game**: Generate a random number. Prompt the user to guess it. Provide feedback ("too high", "too low") until they guess correctly.

- **Function Practice**:
  - Write a function `print_info(int age, double height)` that takes an age and height and prints them. Call it from `main`.
  - Write a function `swap(int& a, int& b)` that swaps the values of two integer variables using references. Test it in `main`.
  - Write a function `calculate_stats(int n1, int n2, int n3, int* sum_ptr, double* avg_ptr)` that takes three integers, calculates their sum and average, and returns these results via pointers. Test it in `main`. (This is more C-style; we'll see better ways later).

- **File Copier**: Write a program that asks the user for an input filename and an output filename. The program should read the contents of the input file and write them to the output file. Handle potential file opening errors.

- **Basic Debugging**: Set up your debugger (GDB, LLDB, or Visual Studio Debugger). Take your Calculator or Guessing Game program, set a breakpoint, run the program in debug mode, step through the code line-by-line, and inspect the values of variables.

---

## Module 1.2: Object-Oriented Programming (OOP)

### Goal
Understand classes, objects, encapsulation, inheritance, and polymorphism in C++.

---

### Theory

#### Classes & Objects

- **class**: A blueprint for creating objects. It defines data members (attributes) and member functions (methods) that operate on that data.
- **Object**: An instance of a class.
- **Encapsulation**: Bundling data and methods within a class. Access control (public, private, protected) hides internal implementation details (private) and exposes a controlled interface (public).
  - **public**: Accessible from anywhere.
  - **private**: Accessible only by member functions of the same class (and friends). Default for class.
  - **protected**: Accessible by member functions of the same class and derived classes.
- **struct vs class**: Almost identical in C++, except the default access level for struct members is public, while for class it's private. `struct` is often used for simple data aggregates without complex behavior.

```cpp
#include <string>
#include <iostream>

class Dog {
private: // Data members are typically private
    std::string name;
    int age;

public: // Methods (and constructors/destructor) are often public
    // Constructor (special method to initialize object)
    Dog(std::string n, int a) {
        name = n;
        age = a;
        std::cout << name << " constructed." << std::endl;
    }

    // Member function (method)
    void bark() {
        std::cout << name << " says: Woof!" << std::endl;
    }

    // Getter method
    int getAge() const { // 'const' means this method doesn't change the object's state
        return age;
    }

    // Setter method
    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        }
    }
}; // Don't forget the semicolon!

int main() {
    Dog myDog("Buddy", 3); // Create an object (instance) of the Dog class
    myDog.bark();         // Call a public method
    // myDog.age = 5;     // ERROR: age is private
    myDog.setAge(4);      // Use public setter
    std::cout << "Age: " << myDog.getAge() << std::endl;
    return 0;
}
```

---

### Constructors & Destructors

- **Constructor**: A special member function called automatically when an object is created. Used for initialization. Has the same name as the class and no return type.
  - **Default Constructor**: Takes no arguments. The compiler generates one if you don't define any constructors, but it does minimal initialization (doesn't initialize built-in types like int reliably!).
  - **Parameterized Constructor**: Takes arguments to initialize data members (like `Dog(string n, int a)` above).
  - **Copy Constructor (C++03 style)**: `ClassName(const ClassName& other)`. Called when an object is initialized from another object of the same type (e.g., `Dog daisy = buddy;`). The default copy constructor performs a member-wise copy. This is often okay, but problematic if the class manages raw pointers (shallow copy vs. deep copy - see Module 1.3).
  - **Move Constructor (C++11)**: `ClassName(ClassName&& other) noexcept`. Called when an object is initialized from a temporary (rvalue). Allows "stealing" resources (like dynamically allocated memory) from the temporary object instead of copying, which is much more efficient. Essential for modern C++.
- **Destructor (`~ClassName()`)**: A special member function called automatically when an object goes out of scope or is explicitly deleted (if allocated dynamically). Used for cleanup (e.g., releasing memory, closing files). Has the same name as the class, preceded by a tilde (`~`), no return type, and no parameters.

- **this Pointer**:  
  Inside a non-static member function, `this` is a pointer to the specific object instance on which the method was called. It's usually implicit, but sometimes needed explicitly (e.g., to return a reference to the current object or to disambiguate between a member variable and a parameter with the same name).

```cpp
class Example {
    int data;
public:
    Example(int data) {
        this->data = data; // 'this->data' is the member, 'data' is the parameter
    }
    Example& setData(int data) {
         this->data = data;
         return *this; // Return a reference to the current object
    }
};
```

- **static Members & Methods**:
  - **static Data Member**: Belongs to the class itself, not to individual objects. There's only one copy shared among all objects of the class. Must be defined outside the class (usually in the .cpp file).
  - **static Member Function**: Can be called using the class name (`ClassName::staticMethod()`) without needing an object instance. Can only access static data members and other static methods. Doesn't have a `this` pointer.

---

### Inheritance

- Mechanism to create a new class (Derived/Child Class) from an existing class (Base/Parent Class). The derived class inherits members (data and methods) from the base class.
- **Syntax**: `class Derived : access-specifier Base { ... };`
  - **public inheritance**: public members of Base become public in Derived, protected become protected. (Most common type - "is-a" relationship).
  - **protected inheritance**: public and protected members of Base become protected in Derived.
  - **private inheritance**: public and protected members of Base become private in Derived. ("implemented-in-terms-of" relationship).
- Constructors/Destructors are not inherited, but base class constructors are called automatically before the derived class constructor runs. Destructors are called in reverse order (derived then base).
- **Method Overriding**: A derived class can provide its own implementation for a method inherited from the base (if the method is not private in the base).

```cpp
class Animal {
public:
    void eat() { std::cout << "Animal eats." << std::endl; }
};

class Cat : public Animal { // Public inheritance: Cat "is-a" Animal
public:
    void meow() { std::cout << "Cat meows." << std::endl; }
    void eat() { std::cout << "Cat eats fish." << std::endl; } // Overrides Animal::eat
};

int main() {
    Cat myCat;
    myCat.eat(); // Calls Cat::eat
    myCat.meow();
    // myCat can also access Animal's public members if not overridden
    return 0;
}
```

---

### Polymorphism (Dynamic Dispatch)

- Means "many forms". Allows treating objects of different derived classes through a common base class interface (usually using pointers or references).
- **virtual Functions**: A member function declared with the `virtual` keyword in the base class. When called through a base class pointer or reference, the version of the function in the actual object's class (derived or base) is executed at runtime. This is dynamic dispatch.
- **override Specifier (C++11)**: Use in the derived class to indicate you intend to override a base class virtual function. Helps catch errors if the base function signature changes or wasn't virtual.
- **final Specifier (C++11)**: Use on a virtual function to prevent further overriding in derived classes, or on a class to prevent inheritance from it.
- **Abstract Base Class (ABC)**: A class with one or more pure virtual functions.
- **Pure Virtual Function**: A virtual function declared with `= 0;`. Makes the class abstract – you cannot create objects directly from an ABC. Derived classes must override pure virtual functions to become concrete (instantiable). Used to define interfaces.

```cpp
#include <iostream>
#include <vector>
#include <memory> // For smart pointers

class Shape { // Abstract Base Class (Interface)
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Shape() = default; // IMPORTANT: Virtual destructor!
};

class Circle : public Shape {
public:
    void draw() const override { // Override the pure virtual function
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

// Function that works with any Shape
void render(const Shape& shape_ref) {
    shape_ref.draw(); // Calls the correct draw() based on the actual object type
}

int main() {
    Circle c;
    Rectangle r;

    render(c); // Calls Circle::draw()
    render(r); // Calls Rectangle::draw()

    // Using base class pointers (often with smart pointers)
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Rectangle>());

    for (const auto& shape_ptr : shapes) {
        shape_ptr->draw(); // Polymorphic call through pointer
    }

    return 0;
}
```

- **Virtual Destructor**: If a class is intended to be used as a base class in polymorphic scenarios (i.e., you might delete a derived object through a base class pointer), its destructor must be declared virtual. Otherwise, only the base class destructor will be called, potentially leading to resource leaks if the derived class destructor had cleanup work to do.

---

### Exercises

- **BankAccount Class**:
  - Create a `BankAccount` class with private members for `accountHolderName` (string) and `balance` (double).
  - Implement a constructor to initialize these members.
  - Implement public methods: `deposit(double amount)`, `withdraw(double amount)` (ensure balance doesn't go negative), and `get_balance() const`.
  - Add a `display() const` method to print the account details.
  - Test your class by creating accounts, depositing, withdrawing, and displaying info.

- **Vector2D Class**:
  - Create a `Vector2D` class with private x and y coordinates (doubles).
  - Implement a constructor.
  - Implement methods `add(const Vector2D& other)` and `subtract(const Vector2D& other)` that return a new `Vector2D` object representing the result.
  - Implement a `dot_product(const Vector2D& other) const` method.
  - Implement a `print() const` method.

- **Inheritance: SavingsAccount**:
  - Derive a `SavingsAccount` class from your `BankAccount` class.
  - Add a private member for `interestRate` (double).
  - Add a constructor that initializes the base part and the interest rate.
  - Add a method `apply_interest()` that increases the balance based on the rate.
  - Override the `display()` method to include the interest rate.
  - Test creating and using `SavingsAccount` objects.

- **Polymorphism: Shapes**:
  - Implement the `Shape`, `Circle`, `Rectangle` example from the theory section above.
  - Add another derived class, e.g., `Triangle`, that also overrides `draw()`.
  - Create a `std::vector` of `Shape*` (or better, `std::unique_ptr<Shape>`) pointers.
  - Add instances of `Circle`, `Rectangle`, and `Triangle` to the vector.
  - Loop through the vector and call the `draw()` method on each element, observing the polymorphic behavior. Remember the virtual destructor in `Shape`!

- **Static Counter**: Add a static integer member to your `BankAccount` class to count how many accounts have been created. Increment it in the constructor. Add a static method `get_account_count()` to retrieve the count. Test it.

---

## Module 1.3: Memory Management (CRITICAL!)

### Goal
Understand the difference between stack and heap memory, master dynamic memory allocation (`new`/`delete`), and learn the modern C++ approach using RAII and smart pointers (`unique_ptr`, `shared_ptr`).

---

### Theory

#### Stack vs. Heap Memory

- **Stack**:
  - Memory allocated for local variables within functions, function parameters, and return values.
  - Managed automatically: Memory is allocated when entering a scope (e.g., function call, `{}`) and deallocated when leaving the scope.
  - Very fast allocation/deallocation (just moving a stack pointer).
  - Limited size (typically a few MB). Allocating too much leads to stack overflow.
  - Lifetime tied to scope.

```cpp
void myFunction() {
    int localVar = 10; // Allocated on the stack
    // ... use localVar ...
} // localVar is automatically deallocated here
```

- **Heap (Free Store)**:
  - A large pool of memory available to the program for dynamic allocation.
  - Managed manually by the programmer using `new` and `delete` (or automatically via smart pointers).
  - Slower allocation/deallocation compared to the stack (involves searching for free blocks, bookkeeping).
  - Much larger size (limited by available system RAM/virtual memory).
  - Lifetime controlled explicitly by the programmer (or smart pointer). Object exists until deleted.
  - Used when:
    - You need an object to exist beyond the scope where it was created.
    - You need to allocate a very large amount of memory that might not fit on the stack.
    - You don't know the size or number of objects needed until runtime.

---

### Pointers Revisited

- A pointer stores the memory address of another variable.
- **Declaration**: `TypeName* pointerName;` (e.g., `int* ptr;`)
- **Address-of operator (`&`)**: Gets the memory address of a variable (e.g., `ptr = &myVariable;`).
- **Dereference operator (`*`)**: Accesses the value at the address stored in the pointer (e.g., `value = *ptr;`).
- **nullptr (C++11)**: Represents a pointer that doesn't point to anything. Always initialize pointers or set them to `nullptr` after deleting to avoid dangling pointers. Check for `nullptr` before dereferencing.

---

### Dynamic Allocation: `new` and `delete` (The "Old" Way - Understand the Dangers)

- `new TypeName;`: Allocates memory on the heap for one object of `TypeName`, calls its constructor, and returns a pointer to that object.
- `new TypeName[size];`: Allocates memory on the heap for an array of `size` objects, calls their default constructors, and returns a pointer to the first element of the array.
- `delete pointer;`: Deallocates the memory pointed to by `pointer` (which must have been allocated with `new TypeName;`). Calls the object's destructor.
- `delete[] pointer;`: Deallocates the memory for an array pointed to by `pointer` (which must have been allocated with `new TypeName[size];`). Calls the destructor for each object in the array.

**CRITICAL**: Mixing `delete` and `delete[]` or forgetting to delete leads to undefined behavior (crashes, corruption) and memory leaks.

---

### Common Problems with Manual Management

- **Memory Leaks**: Forgetting to delete memory allocated with `new`. The memory remains allocated but inaccessible, wasting resources.
- **Dangling Pointers**: Using a pointer after the memory it points to has been deleted or has gone out of scope (if pointing to stack memory). Leads to crashes or unpredictable behavior.
- **Double Free**: Trying to delete the same memory twice. Leads to heap corruption and crashes.
- **Exception Safety**: If an exception occurs between `new` and `delete`, the `delete` might be skipped, causing a leak.

---

### RAII (Resource Acquisition Is Initialization)

- The Core C++ Philosophy for Resource Management.
- Bind the lifetime of a resource (heap memory, file handles, network sockets, mutex locks, etc.) to the lifetime of an object on the stack.
- Acquire the resource in the object's constructor.
- Release the resource in the object's destructor.
- Since stack objects are automatically destroyed when they go out of scope (even if an exception occurs - this is called stack unwinding), the resource is automatically released correctly.
- Smart pointers are the standard library's implementation of RAII for heap memory.

---

### Smart Pointers (C++11 and later) - The Modern Way

- **Header**: `<memory>`
- Wrapper classes that act like raw pointers but manage the lifetime of the heap-allocated object they point to using RAII.

- **std::unique_ptr<T>**:
  - Represents exclusive ownership of a dynamically allocated object (T).
  - Only one `unique_ptr` can point to a given object at any time.
  - Cannot be copied. Can be moved (transferring ownership) using `std::move()`.
  - When the `unique_ptr` goes out of scope (or is reset), it automatically deletes the managed object.
  - Very lightweight (usually the same size as a raw pointer).
  - Use `unique_ptr` by default unless you specifically need shared ownership.
  - **Creation**: `std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(constructor_args);` (C++14, preferred, exception-safe). Or `std::unique_ptr<MyClass> ptr(new MyClass(constructor_args));` (C++11).

- **std::shared_ptr<T>**:
  - Represents shared ownership of a dynamically allocated object.
  - Multiple `shared_ptr`s can point to the same object.
  - Maintains an internal reference count. The count increases when a `shared_ptr` is copied and decreases when a `shared_ptr` is destroyed or reset.
  - The managed object is automatically deleted only when the last `shared_ptr` pointing to it goes out of scope (reference count drops to zero).
  - Has some overhead compared to `unique_ptr` (for the reference count).
  - Useful for situations where multiple parts of the code need to keep an object alive, and it's unclear which part will finish using it last.
  - **Creation**: `std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(constructor_args);` (Preferred, more efficient, exception-safe). Or `std::shared_ptr<MyClass> ptr(new MyClass(constructor_args));`.

- **std::weak_ptr<T>**:
  - A non-owning "observer" of an object managed by `shared_ptr(s)`.
  - Points to an object but does not affect its reference count.
  - Used to break potential reference cycles that can occur with `shared_ptr` (e.g., Object A has a `shared_ptr` to B, and B has a `shared_ptr` to A - neither reference count will ever reach zero).
  - Cannot be dereferenced directly. You must call `.lock()` to get a temporary `shared_ptr`. If the object still exists, `lock()` returns a valid `shared_ptr`; otherwise, it returns an empty `shared_ptr`.

---

### Exercises

- **Raw Pointer Dangers**:
  - Write a function that allocates an integer on the heap using `new`, assigns a value, prints the value, and forgets to delete it. Call this function multiple times in a loop. Conceptually, understand this creates a memory leak (though detecting small leaks might require tools).
  - Write code that creates a dangling pointer (e.g., delete memory, then try to access it via the pointer). Observe the crash or undefined behavior.
  - Write code that causes a double free. Observe the crash.
  - (Optional/Advanced): If on Linux/macOS, install valgrind. Compile your leaking program with debug symbols (`-g`) and run it under `valgrind --leak-check=full ./your_program`. Observe how Valgrind reports the memory leak.

- **RAII Wrapper**:
  - Create a simple class `ResourceWrapper` that allocates an int with `new` in its constructor and deletes it in its destructor. Add a method to set/get the integer's value.
  - In `main`, create an instance of `ResourceWrapper` on the stack. Observe (e.g., by adding print statements in the constructor/destructor) that the memory is automatically managed when the wrapper object goes out of scope.
  - Create a function that throws an exception. Create the `ResourceWrapper` before calling this function inside a `try` block. Observe that the destructor is still called during stack unwinding, preventing a leak.

- **unique_ptr Practice**:
  - Refactor Exercise 1 (the leaking function) to use `std::unique_ptr<int>` and `std::make_unique<int>`. Observe that no explicit `delete` is needed and the memory is managed correctly.
  - Create a `unique_ptr` to your `BankAccount` class. Access its methods using the `->` operator (e.g., `ptr->deposit(100);`).
  - Create a function `process_account(std::unique_ptr<BankAccount> account_ptr)` that takes ownership of the pointer via move semantics. In `main`, create a `unique_ptr` and pass it to the function using `std::move()`. Verify that the pointer in `main` becomes `nullptr` after the call.

- **shared_ptr Practice**:
  - Create a `std::shared_ptr` to a `Vector2D` object using `std::make_shared`.
  - Create several copies of this `shared_ptr`. Use the `.use_count()` method to observe how the reference count changes as copies are made and destroyed (go out of scope).
  - Store `shared_ptr<BankAccount>` objects in a `std::vector`.

- **Shallow vs. Deep Copy (Conceptual)**:
  - Imagine a class `MyArray` that holds a raw pointer `int* data` allocated with `new int[size]` in the constructor and freed with `delete[] data` in the destructor.
  - Explain what happens if you use the default copy constructor (`MyArray b = a;`). (Answer: Both `a.data` and `b.data` point to the same memory. When one object is destroyed, it `delete[]`s the memory, leaving the other with a dangling pointer. When the second object is destroyed, it tries to `delete[]` the same memory again - double free!).
  - Describe how you would implement a proper copy constructor and copy assignment operator for `MyArray` to perform a deep copy (allocating new memory and copying the contents).
  - Explain how using `std::vector<int>` instead of `int* data` would solve this problem automatically (because `std::vector` handles its own memory management correctly).

---

## Module 1.4: Standard Template Library (STL) - Containers & Algorithms

### Goal
Learn to use the most common STL containers (`vector`, `map`, `string`, etc.) and algorithms for efficient data storage and manipulation.

---

### Theory

#### Introduction to STL

- A collection of powerful, generic, and efficient components built into C++.
- Key parts:
  - **Containers**: Data structures (like lists, arrays, maps).
  - **Algorithms**: Functions that operate on data (usually within containers), like sorting, searching, transforming.
  - **Iterators**: Objects that act like pointers, allowing algorithms to work generically with different container types by providing a standard way to traverse elements.

---

### Containers

- **Sequence Containers**: Ordered collections.
  - **std::vector**: (Use this most often!) Dynamic array. Elements are contiguous in memory (good for cache performance, random access). Fast access by index (`[]`), fast addition/removal at the end (`push_back`, `pop_back`). Insertion/deletion in the middle is slow (requires shifting elements). Automatically resizes when needed. Include `<vector>`.
  - **std::deque**: Double-ended queue. Similar to vector but allows fast insertion/deletion at both the beginning and the end. Elements are not necessarily contiguous. Include `<deque>`.
  - **std::list**: Doubly-linked list. Fast insertion/deletion anywhere in the list (if you have an iterator to the position). Slow random access (no `[]` operator, must traverse). Each element has overhead for next/prev pointers. Include `<list>`.

- **Associative Containers**: Store elements sorted by key. Efficient searching, insertion, deletion (typically logarithmic time).
  - **std::map<KeyType, ValueType>**: Stores key-value pairs, sorted by key. Unique keys. Include `<map>`.
  - **std::set<KeyType>**: Stores unique keys, sorted by key. Include `<set>`.
  - **std::multimap**, **std::multiset**: Allow duplicate keys.

- **Unordered Associative Containers (C++11)**: Store elements in a hash table. Average time complexity for search, insertion, deletion is constant (O(1)), but potentially linear in the worst case (due to hash collisions). No inherent ordering of elements.
  - **std::unordered_map<KeyType, ValueType>**: Key-value pairs, hashed by key. Unique keys. Often faster than `std::map` if ordering isn't needed. Include `<unordered_map>`.
  - **std::unordered_set<KeyType>**: Unique keys, hashed. Include `<unordered_set>`.
  - **std::unordered_multimap**, **std::unordered_multiset**: Allow duplicate keys.

- **Container Adapters**: Provide a different interface on top of an underlying container.
  - **std::stack**: Last-In, First-Out (LIFO). `push()`, `pop()`, `top()`. Uses `deque` by default. Include `<stack>`.
  - **std::queue**: First-In, First-Out (FIFO). `push()`, `pop()`, `front()`, `back()`. Uses `deque` by default. Include `<queue>`.
  - **std::priority_queue**: Retrieves the element with the highest priority (largest by default). `push()`, `pop()`, `top()`. Uses `vector` by default. Include `<queue>`.

---

### Iterators

- Objects that generalize pointers, allowing algorithms to traverse containers without knowing the container's internal structure.
- Each container provides methods like `begin()` (iterator to the first element) and `end()` (iterator past the last element).
- Common operations: `*it` (dereference to get value), `++it` (move to next element), `it1 == it2`, `it1 != it2`.
- Different containers provide different categories of iterators (e.g., vector has random access iterators allowing `it + 5`, while list only has bidirectional iterators allowing `++it` and `--it`).
- **Iterator Invalidation**: Performing operations like inserting/deleting elements in a container can invalidate existing iterators (make them unusable or point to the wrong place). Be careful! Check container documentation for rules (e.g., inserting into a vector might invalidate all iterators if it causes a resize).

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {10, 20, 30, 40};
    // Using iterators explicitly
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " "; // Dereference iterator to get value
    }
    std::cout << std::endl;

    // Using range-based for loop (simpler, uses iterators implicitly)
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

### Algorithms

- **Header**: `<algorithm>` (and `<numeric>` for some like `accumulate`).
- Functions that operate on ranges defined by iterators (typically `begin()` to `end()`).
- Examples:
  - `std::sort(v.begin(), v.end());` - Sorts the elements in the range.
  - `std::find(v.begin(), v.end(), value_to_find);` - Returns an iterator to the first occurrence of `value_to_find`, or `v.end()` if not found.
  - `std::copy(source.begin(), source.end(), destination.begin());` - Copies elements.
  - `std::transform(input.begin(), input.end(), output.begin(), unary_operation);` - Applies an operation to each element.
  - `std::accumulate(v.begin(), v.end(), initial_value);` - Sums up elements (from `<numeric>`).
  - `std::count_if(v.begin(), v.end(), predicate);` - Counts elements satisfying a condition.

---

### Lambda Expressions (C++11)

- Anonymous, inline functions. Extremely useful with STL algorithms.
- **Syntax**: `[capture_clause](parameters) -> return_type { body }`
  - **capture_clause**: Specifies which variables from the surrounding scope are accessible inside the lambda (`[]` none, `[=]` by copy, `[&]` by reference, `[var]` capture `var` by copy, `[&var]` capture `var` by reference, `[this]` capture `this` pointer).
  - **parameters**: Like regular function parameters.
  - `-> return_type`: Optional if the compiler can deduce it or if it returns `void`.
  - **body**: Function code.

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {1, -2, 3, -4, 5};
    int threshold = 0;

    // Count positive numbers using a lambda
    int positive_count = std::count_if(v.begin(), v.end(),
        // Lambda function starts here:
        [=](int x) -> bool { // Captures threshold by copy (=)
            return x > threshold;
        } // Lambda ends here
    );

    std::cout << "Positive count: " << positive_count << std::endl; // Output: 3

    // Add 10 to each element using transform and a lambda
    std::transform(v.begin(), v.end(), v.begin(), // Output back into v
        [](int x) { return x + 10; }
    );

    for(int val : v) { std::cout << val << " "; } // Output: 11 8 13 6 15
    std::cout << std::endl;

    return 0;
}
```

---

### std::string

- The standard C++ string class. Include `<string>`.
- Manages its own memory (dynamic character array). Much safer and easier than C-style char arrays (`char*`).
- Supports many operations: concatenation (`+`), comparison (`==`, `<`, etc.), searching (`find`), substrings (`substr`), access (`[]`), modification.

---

### Exercises

- **std::vector Basics**:
  - Create a `std::vector<int>`.
  - Use `push_back()` to add the numbers 1 through 10.
  - Iterate through the vector using a range-based for loop and print each element.
  - Access and print the element at index 5 using `[]` and `.at()` (notice `.at()` provides bounds checking).
  - Print the `.size()` and `.capacity()` of the vector. Add more elements and observe how capacity changes.
  - Use `.insert()` to insert the number 99 at index 3.
  - Use `.erase()` to remove the element at index 6. Print the final vector.

- **Word Frequency Counter**:
  - Read text from standard input (or a file) word by word.
  - Use an `std::map<std::string, int>` to store the frequency of each word.
  - Iterate through the map and print each word along with its count.
  - Repeat the exercise using `std::unordered_map`. Compare the output order (map is sorted, unordered_map is not).

- **Sorting**:
  - Create a `std::vector<std::string>` with several names. Print it.
  - Use `std::sort` to sort the vector alphabetically. Print the sorted vector.
  - Create a `std::vector<BankAccount>` (using the class from Module 1.2). Try to sort it using `std::sort`. It won't compile directly. You need to overload the `<` operator for `BankAccount` or provide a custom comparison function (or lambda) to `std::sort`. Implement one of these solutions to sort the accounts by balance.

- **Algorithms & Lambdas**:
  - Create a `std::vector<int>` with numbers from 1 to 20.
  - Use `std::find` to find the iterator pointing to the number 15. Check if the iterator is valid (not `.end()`) before dereferencing.
  - Use `std::count_if` with a lambda to count how many numbers in the vector are divisible by 3.
  - Use `std::transform` with a lambda to create a new `std::vector<int>` where each element is the square of the corresponding element in the original vector.
  - Use `std::accumulate` (from `<numeric>`) to calculate the sum of all elements in the original vector.

- **std::string Manipulation**:
  - Create two `std::string` variables. Initialize them.
  - Concatenate them using `+` and store in a third string. Print the result.
  - Use `.find()` to search for a substring within one of the strings.
  - Use `.substr()` to extract a portion of a string.
  - Use a loop and the `[]` operator to iterate through the characters of a string and print them one by one.

---

This concludes the theory and exercises for Phase 1. Take your time, experiment with the code, use your debugger, and don't hesitate to look up details on cppreference.com. Good luck!