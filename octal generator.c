//Coded by Garrett Giddings 5/24/2020
#include <stdio.h>

int main(void)
{
    int input, num1, num2, num3, num4, num5;

    printf("\nEnter a number between 0 and 32767: ");
    scanf("%d", &input);

    num5 = input % 8;
    input /= 8;
    num4 = input % 8;
    input /= 8;
    num3 = input % 8;
    input /= 8;
    num2 = input % 8;
    input /= 8;
    num1 = input % 8;

    printf("\nIn octal, your number is: %1d%1d%1d%1d%1d\n", num1, num2, num3, num4, num5);

    return 0;
}