/*Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    int length = 0;
    char *duplicated_str;

    while(src[length])
            length ++;
    duplicated_str = malloc(sizeof(*duplicated_str) * (length + 1));
    if (duplicated_str != NULL)
    {
        while(src[i])
        {
            duplicated_str[i] = src[i];
            i++;
        }
        duplicated_str[i] = '\0';
    }

    return(duplicated_str);

}

/*version aceptada por grademe*/ 
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char	*tmp; //we will duplicate str into this variable
	int	len; 
	int	i;

	len = 0;
	i = 0;
	while (src[len]) //we calculate the length of src to create a place with enough memory
		len++;
	tmp = malloc(sizeof(char) * len + 1); //we allocate some space thanks to malloc. + 1 because the string need some space for the extra "\0" at the end (don't forget it !)
	if (!tmp) //malloc protection
		return (NULL);
	while (src[i]) //loop to complete the new string
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0; //adding the null character at the end
	return (tmp);
}



#include <stdlib.h>

char    *ft_strdup(char *src)
{

	int i;
	int len;
	char *temp;

	len = 0;
	i = 0;

	while(src[len])
			len++;
	temp = malloc(sizeof(char)*len + 1);
	if (!temp)
		return (NULL);

	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
    temp[i] = 0;
	return(temp);


}
