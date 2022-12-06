#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void quicksort(int *v, int m, int esq, int dir)
{
    int i = esq, j = dir, pivo = v[(i + j) /2], aux;

    if(dir - esq + 1 > 0)
    {
        do
        {
            while(v[i] < pivo)
                i++;

            while(v[j] > pivo)
                j--;

            if(i <= j)
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }

        }
        while(i <= j);

        if(j > esq)
            quicksort(v, m, esq, j); 

        if(i < dir)
            quicksort(v, m, i, dir); 

    }

    else
    {
        int troca = 1;

        for(i = 0 ; (i < dir -1) && (troca) ; i++)
         {
             troca = 0;

            for(j = 0 ; j < dir -i -1 ; j++)
                if(v[j] > v[j +1])
                 {
                    aux = v[j];
                    v[j] = v[j +1];
                    v[j +1] = aux;
                    troca = 1; 
                 }
         }

    }
}

int main()
{
    int i, n, m, *vet;

    scanf("%d", &n);

    vet = (int*) malloc(n *sizeof(int));

    for(i = 0 ; i < n ; i++)
        scanf("%d", vet +i);

    scanf("%d", &m);

    quicksort(vet, m, 0, n-=1);

    for(i = 0 ; i <= n ; i++)
        printf("%d ", vet[i]);

    return 0;
}

