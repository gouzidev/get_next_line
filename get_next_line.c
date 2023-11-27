#include "get_next_line.h"

#define BS 5

char *get_line(char *buff)
{
	char *line;
	int i;

	i = 0;
	while (buff[i] && buff[i] != '_')
		i++;
	line = malloc((sizeof(char) + 1) * i);
	i = -1;
	while (++i >= 0 && buff[i] && buff[i] != '_')
		line[i] = buff[i];
	line[i] = '\0';
	return (line);

}
char *get_rest(char *buff)
{
	char *rest;
	int i;
	int j;
	i = 0;
	while (buff[i] && buff[i] != '_')
		i++;
	if (buff[i] == '_')
		i++;
	rest = malloc((len(buff) - i + 1) * sizeof(char));
	j = 0;
	while (buff[i] && buff[i] != '_')
		rest[j++] = buff[i++];
	rest[j] = '\0';
	return (rest);
}

char *get_next_line(int fd)
{
	char *str;
	char *buff;
	static char *rest;
	int i;

	i = 1;
	str = NULL;
	buff = malloc(BS + 1);
	while (i > 0)
	{
		i = read(fd, buff, BS);
		buff[i] = '\0';
		if (rest && *rest)
			str = ft_strjoin(rest, str);
		str = ft_strjoin(str, buff);
		rest = get_rest(buff);
		if (ft_strchr(str, '_'))
			return get_line(str);
	}
}

int main()
{
	printf("-> LINE %s  \n", get_next_line(open("FILE", 0)));
	printf("-> LINE %s  \n", get_next_line(open("FILE", 0)));
}