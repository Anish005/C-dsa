#include<stdio.h>

typedef struct {
    float real;
    float img;
} Complex;

// Function declarations
void swap(Complex *a, Complex *b);
void print(Complex *x, Complex *y);

int main() {
    Complex x = {4.5, 6.7};
    Complex y = {3.4, 5.6};
    Complex *ptr1 = &x;
    Complex *ptr2 = &y;

    print(ptr1, ptr2);

    return 0;
}

// Function definitions
void swap(Complex *a, Complex *b) {
    Complex temp = *a;
    *a = *b;
    *b = temp;
}

void print(Complex *x, Complex *y) {
    printf("Before Swap:\n");
    printf("x: %.2f + %.2fi\n", x->real, x->img);
    printf("y: %.2f + %.2fi\n", y->real, y->img);

    // Call the swap function
    swap(x, y);

    printf("After Swap:\n");
    printf("x: %.2f + %.2fi\n", x->real, x->img);
    printf("y: %.2f + %.2fi\n", y->real, y->img);
}