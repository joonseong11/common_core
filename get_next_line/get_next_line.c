#include "get_next_line.h"

void	read_buf(int	fd, char *temp)
{
	ssize_t	check;
	char	  *buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
  {
    free(buf);
		return ;
  }
	buf[0] = '\0';
  while (ft_strchr(buf, '\n') == 0)
  {
    check = read(fd, buf, BUFFER_SIZE);
    temp = ft_strjoin(temp, buf);
    if (check < 0)
    {
      free(buf);
      return ;
    }
  }
}

char	*get_next_line(int	fd)
{
	static char	*temp;
	char	    	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_buf(fd, temp);
	if (temp == NULL)
		return (NULL);
	line = line_truncate(temp);
	temp = leave_newtemp(temp);
	return (line);
}


