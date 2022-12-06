#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int tamanho_vetor(int *vet)
{
    int i = 0;
    
    while(vet[i] != -1)
        i++;
    
    return i;
}

char * descodifica(char *str, int *vet)
{
    if(str != NULL)
    {
        char *str2 = malloc(tamanho_vetor(vet) *sizeof(char));
        int i = 0, j = 0, n, x;

        n = strlen(str);

        while(vet[i] != -1)
        {
            if(vet[i] <= n)
            {
                x = vet[i];
                str2[j] = str[x-1];
                j++;
            }

            i++;
        }

        if(j > 0)
            return str2;

        else
            return NULL;
    }

    return NULL;
}

int main()
{
    char *str = malloc(100 *sizeof(char));
    int *vet = malloc(sizeof(int));
    int i, j = 0;

    scanf("%s", str);

    while(i != -1)
    {
        scanf("%d", &i);
        vet[j] = i;
        vet = realloc(vet, (2+j) *(sizeof(int)));
        j++;
    }

    if((str = descodifica(str, vet)) != NULL)
        printf("%s\n", str);
    
    free(vet);
    free(str);

    return 0;
}

