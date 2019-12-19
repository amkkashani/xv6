#include "types.h"
#include "stat.h"
#include "user.h"
//#include "proc.h"



int
main()
{
//struct timeVariables *t = malloc(sizeof(struct timeVariables));
changePolicy(1);
struct timeVariables test[10];
int sumOfCBT=0;
int sumOfTT=0;
int sumOfWT=0;
for(int i=0;i<10;i++){
    if(fork()!=0){
        waitForChild(&test[i]);
        sumOfCBT += test[i].runningTime;
        sumOfTT += test[i].terminationTime - test[i].creationTime;
        sumOfWT += test[i].readyTime;

    }else
    {    int f = getpid();
        for(int j=0;j<1000;j++){
            printf(1,"[%d]:[%d]\n",f,i);
        }
        exit();
    }
    
}
for(int j=0;j<10;j++){
            printf(1,"\nchilde cbt = %d , turnAroundtime = %d , waiting time %d \n",test[j].runningTime,test[j].terminationTime - test[j].creationTime , test[j].readyTime );
}
printf(1,"\n avg CBT = %d  , avg TT = %d , avg WT = %d\n ",sumOfCBT/10,sumOfTT/10,sumOfWT/10);
    


exit();
}