#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
  char *line;
  int fd;
  int   ret;
  
  fd = 0;
  if (ac > 1)
    fd = open(av[1], O_RDONLY);
  while ((ret = get_next_line(fd, &line)) != -1)
    {
      printf("%s\n", line);
      free(line);
      if (ret == 0)
          break;
    }
  return (0);
}