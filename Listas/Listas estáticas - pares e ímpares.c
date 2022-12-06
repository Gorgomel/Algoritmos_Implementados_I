#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista
{
    int item[MAX_SIZE]; 
    int tam; 
};

Lista* criar_lista()
{
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l)
{
    return (l != NULL) && (l->tam == MAX_SIZE);
}

int inserir(Lista *l, int chave)
{
    if (!lista_cheia(l))
    {

        l->item[l->tam] = chave;

        l->tam++; 

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l)
{
    int i;

    if (!lista_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int liberar_lista(Lista *l)
{
    if (l != NULL)
    {
        free(l);

        return 1;
    }

    return 0;
}

Lista * scan()
{
    Lista *l = criar_lista();
    int i;
    
    while(i != -1)
    {
        scanf("%d", &i);
        
        if(i != -1)
            inserir(l, i);
    }
    
    return l;
}

void par_impar(Lista *l1, Lista *l2, Lista *l3)
{
    int i = 0;
    
    if(!lista_vazia(l1))
    {
        for(i = 0 ; i < l1->tam ; i++)
        {
            if(l1->item[i] % 2 == 0)
                inserir(l2, l1->item[i]);
            
            else
                inserir(l3, l1->item[i]);
        }
        
        if(!lista_vazia(l2))
        {
            printf("par: ");
            imprimir_lista(l2);
        }
        
        else
            printf("par: -1\n");
        
        
        if(!lista_vazia(l3))
        {
            printf("impar: ");
            imprimir_lista(l3);
            i = 1;
        }
        
        else
            printf("impar: -1");
    }
    
    else
        printf("par: -1\n");
    
    if(lista_vazia(l2) && i != 1)
        printf("impar: -1\n");
}

int main() 
{
    Lista *l1, *l2, *l3;
    
    l1 = scan();
    
    l2 = criar_lista();
    l3 = criar_lista();
    
    par_impar(l1, l2, l3);
    
    liberar_lista(l1);
    liberar_lista(l2);
    liberar_lista(l3);
    
    return 0;
}

