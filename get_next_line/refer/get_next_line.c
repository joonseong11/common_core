#include "get_next_line.h"

char	*get_newline(char *str, )
{

	return ();
}

char	*get_leftline()
{
	return ();
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*buf;

	buf = ft_calloc();
	while (!istherenewline(temp[fd]))
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		temp[fd] = strjoin(temp[fd], buf[r])
	}
	line = malloc(sizeof(char) * BUFFER_SIZE);
	line = get_newline(temp[fd]);
	temp[fd] = get_leftline(temp[fd],);
	return (line);
}
