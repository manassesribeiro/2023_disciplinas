#include <stdio.h>

int main()
{
    int cont;
    cont = 1;
    while(cont <= 1000)
    {
        if (cont % 2 != 0)
        {
            printf("O valor %i é impar\n", cont);
        }
        cont = cont + 1;
    }

    return 0;
}