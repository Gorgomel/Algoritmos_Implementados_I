#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int numerador, denominador;
}rac;

rac multi_volta (rac a, rac b)
{
    rac c;

    c.numerador = a.numerador * b.denominador;
    c.denominador = a.denominador * b.numerador;

    return c;

}

int main(){
    rac a, b, c;

    scanf("%d", &a.numerador);
    scanf("%d", &a.denominador);

    scanf("%d", &b.numerador);
    scanf("%d", &b.denominador);

    c = multi_volta(a,b);
    printf("%d %d\n", c.numerador, c.denominador);


    return 0;
}
