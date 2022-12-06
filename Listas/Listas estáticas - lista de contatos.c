#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Str Str;
typedef struct Lista Lista;

struct Str
{
    char *item;
};

struct Lista
{
    int tam;
    Str *str;
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

int buscar(Lista *l, char *chave)
{
    int i;

    if (!lista_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
            if (strcmp(l->str->item, chave))
                return i;
    }

    return -1;
}

int inserir(Lista *l, char *chave)
{
    if (!lista_cheia(l))
    {
        l->str[l->tam].item = malloc(100 *sizeof(char));
        strcpy(l->str[l->tam].item, chave);
        
        l->tam++; 
        l->str = realloc(l->str, (l->tam +1) *sizeof(Str));        
        return 1;
    }

    return 0;
}

int liberar_lista(Lista *l)
{
    if (l != NULL)
    {
        int i;
        
        for(i = 0 ; i < l->tam ; i++)
            free(l->str[i].item);
        
        free(l->str);
        free(l);

        return 1;
    }

    return 0;
}

Lista* scan(int n)
{
    Lista *l = criar_lista();
    char *aux = malloc(100 *sizeof(char));
    int i;
    
    l->str = malloc(n *sizeof(Str));
    
    for(i = 0 ; i < n ; i++)
    {  
        scanf("%s", aux);
        inserir(l, aux);
    }
    
    free(aux);
    return l;
    
}

static void compara_string(char *l, char *str)
{
    int i, j = 0;
    
    for(i = 0 ; (i < strlen(l)) && (j < strlen(str)) ; i++)
    {
        if(l[i] == str[j])
            j++;
        
        else
            j = 0;
    }
    
    if(j == strlen(str))
        printf("%s\n", l);
}

void encontra_string(Lista *l, char *str)
{
    int i;
    
    for(i = 0 ; i < l->tam ; i++)
    {
        compara_string(l->str[i].item, str);        
    }
}

int main() 
{
    Lista *l;
    char *str = malloc(100 *sizeof(char));
    int n;
    
    scanf("%s", str);
    
    scanf("%d", &n);
    
    l = scan(n);
    
    encontra_string(l, str);
    
    free(str);
    liberar_lista(l);
    
    return 0;
}

