#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Real Real;

struct Real
{
    int i; 
    int f; 
};

Real* criar(int i, int f)
{
    Real *num = malloc(sizeof(Real));
      
    if(f < 0)
        f *= -1;
    
    if(f >= 100)
        while(f >= 100)
            f /= 10; 
    
    num->i = i;
    num->f = f;

    return num;
}

Real* soma(Real *r1, Real *r2)
{
    Real *aux = malloc(sizeof(Real));
    int a1;
    
    if(r1->i < 0)
        a1 = (((r1->i *100) *-1) + r1->f) *-1;
    
    else 
        a1 = (r1->i *100) + r1->f;
    
    if(r2->i < 0)
        a1 += ((((r2->i *100) *-1) + r2->f) * -1);
    
    else 
        a1 += (r2->i *100) + r2->f;
    
    aux->i = a1 /100;
    
    if(a1 < 0)
    aux->f = (a1 *-1) %100;
    
    else
    aux->f = a1 %100;     
    
    return aux;
}

Real* subtracao(Real *r1, Real *r2)
{
    Real *aux = malloc(sizeof(Real));
    int a1;
    
    if(r1->i < 0)
        a1 = (((r1->i *100) *-1) + r1->f) *-1;
    
    else 
        a1 = (r1->i *100) + r1->f;
    
    if(r2->i < 0)
        a1 -= ((((r2->i *100) *-1) + r2->f) * -1);
    
    else 
        a1 -= (r2->i *100) + r2->f;
    
    aux->i = a1 /100;
    
    if(a1 < 0)
    aux->f = (a1 *-1) %100;
    
    else
    aux->f = a1 %100;     
    
    return aux;
}
    
int arredondar(Real *r1)
{
    int i = r1->i;
    
    if(i < 0)
        i *= -1;

    if(r1->f >= 50)
    {
        if(r1->i < 0)
        return (i +1) *-1;
    
        else
            return i +1;
    }
      
    else
    {
        if(r1->i < 0)
           return i *-1;
        
        else
            return i;
    }
}

void imprimir(Real *r1)
{
    if(r1->f < 10)
        printf("%d.0%d\n", r1->i, r1->f);
    
    else
        printf("%d.%d\n", r1->i, r1->f);
}

int main() 
{
    Real *num1, *num2, *num3;
    int i, f;
    
    scanf("%d %d", &i, &f);
    
    num1 = criar(i, f);
    
    scanf("%d %d", &i, &f);
    
    num2 = criar(i, f);
    
    imprimir(num1);
    
    imprimir(num2);
    
    num3 = soma(num1, num2);
    
    imprimir(num3);
    
    num3 = subtracao(num1, num2);
    
    imprimir(num3);
    
    printf("%d %d", arredondar(num1), arredondar(num2));
    
    free(num1);
    free(num2);
    free(num3);
  
    return 0;
}

