/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
         i++;

    return (s1[i] - s2[i]);

}

/*int main(void)
{
    char str1[] = "hola";
    char str2[] = "hola";
    char str3[] = "adios";
    char str4[] = "hol";
    char str5[] = "holb";

    // Comparaciones
    printf("Comparando \"%s\" y \"%s\": %d\n", str1, str2, ft_strcmp(str1, str2)); // Debería devolver 0
    printf("Comparando \"%s\" y \"%s\": %d\n", str1, str3, ft_strcmp(str1, str3)); // Debería devolver algo mayor a 0
    printf("Comparando \"%s\" y \"%s\": %d\n", str1, str4, ft_strcmp(str1, str4)); // Debería devolver algo mayor a 0
    printf("Comparando \"%s\" y \"%s\": %d\n", str1, str5, ft_strcmp(str1, str5)); // Debería devolver algo menor a 0

    return 0;
}*/
/*funcion alternativa que pasa el grademe*/
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while((s1[i] || s2[i]) && s1[i] == s2[i])
    i++;
     
    return (s1[i] - s2[i]);
}