#include "types.h"
#include "stat.h"
#include "user.h"



int
main()
{
    changePolicy(2);
    struct timeVariables test[25];
    struct timeVariables sorted[25];
    int temp;
    int pids[25];
 //   int i=0;
    for(int i=0;i<25 ;i++){
        temp =fork();
        if(temp ==0){
            if(i<5){
                changePriority(5);
            }else if(i<10)
            {
                changePriority(4);
            }else if(i<15){
                changePriority(3);
            }else if(i<20)
            {
                changePriority(2);
            }else
            {
                changePriority(1);
            }
            for(int j=0 ;j<500;j++){
                printf(1,"[%d]:[%d]\n",i,j);
            }
            break;        
            
        }
        pids[i]=temp;  
    }
    if(temp!=0){
        for(int kk=0;kk<25;kk++){
            int curentPid = waitForChild(&test[kk]);
            int finder =0;
            printf(1,"*****%d************\n",curentPid);
            for(finder=0 ;finder<25;finder++){
                if(pids[finder]==curentPid){
                    //printf(1,"\n %d = childe cbt = %d , turnAroundtime = %d , waiting time %d \n",finder,test[kk].runningTime,test[kk].terminationTime - test[kk].creationTime , test[kk].readyTime );
                    sorted[finder] = test[kk];
                }
            }
            
        }
        printf(1,"all things finished \n");

        for(int f = 0;f<25;f+=5){
            printf(1,"**\npriority  %d \n",5-f/5);
            int sumOfCBT=0;
            int sumOfTT=0;
            int sumOfWT=0;
            for(int i=0 ; i<5;i++){
                printf(1,"\n cbt = %d , turnAroundtime = %d , waiting time %d \n",sorted[f+i].runningTime,sorted[f+i].terminationTime - sorted[f+i].creationTime , sorted[f+i].readyTime );
                sumOfCBT += sorted[f+i].runningTime;
                sumOfTT += sorted[f+i].terminationTime - sorted[i].creationTime;
                sumOfWT += sorted[f+i].readyTime;
            }
            printf(1,"\n avg CBT = %d  , avg TT = %d , avg WT = %d\n ",sumOfCBT/5,sumOfTT/5,sumOfWT/5);
        }
    }
    exit();
}