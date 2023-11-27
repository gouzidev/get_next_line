#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*buf;

	len = 0;
	while (s[len])
		len++;
	buf = malloc((len + 1) * sizeof(char));
	if (buf == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	len(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*output;
	int		i;
	int		j;

	if (str == NULL && buff == NULL)
		return (NULL);
    if (str == NULL)
        return (ft_strdup(buff));
    if (buff == NULL)
        return (ft_strdup(str));
	output = (char *)malloc((len(str) + len(buff) + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < len(str))
		output[i] = str[i];
	j = 0;
	while (j < len(buff))
		output[i++] = buff[j++];
	output[i] = '\0';
	return (output);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (((char *)str + i));
		i++;
	}
	if (str[i] == (char)c)
		return (((char *)str + i));
	return (NULL);
}

