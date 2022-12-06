#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned int potencia(unsigned int a, unsigned  int b)
{
    if (b == 0)
        return 1;

    else
        return a * potencia(a, b - 1);
}

int main ()
{
    unsigned int a, b;

    scanf("%d" "%d", &a, &b );

    printf("%d\n", potencia(a, b));

    return 0;
}

