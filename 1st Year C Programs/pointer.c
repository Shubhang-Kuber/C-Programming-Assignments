#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // points to arr[0]

    printf("ptr points to value: %d\n", *ptr); // 10

    ptr++; // increment pointer
    printf("After ptr++, value: %d\n", *ptr); // 20

    ptr = ptr + 2; // move forward by 2 elements
    printf("After ptr+2, value: %d\n", *ptr); // 40

    ptr--; // decrement pointer
    printf("After ptr--, value: %d\n", *ptr); // 30

    // Pointer difference
    int *start = &arr[0];
    int *end = &arr[4];
    int diff = end - start;
    printf("Number of elements between start and end: %d\n", diff); // 4

    return 0;
}

