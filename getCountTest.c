#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc,char **argv)
{
  int a = 4;
  getChildren(a);
  getChildren(a);	
  int result = getCount(22);
  printf(1,"--- %d ---",result);
  //this code for test of 3.3
  /*
  changePolicy(1);
  changePolicy(2);*/

  //for 3.4
  //struct timeVariables * test;
 // waitForChild();
  exit();
}