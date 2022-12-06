#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100

typedef struct Fila Fila;

struct Fila
{
    int item[TAM_MAX];
    int ini;
    int fim; 
    int tam; 
};

Fila* criar_fila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f)
{

    if (f == NULL)
        return -1; 
    
    else if (f->tam < TAM_MAX)
        return 0; 
    
    else
        return 1; 
}

int fila_vazia(Fila *f)
{
    if (f == NULL)
        return -1; 
    
    else if (f->tam > 0)
        return 0; 
    
    else
        return 1; 
}

int enfileirar(Fila *f, int chave)
{
    if (f == NULL)
        f = criar_fila();
    
    if (!fila_cheia(f))
    {
        if (f->ini < 0)
            f->ini = 0;
        
        if (f->fim < TAM_MAX - 1)
            f->fim++;
        
        else
            f->fim = 0;
        
        f->item[f->fim] = chave;

        f->tam++;

        return 1; 
    }

    return 0; 
}

int desenfileirar(Fila *f)
{
    int item = INT_MIN;
    
    if (!fila_vazia(f))
    {
        item = f->item[f->ini];
        
        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0)
        {
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void imprimir_fila(Fila *f)
{
    Fila aux = *f;
    int item;
    
    while (!fila_vazia(&aux))
    {
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
        free(f);
}

Fila * scan()
{
    Fila *f = criar_fila();
    int i;
    
    while(i != -1)
    {
        scanf("%d", &i);
            
        if(i != -1)
            enfileirar(f, i);
    }
    
    return f;
}

void movs(Fila *f, int ticket)
{
    int i, quant = 0;
    
    for(i = 0 ; (f->item[f->ini] != ticket) && (i < f->tam) ; i++)
    {
        enfileirar(f, desenfileirar(f));
        quant++;
    }
    
    if(f->item[f->ini] == ticket)
    {
        desenfileirar(f);
        imprimir_fila(f);
        printf("%d \nsucesso\n", quant);
    }
    
    else
    {
        imprimir_fila(f);
        printf("%d \nfalha\n", quant);   
    }

}

int main() 
{
    Fila *f;
    int n;
    
    f = scan();
    
    scanf("%d", &n);
    
    movs(f, n);
    
    liberar_fila(f);
    
    return 0;
}

