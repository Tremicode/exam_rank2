/*Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/


char    *ft_strrev(char *str)
{
    int i = - 1;
    int length = 0;
    char temp;

    while (str[length])
            length++;
    while (++i < length / 2)
    {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    return(str);
}