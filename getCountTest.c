#include "types.h"
#include "stat.h"
#include "user.h"
 
int
main(int argc,char **argv)
{
  int a = 4;
  getChildren(a);
  getChildren(a);
  int test = readcommand (0, command, args);
  printf("i find this %d",test);	
  int result = getCount(22);
  printf(1,"--- %d ---",result);
  exit();
}