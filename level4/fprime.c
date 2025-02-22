/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int number;

    if (argc == 2)
    {
        i = 1;
        number = atoi(argv[1]);
        if (number == 1)
         {
            printf("1");
         }
         
        while  (number >= ++i)
        {
                if (number % i == 0)
                {
                    printf("%d",i);
                    if (number == i)
                                break;
                    printf("*");
                    number /= i;
                    i = 1;
                }
        }
        
    }
    printf("\n");
    return(0);
    
}

/*otra version pasada por grademe*/


int main(int argc, char **argv)
{
    int i;
    int number;

    if(argc == 2)
    {
        i = 1;
        number = atoi (argv[1]);

        if (number == 1)
        printf("1");

        while(number >= i++)
        {
            if(number % i == 0)
            {
                printf("%d",i);
                if(number == i)
                        break;
                printf("*");
                number /= i;
                i = 1;
            }
        }
    }

    printf("\n");

}
/*improved version*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int number;

    // Si el número de parámetros no es 2, imprime solo una nueva línea
    if (argc != 2)
    {
        printf("\n");
        return 0;
    }

    number = atoi(argv[1]);  // Convierte el argumento a entero

    // Caso especial cuando el número es 1
    if (number == 1)
    {
        printf("1\n");
        return 0;
    }

    i = 2;  // Comienza desde el primer número primo

    // Factorización en primos
    while (number > 1)
    {
        if (number % i == 0)  // Si i es un factor de number
        {
            printf("%d", i);
            number /= i;  // Divide el número por i
            if (number > 1)
                printf("*");  // Si el número no es 1, imprime un asterisco
        }
        else
        {
            i++;  // Si i no es factor, incrementamos i
        }
    }

    printf("\n");  // Salto de línea al final
    return 0;
}
