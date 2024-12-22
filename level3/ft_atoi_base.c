/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base); version pasada por grademe*/








#include <unistd.h>


char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')  // Si el carácter es una letra mayúscula
        return (c + ('a' - 'A'));  // Convierte a minúscula restando la diferencia entre 'A' y 'a'
    return (c);  // Si no es mayúscula, lo deja igual (lo devuelve tal cual)
}

int get_digit(char c, int digits_in_base)
{
    int max_digit;

    if (digits_in_base <= 10)  // Si la base es 10 o menos
        max_digit = digits_in_base - 1 + '0';  // El último dígito es igual a '0' + (base - 1)
    else  // Si la base es mayor que 10 (hasta base 16)
        max_digit = digits_in_base - 10 - 1 + 'a';  // El último dígito es 'a' + (base - 11)

    if (c >= '0' && c <= '9' && c <= max_digit)  // Si el carácter es un número y está dentro del rango permitido
        return (c - '0');  // Convierte el carácter numérico a su valor numérico
    else if (c >= 'a' && c <= 'f' && c <= max_digit)  // Si el carácter es una letra entre 'a' y 'f' y dentro del rango
        return (10 + c - 'a');  // Convierte las letras a su valor numérico (10 para 'a', 11 para 'b', etc.)
    else
        return (-1);  // Si no es un dígito válido, devuelve -1
}

int ft_atoi_base(const char *str, int str_base)
{
    int result = 0;  // Aquí almacenaremos el número resultante
    int sign = 1;  // Determina si el número es positivo o negativo
    int digit;

    if (str == NULL || str_base < 2 || str_base > 16)  // Si la cadena es nula o la base no está en el rango [2, 16]
        return 0;

    if (*str == '-')  // Si el número es negativo
    {
        sign = -1;  // Cambia el signo a negativo
        ++str;  // Avanza al siguiente carácter
    }

    while (*str)  // Recorre toda la cadena de caracteres
    {
        digit = get_digit(to_lower(*str), str_base);  // Convierte el carácter actual a su valor numérico según la base
        if (digit == -1)  // Si no es un dígito válido
            break;  // Salimos del bucle
        result = result * str_base + digit;  // Calculamos el número (multiplicamos por la base y sumamos el dígito)
        ++str;  // Avanza al siguiente carácter
    }
    return (result * sign);  // Devuelve el número resultante, aplicando el signo
}