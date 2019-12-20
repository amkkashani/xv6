#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int table[1200][256] ={0};
extern int cpuMode;
int
sys_getpid(void)
{
  return myproc()->pid;
}



int
sys_fork(void)
{
  int dadPid = sys_getpid();
  int pidChild = fork();
  //cprintf("father : %d child : %d",dadPid , pidChild);
  for(int i =0;i<256;i++){
    if(table[dadPid][i]==0){
      table[dadPid][i]=pidChild;
      break;
    }
  }
  return pidChild;
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}



int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//my implimentation
int
sys_getChildren(int prosecId)
{
  int result=0;
  argint(0,&prosecId);
  int j=0;
  while(table[prosecId][j]!=0){
     int temp = table[prosecId][j];
     while(temp>0){
       temp/=10;
       result*=10;
     }
     result+=table[prosecId][j];
     j++;
  }
  return result;
}


//question 2
int
sys_getCount(int find){
  argint(0,&find);
  int counter =0;
  for(int i=0;i<=myproc()->usagepointer;i++){
    if(myproc()->usage[i]==find){
      counter++;
    }
  }
  return counter;
}

//3.2
int
sys_changePriority(int newPriority){
  argint(0,&newPriority);
  if(newPriority > 5 || newPriority < 0){
    return -1;
  }
  myproc()->calculatedPriority = newPriority;
  myproc()->priority = newPriority ;


  return 5;
}

//3.3
int
sys_changePolicy(int mode){
  argint(0,&mode);
  if(mode>2 || mode<0){
    return -1;
  }
  cprintf("%d",cpuMode);
  cpuMode = mode;
  return 1;
}

//3.4
int
sys_waitForChild(void){
  struct timeVariables *ct;
  argptr (0 , (void*)&ct ,sizeof(*ct));
  return waitForChild(ct);
  cprintf("%d",ct->readyTime);
  
}








