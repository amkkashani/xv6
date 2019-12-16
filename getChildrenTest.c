#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc,char **argv)
{
  int a= fork();
  fork();
  fork();
  fork();
  wait();
  wait();
  wait();
  int b = getChildren(a);
  printf(1,"pid %d =*****ppid=%d //\n",getpid(),b);
  wait();
//  printf(1, "My first xv6 program\n"); 
  //for question one testing :) here is finished
  exit();
}
