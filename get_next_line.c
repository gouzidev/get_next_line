#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *res = NULL;
    char *buff;
    char c;
	buff = malloc(SIZE);
    int byte_read;
	int	i = 0;
	int done = 0;
	do
	{
		i = 0;
		while (i < SIZE)
		{
			byte_read = read(fd, &c, 1);
			printf("%c ", c);
			buff[i++] = c;
			if (c == '\n')
			{
				done = 1;
				buff[i] = c;
			 	ft_strjoin(res, buff);
				return (res);
			}
			if (byte_read == 0)
			{
				done = 1;
				if (i > 0)
				{
					return (res);
				}
				return (NULL);
			}
		}
		buff[i] = '\0';
		res = ft_strjoin(res, buff);
	}
	while (!done);
	return (res);
}

int main()
{
    int fd = open("file.txt", O_RDWR);
    printf("-> %s\n", get_next_line(fd));

}