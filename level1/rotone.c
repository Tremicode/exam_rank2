/*Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>*/
#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void    rotone(char *s)
{
        while (*s)
        {
                if ((*s >= 'A' && *s <= 'Y') || (*s >= 'a' && *s <= 'y'))
                        ft_putchar(*s + 1);
                else if (*s == 'Z' || *s == 'z')
                        ft_putchar(*s -25);
                else
                        ft_putchar(*s);
                ++s;


        }
}

int main (int ac, char  **av)
{
        if (ac == 2)
                rotone(av[1]);
        ft_putchar('\n');
        return (0);
}


#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            // Si el carácter es 'Z' o 'z', vuelve a 'A' o 'a' respectivamente
            if (argv[1][i] == 'Z')
                argv[1][i] = 'A';
            else if (argv[1][i] == 'z')
                argv[1][i] = 'a';
            // Si el carácter es una letra entre 'A' y 'Y' o entre 'a' y 'y', avanza una posición
            else if ((argv[1][i] >= 'A' && argv[1][i] <= 'Y') || (argv[1][i] >= 'a' && argv[1][i] <= 'y'))
                argv[1][i] += 1;

            // Escribimos el carácter modificado (o sin modificar si no era letra)
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    // Si no hay un solo argumento, o al final, escribimos un salto de línea
    write(1, "\n", 1);
    return 0;
}
