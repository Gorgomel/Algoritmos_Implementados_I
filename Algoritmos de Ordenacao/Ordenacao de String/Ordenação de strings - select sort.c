#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void free_matriz(char **mat, int l)
{
    int i;

    for(i = 0 ; i < l ; i++)
        free(mat[i]);

    free(mat);
}

char ** iniciar_matriz(int l)
{
    char **mat = malloc(l* sizeof(char*));
    int i;

    for(i = 0 ; i < l ; i++)
        mat[i] = malloc(sizeof(char));

    for(i = 0 ; i < l ; i++)
        scanf("%s", mat[i]);

    return mat;
}

void imprimir_matriz(char **mat, int l)
{
    int i;

    for(i = 0 ; i < l ; i++)
        printf("%s\n", mat[i]);
}

int retorna_tamanho_menor(char *str1, char *str2)
{
    int i;

    for(i = 0 ; str1[i] != '\0' && str2[i] != '\0' ; i++);

    return i;
}

void selectsort(char **mat, int l)
{
    char aux[100];
    int i, j, k, p;

    for (i = 0 ; i < l ;  i++)
    {
        p = i;

        for (j = i +1 ; j < l ; j++)
        {
            if (mat[j][0] < mat[p][0])
                p = j;

            else if(mat[j][0] == mat[p][0])
            {
                k = 1;
                do
                {
                    if(mat[j][k] < mat[p][k])
                    {
                        p = j;
                       // k = 0;
                    }

                    else if(mat[j][k] == mat[p][k])
                        k++;

                }while((mat[j][k] == mat[p][k]) && (k < retorna_tamanho_menor(mat[j], mat[p])));
            }
        }

        if (p != i)
        {
            strcpy(aux, mat[i]);
            strcpy(mat[i], mat[p]);
            strcpy(mat[p], aux);
        }
    }
}

int main()
{
    char **mat;
    int l;

    scanf("%d", &l);

    mat = iniciar_matriz(l);

    selectsort(mat, l);

    imprimir_matriz(mat, l);
    
    free_matriz(mat, l);

    return 0;
}

