#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned int multi(unsigned int a, unsigned  int b)

{

    if (b == 1)

        return a;       

      

    else        

        return a += multi(a,  b -= 1);   

}

int main ()

{

	unsigned int a, b;

	

	scanf("%d" "%d", &a, &b );

	

	printf("%d\n", multi(a, b));

	

	return 0;

}



