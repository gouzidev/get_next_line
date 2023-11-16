#include "get_next_line.h"

char *get_next_line(int fd)
{

    char *buff;
    char c;
	buff = malloc(SIZE + 1);
    int byte_read;
	int	i = 0;
	while (i < SIZE)
	{
		byte_read = read(fd, &c, 1);
		if (c == '\n' || c =='\0')
		{
			buff[i] = '\0';
			return (buff);
		}
		if (byte_read == 0 || byte_read == -1)
		{
			if (i > 0)
			{
				buff[i] = '\0';
				return (buff);
			}
			return (NULL);
		}
		buff[i] = c;
		i++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	}
	buff[i] = '\0';
    return (buff);
}

int main()
{
    int fd = open("file.txt", O_RDWR);
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
    printf("-> %s\n", get_next_line(fd));
}