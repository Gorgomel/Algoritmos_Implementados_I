#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

static void refazer(char **mat, int esq, int dir)
{
    char *aux = malloc(100 *sizeof(char));
    int j = (esq + 1) * 2 - 1;
    
    strcpy(aux, mat[esq]);
    
    while (j <= dir)
    {
        if ((j < dir) && (strcmp(mat[j], mat[j +1]) < 0))
            j++;

        if (strcmp(aux, mat[j]) > 0)
            break;

        strcpy(mat[esq], mat[j]);
        esq = j; 
        j = (esq + 1) * 2 - 1;
    }

    strcpy(mat[esq], aux);
    free(aux);
}

static void gerarHeap(char **mat, int n)
{
    int esq = n / 2;
 
    while (esq >= 0)
    {
        refazer(mat, esq, n - 1);
        esq--;
    }
}

void heapsort(char **mat, int n)
{
    char *aux;
    int dir = n - 1;

    gerarHeap(mat, n); 
    
    while (dir > 0)
    {
        aux = malloc(100 *sizeof(char));
        strcpy(aux, mat[0]);
        strcpy(mat[0], mat[dir]);
        strcpy(mat[dir], aux);
        dir--;

        refazer(mat, 0, dir);
        free(aux);
    }
}

char ** gerar_matriz(int n)
{
    char **mat = malloc(n *sizeof(char*));
    int i;
    
    for(i = 0 ; i < n ; i++)
    {
        mat[i] = malloc(100 *sizeof(char));
        scanf("%s", mat[i]);
    } 
    
    return mat;
}

void imprimir_matriz(char **mat, int n)
{
    int i;
    
    for(i = 0 ; i < n ; i++)
        printf("%s\n", mat[i]);
    
}

void free_matriz(char **mat, int n)
{
    int i;
    
    for(i = 0 ; i < n ; i++)
        free(mat[i]);
    
    free(mat);
}

int main()
{
    char **mat;
    int n;
    
    scanf("%d", &n);
    
    mat = gerar_matriz(n);
    
    heapsort(mat, n);
    
    imprimir_matriz(mat, n);
    
    free_matriz(mat, n);
    
    return 0;
    
}
