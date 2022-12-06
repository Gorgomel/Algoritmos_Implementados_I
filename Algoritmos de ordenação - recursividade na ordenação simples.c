#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectsort(int *v, int n)
{
    int j, p, aux;

    p = n;

    for(j = 0 ; j < n ; j++)
        if(v[j] > v[p])
            p = j;

    if(n > 0)
    {
        aux = v[n];
        v[n] = v[p];
        v[p] = aux;
        selectsort(v, (n-=1));
    }
}

int main()
{
    int n, i;

    scanf("%d", &n);

    int *vet = (int*) malloc(n *sizeof(int));

    for(i = 0 ; i < n ; i++)
        scanf("%d", vet + i);

    selectsort(vet, (n-=1));

    for(i = 0 ; i <= n ; i++)
        printf("%d ", vet[i]);

    free(vet);
    
    return 0;
}

