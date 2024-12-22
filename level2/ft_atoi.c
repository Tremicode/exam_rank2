/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <stdio.h>

int	ft_atoi(char *str)
{
	int result = 0;
    int sign = 1;

    while(*str == ' ' || (*str >= 9 && *str <= 13))
            str++;
    if (*str == '-')
        sign = -1;

    if (*str == '-'|| *str == '+')
            str++;

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str -'0';
                str++;
    }
    return (result * sign);
}
int main(int argc, char **argv)
{
    int i = 1;
    int atoi;
    while (argc > i)
    {
         *argv[atoi = ft_atoi(i++)];
        printf("resultado = %i", atoi);
    }
    return(0);
    /*char str1[] = "1234";     // Cadena con número positivo
    char str2[] = "-5678";    // Cadena con número negativo
    char str3[] = "    +42";  // Cadena con espacios y número positivo
    char str4[] = "  -123abc"; // Cadena con números y letras mezcladas

    // Prueba de conversiones
    printf("Resultado de ft_atoi(\"%s\") = %d\n", str1, ft_atoi(str1));
    printf("Resultado de ft_atoi(\"%s\") = %d\n", str2, ft_atoi(str2));
    printf("Resultado de ft_atoi(\"%s\") = %d\n", str3, ft_atoi(str3));
    printf("Resultado de ft_atoi(\"%s\") = %d\n", str4, ft_atoi(str4));

    return 0;*/
}

