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

Fila * intercala(Fila *f1, Fila *f2)
{
    Fila *f3 = criar_fila();
    int i, j;
    
    if(f2->tam > f1->tam)
        j = f2->tam;
    
    else 
        j = f1->tam;
    
    for(i = 0 ; i < j ; i++)
    {
        if(i < f1->tam && i < f2->tam)
        {
            if(f1->item[i] > f2->item[i])
            {
                enfileirar(f3, f1->item[i]);
                enfileirar(f3, f2->item[i]);
            }
            
            else
            {
                enfileirar(f3, f2->item[i]);
                enfileirar(f3, f1->item[i]);
            }
        }
        
        else if(i < f1->tam)
            enfileirar(f3, f1->item[i]);
            
        else if(i < f2->tam)
            enfileirar(f3, f2->item[i]);
    }
    
    return f3;
}

int main() 
{
    Fila *f1, *f2, *f3;

    f1 = scan();
    fflush(stdin);
    f2 = scan();

    f3 = intercala(f1, f2);

    imprimir_fila(f3);
    
    liberar_fila(f1);
    liberar_fila(f2);
    liberar_fila(f3);
    
    return 0;
}

