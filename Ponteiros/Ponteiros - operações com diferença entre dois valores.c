#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void trespont(int * a, int * b, int * c)
{
    *c = *a - *b;
    if(*c < 0)
    {
        *c = *c * -1;
    }
    *a = *a + *c;
    *b = *b - *c;
}

int main(){
    int x, y, z;
    int *a, *b, *c;

    scanf("%d", &x);
    scanf("%d", &y);

    a = &x;
    b = &y;
    c = &z;

    trespont(a, b, c);

    printf("A=%d B=%d C=%d\n", *a, *b, *c);

    return 0;
}

