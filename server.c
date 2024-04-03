#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <math.h>

int g = 0;
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
void handle_sigint(int sig) 
{ 
    static int s;


    if (sig == SIGUSR1)
    {
        // printf("Caught signal SIGUSR1 %d \n", 0);
        g++;
    }
    if (sig == SIGUSR2)
    {
        // printf("Caught signal SIGUSR2 %d \n", 1);
        s+= ft_power(2,g);
        g++;
    }
    
   if (g == 8)
   {
    // printf("\n s == %d \n", s);
        write(1,&s,1);
        g=0;
        s=0;
   }

//    static int clientrpid = 0;
//    if(clientrpid != sid)
//    {
//     clientrpid = sid;
//     uu
//    }
   

} 


int main(int ac , char *av[])
{
    static int s;
      signal(SIGUSR1, handle_sigint); 
      signal(SIGUSR2, handle_sigint);
   int pid =getpid() ;
   printf("pid = %d\n",pid);
   while(1)
   {
   
    sleep(3);
   }
        
   return 0;
}