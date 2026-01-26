#include <stdio.h>

/* Forward declaration */
struct Accumulator;

/* Definición del tipo de apuntador a función */
typedef int (*Operation)(struct Accumulator*, int);

/* Definición de la estructura */
typedef struct Accumulator {
    int value;
    int factor;
    Operation op;   // <- Apuntador a función
} Accumulator;


/* Funciones que operan sobre la estructura */

int add(Accumulator* acc, int x) {
    acc->value += x;
    return acc->value;
}

int multiply_with_factor(Accumulator* acc, int x) {
    acc->value += x * acc->factor;  // usa miembro interno "factor"
    return acc->value;
}

int subtract(Accumulator* acc, int x) {
    acc->value -= x;
    return acc->value;
}


/* Función que ejecuta la operación asignada */
int execute(Accumulator* acc, int x) {
    return acc->op(acc, x);
}


int main() {

    Accumulator acc1 = { .value = 0, .factor = 2, .op = add };
    Accumulator acc2 = { .value = 0, .factor = 3, .op = multiply_with_factor };
    Accumulator acc3 = { .value = 100, .factor = 1, .op = subtract };

    printf("acc1: %d\n", execute(&acc1, 10));  // 10
    printf("acc2: %d\n", execute(&acc2, 10));  // 30 (10 * factor 3)
    printf("acc3: %d\n", execute(&acc3, 10));  // 90

    return 0;
}
