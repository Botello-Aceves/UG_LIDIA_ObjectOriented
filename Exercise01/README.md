# Configurable Accumulator in C using Function Pointers

This project demonstrates how to simulate **object-oriented behavior in pure C** by combining:

- Structures
- Function pointers
- Internal state manipulation

The example implements a **configurable accumulator** whose behavior changes dynamically depending on the function assigned to it.

---

## 🎯 Objective

Show that in C:

> A function can receive a pointer to the same structure that contains it, allowing the function to access and modify the internal members of the structure — behaving like a *method*.

This is the conceptual foundation of:

- Strategy Pattern
- Object-Oriented design in C
- How many real C libraries are implemented internally

---

## 🧠 Concept

The structure contains:

- Internal data (`value`, `factor`)
- A function pointer (`op`)

Different functions can be assigned to `op`, and each one uses the internal members of the structure to perform a different operation.

So the **behavior of the object is not fixed** — it is defined dynamically.

---

## 🏗 Structure Definition

```c
struct Accumulator;

typedef int (*Operation)(struct Accumulator*, int);

typedef struct Accumulator {
    int value;
    int factor;
    Operation op;
} Accumulator;

---

## ⚙️ Available Operations

add → adds a value

multiply_with_factor → multiplies input by the internal factor

subtract → subtracts a value

Each function receives a pointer to the structure and uses its internal data.

---

## ▶️ How It Works
int execute(Accumulator* acc, int x) {
    return acc->op(acc, x);
}


The operation executed depends on the function assigned to op.

---

## 🧪 Example Usage
Accumulator acc1 = { .value = 0, .factor = 2, .op = add };
Accumulator acc2 = { .value = 0, .factor = 3, .op = multiply_with_factor };
Accumulator acc3 = { .value = 100, .factor = 1, .op = subtract };

printf("acc1: %d\n", execute(&acc1, 10));
printf("acc2: %d\n", execute(&acc2, 10));
printf("acc3: %d\n", execute(&acc3, 10));

Expected Output
acc1: 10
acc2: 30
acc3: 90

---

## 🧩 Why This Matters

This exact pattern is used in:

FILE implementation in stdio

Linux kernel drivers

Graphics libraries

Simulation engines

Plugin systems

Understanding this example helps students bridge:

Function pointers → modular design → object-oriented concepts in C

---

## 🛠 Compile and Run
gcc main.c -o accumulator
./accumulator