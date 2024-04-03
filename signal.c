#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// // int count = 0;
// void (* old_handler);

// void contrc(int signum)
// {
//     static int count = 0;
//     signal(SIGINT, contrc);
//     ++count;
//     printf("cntrol_c cout = %d\n",count);
// }

// int main()
// {
//     static int  count = 0;

//     int c;
//     old_handler = signal(SIGINT,contrc);
//     while ( (c = getchar()) != '\n')
//     {
//         printf("ctr_c count = %d \n",count);
//         signal(SIGINT, old_handler);
//         for(;;);
//     }
    
// }
// #include <sys/wait.h>
// int main(int ac, char *av[])
// {
//     int pid = fork();
//     if(pid == -1)
//     {
//         return 1;
//     }

//     if( pid == 0)
//     {
//         while (1)
//         {
//             printf("some text goes here \n");
//             sleep(1);
//         }
//     }
//     else
//     {
//         sleep(50);
//         kill(pid, SIGKILL);
//         wait(NULL);
//     }  
    
//     return 0;
// }

int     ft_power(int a, int b)
{
    int i =0;
    int s = 1;
    while (i < b)
    {
        s = s * a;
        i++;
    }
    return s;
}
int main()
{
    printf("--> %d\n",ft_power(2,0));
}