#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rFunction(int max)
{
  srand(time(0));

  for(int i = 0; i<5; i++)
    printf(" %d ", rand() % max);

  return 0;
}

int main()
{
  rFunction(2);
}
