#include "get_next_line.h"

char	*get_next_buf(int	fd, char *temp)
{
	ssize_t	check;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (NULL);
	buf[0] = '\0';
	check = read(fd, temp, BUFFER_SIZE);
	if (check < 0)
		return (NULL);
	
}

char	*get_next_line(int	fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = get_next_buf(fd, temp);
	if (temp == 0)
		return (NULL);
	line = parsing(temp);
	temp = leave_after_NULL(temp);
	return (line);
}
