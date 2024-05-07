#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    int* ptr_a = &a;
    int* ptr_b = &b;

    *ptr_a = *ptr_a + *ptr_b;
    *ptr_b = *ptr_a - *ptr_b;
    *ptr_a = *ptr_a - *ptr_b;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}