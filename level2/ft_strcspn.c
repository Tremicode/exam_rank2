/*Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <stdio.h>
#include <stddef.h>  // Para el tipo `size_t`

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j = 0;

    while (s[i])
    {
        j = 0;

        while (reject[j])
        {
            if (s[i] == reject[j])
                return(i);
            j++;

        }
        i++;
    }
return(i);

}

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject);

int main(void)
{
    const char *s = "hello, world";
    const char *reject = "o,";
    
    // Usamos ft_strcspn y strcspn para comparar resultados
    size_t result = ft_strcspn(s, reject);
    size_t expected = strcspn(s, reject);

    printf("Resultado ft_strcspn: %zu\n", result);
    printf("Resultado strcspn: %zu\n", expected);

    // Comprobamos si son iguales
    if (result == expected)
        printf("¡Funciona correctamente!\n");
    else
        printf("Hay un error.\n");

    return 0;
}

// nueva version 
#include <stddef.h> // size_t

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (*s)
    {
        while (reject[i] && *s != reject[i])
            i++;
        if (reject[i] != '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}