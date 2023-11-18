#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#ifndef SIZE
#define SIZE 5
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*ft_strjoin(char const *s1, char const *s2);