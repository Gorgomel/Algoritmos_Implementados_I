#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n, int * in, float * fr)
{
    *in = n;
    *fr = n - *in;

}

int main(){
    int n, i;
    float aux;

    scanf("%d", &n);

    int inteira[n], *in;
    float fraciona[n], todos[n], *fr;

    for(i = 0 ; i < n ; i++)
    {
        scanf("%f", &aux);
        todos[i] = aux;
        in = &inteira[i];
        fr = &fraciona[i];
        frac(aux, in, fr);
    }

    for(i = 0 ; i < n ; i++)
    {
        printf("N=%.3f ", todos[i]);
        printf("I=%d ", inteira[i]);
        printf("F=%.3f ", fraciona[i]);
        printf("\n");
    }



    return 0;
}

