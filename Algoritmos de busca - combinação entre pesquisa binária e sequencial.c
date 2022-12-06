#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_sequenc(int key, int *vet, int inicio, int fim)
{
    int i;

    if(key == vet[inicio])
        return inicio;

    else if(key == vet[fim-=1])
        return fim;

    else
    {
        for(i = inicio ; i <= fim && key <= vet[i] ; i++);

        return ((i <= fim) && (vet[i] == key)) ? i : -1;
    }
}

int busca_bin(int key, int *vet, int fim, int m)
{
    int meio, inicio = 0, i;

    if(vet != NULL)
    {
        meio = (inicio + fim) /2;

        for(i = 0 ; fim - inicio > m ; i++)
        {
            meio = (inicio + fim) /2;

            if(key == vet[meio])
            {
                printf("%d", meio);
                return 0;
            }

            else if(key < vet[meio])
                fim = meio -1;

            else if(key > vet[meio])
                inicio = meio +1;
        }


        if(key > vet[meio])
        {
            if(inicio > 0)
                inicio -= 1;

            meio = busca_sequenc(key, vet, inicio, fim);

            for(i = inicio ; i < fim ; i++)
                printf("%d ", vet[i]);
        }

        else
        {
            meio = busca_sequenc(key, vet, inicio, fim);

            for(i = inicio ; i <= fim ; i++)
                printf("%d ", vet[i]);
        }

        printf("\n%d", meio);
    }

    return -1;
}

int main()
{
    int key, n, i, m;

    scanf("%d", &key);

    scanf("%d", &n);

    int *vet = (int*) malloc(n *sizeof(int));

    for(i = 0 ; i < n ; i++)
        scanf("%d", vet + i);

    scanf("%d", &m);

    busca_bin(key, vet, n, m);

    return 0;
}

