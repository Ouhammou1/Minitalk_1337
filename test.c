#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *convert_binary(int n)
{
    char *ptr;
    int i;

    ptr = (char *)malloc(9 * sizeof(char));
    if(ptr == NULL)
        return NULL;

    if ( n == 0)
        write(1,"0",1);
    
    i =7;
    while (i >= 0)
    {
        ptr[i] = (n & 1) + '0';
        n >>= 1;
        i--;
    }
    ptr[8] = '\0';
    return ptr;
}
int main(int ac, char **av)
{
   
            printf("%d ==>  %s\n",atoi(av[1]),convert_binary(atoi(av[1])));

    
    
}