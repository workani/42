#include "libft.h"
#include <stdlib.h>
#include <string.h>


char *ft_itoa()
{
  int i = 0;
  int nbr = 0;
  int tmp = nbr;
  char arr[10];

  if (nbr == 0)
      i++;
  while (tmp)
  {
    tmp /= 10;
    i++;
  }
  while (i--)
  {
    arr[i] = (nbr % 10) + '0';
    nbr /= 10;
  }
}

int main ()
{
  
}

