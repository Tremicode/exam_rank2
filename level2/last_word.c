/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/
void    last_word(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i])
    {
        if (str[i] == ' ' && str[i +1] >= '!' && str[i + 1] <= '~')
            j= i + 1;
        i++;
    }
    while (str[j] >= '!' && str[j] <= '~')
    {
        write (1,&str[j],1);
        j++;
    }
}

int main(int argc, char **argv)
{
 if (argc == 2)
    last_word (argv[1]);

    write(1,"\n",1);
  
}
