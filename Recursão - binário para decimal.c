#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BASE 2

typedef struct{
    unsigned int x;
    unsigned int y;
}tipo1;

unsigned int bina(int *v, tipo1 b)
{
    int  i = 0;

    if(b.x < 1)
        return i;

    else
        *((b.y-b.x)+v) = (int)(pow(BASE, (b.x-1)) + 0.5) * (*((b.y-b.x)+v));
        i += *((b.y-b.x)+v);
        b.x -= 1;
        return i += bina(v , b);

}

int main()
{
    int i, j;
    tipo1 b;

    scanf("%d", &b.x);

    b.y = b.x;

    int v[b.x];

    for(i = 0 ; i < b.x ; i++)
    {
        scanf("%d", &j);

        if(j == 0 || j == 1)
            v[i] = j;

        else
        i--;
    }

    printf("%d", bina(v, b));

    return 0;
}
