# Function Pointers with Insertion Sort (C)

This repository demonstrates how **function pointers** allow an algorithm to be completely independent from the comparison criteria.

The same **Insertion Sort** implementation can sort data using different rules **without modifying a single line of the algorithm**.

This is a powerful educational example to understand:

- Function pointers in C
- Inversion of control
- Decoupling logic from behavior
- The foundation of the Strategy Pattern (in pure C)

---

## 🎯 Key Concept

> The algorithm does not know what "less than" means.  
> It delegates that decision to a function pointer.

Insertion sort here is not a sorting algorithm.

It is a **reordering engine**.

The actual sorting logic lives in the comparator functions.

---

## 📁 Project Structure

├── build.sh
├── run.sh
├── build.bat
├── run.bat
├── main.c
├── insert_sort.c
├── insert_sort.h
├── comparators.h
└── README.md


---

## ⚙️ How It Works

The insertion sort receives a function pointer:

    typedef int (*CompareFn)(int a, int b);

And uses it like this:

    while (j >= 0 && compare(key, arr[j]))

The algorithm does not know the comparison rule.

We can change the sorting behavior by simply passing a different function.

---

## 🧪 What Is Demonstrated

The same array is sorted using:

- Ascending order

- Descending order

- Absolute value

- Even numbers first

Without changing the insertion sort implementation.

---

## 🐧 Linux / macOS (bash)
Build
./build.sh

Run
./run.sh

---

## 🪟 Windows (MinGW)

This project can be compiled on Windows using MinGW.

1) Verify MinGW installation

Make sure gcc is available from the command line:

    gcc --version

2) Build

Double click:

    build.bat


or from CMD:

    build.bat

3) Run
    run.bat

---

## 💡 Educational Takeaway

Notice:

- The algorithm never changes
- Only the comparator changes
- The code is portable across Linux, macOS, and Windows
- This is the conceptual foundation of how std::sort works in C++

---

## ▶️ Expected Output

You will see the same data ordered in different ways depending on the comparator function used.

---

## 🧠 Final Message

Insertion sort is not a sorting algorithm.
It is a reordering engine driven by a function pointer.