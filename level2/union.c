/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/


#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        unsigned char seen[256] = {0}; // Para verificar qué caracteres ya han sido impresos
        int i = 0;
        int j = 0;

        // Recorrer la primera cadena
        while (argv[1][i])
        {
            // Verificar si el carácter aparece en la segunda cadena
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j] && !seen[(unsigned char)argv[1][i]])
                {
                    write(1, &argv[1][i], 1);  // Imprimir el carácter común
                    seen[(unsigned char)argv[1][i]] = 1;  // Marcar como impreso
                    break;  // Una vez encontrado, salir del bucle de la segunda cadena
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);  // Salto de línea al final
    return 0;
}

