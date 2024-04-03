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
int main(int ac , char *av[])
{
  char *ptr =(char*)malloc(9 * sizeof(char));
    if(ptr ==  NULL)
        return 0;

    if (ac != 3)
    {
        printf("error");
    }
    else
    {
    int  p = atoi(av[1]);
    int j=0;
    while (av[2][j] != '\0')
    {
        ptr = convert_binary(av[2][j]);
        int i = 7;
        while (i >= 0)
        {
            if(ptr[i] == '0')
            {
                kill(p,SIGUSR1);
            }
            if(ptr[i] == '1')
            {
                kill(p,SIGUSR2);
            }
            usleep(500);
                i--;
        }
        j++;
    }   
    }
return 0;
}