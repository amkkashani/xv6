#include "types.h"
#include "stat.h"
#include "user.h"
//#include "proc.h"




int
main()
{
//struct timeVariables *t = malloc(sizeof(struct timeVariables));
for(int i=0;i<10;i++){
    if(fork()!=0)
        wait();
    else
    {    int f = getpid();
        for(int j=0;j<1000;j++){
            printf(1,"[%d]:[%d]\n",f,i);
        }
        break;
    }
    
}
    


exit();
}