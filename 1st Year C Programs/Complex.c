#include<stdio.h>
#include<stdlib.h>

 struct complex{
    int real;
    int imag;
};

struct complex summmation (struct complex c1, struct complex c2);

int main(){
    struct complex num1, num2, result;
    printf("Enter the real and imaginary part of num1\n");
    scanf("%i %i", &num1.real, &num1.imag);

    printf("Enter the real and imaginary part of num2\n");
    scanf("%i %i", &num2.real, &num2.imag);

    result = summmation(num1, num2);
    printf("Sum = %.2i + %.2ii\n", result.real, result.imag);
}

struct complex summmation (struct complex c1, struct complex c2){
    struct complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag+ c2.imag;
    return res;
}