#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef SIZE
#define SIZE 5

typedef struct s_list
{
	char		*str;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == 0)
		return (0);
	new_node->next = NULL;
	new_node->str = strdup(content);
	return (new_node);
}

int ft_strlen(char *str, char c)
{
	int i;
	if (str)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
	}
	return (i);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new, int *len)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst == NULL)
			ft_lstadd_front(lst, new);
		else
		{
			last = *lst;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	*len += ft_strlen(new->str, '\0');
}

int found_nl(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '_')
			return 1;
	}
	return (0);
}

void ft_lstprint(t_list *lst)
{
	int i = 0;
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	while (lst)
	{
		printf("-> %s  [%i]\n", lst->str, ++i);
		lst = lst->next;
	}
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
}

int list_len(t_list *list)
{
	int i;
	int l;

	i = 0;
	l = 0;
	while (list)
	{
		while (list->str[i] && list->str[i] != '_' && ++l)
			i++;
		list = list->next;
	}
	return l;
}

char *get_line(t_list *list)
{
	int i;
	int j;
	char *line;

	i = list_len(list);
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (list)
	{
		j = 0;
		while (list->str[j] && list->str[j] != '_')
			line[i++] = list->str[j++];
		list = list->next;
	}
	return (line);
}
void freee(t_list **list)
{
	t_list *next;

	next = *list;
	while (list && *list && (*list)->next)
	{
		next = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = next;
	}
}
t_list* cleaner(t_list **list, t_list *new_node, char **rest)
{
	int i;
	int j;
	t_list *temp;
	t_list *next;
	char *buff;

	buff = malloc(ft_strlen(new_node->str, '_'));
	temp = *list;
	while (temp)
	{
		if (temp == new_node)
		{
			i = -1;
			printf("new_node->str    %s\n", new_node->str);
			while (++i >= 0 && new_node->str[i] && new_node->str[i] != '_')
				buff[i] = new_node->str[i];
			buff[i] = '\0';
			printf("buff             %s\n", buff);
			if (new_node->str[i] == '_')
				i++;
			(*rest) = malloc(ft_strlen(&new_node->str[i], '_'));
			j = 0;
			while (new_node->str[i] && new_node->str[i] != '_')
				(*rest)[j++] = new_node->str[i++];
			(*rest)[j] = '\0';
			printf("rest             %s\n", *rest);
			freee(list);
			new_node->str = buff;
			printf("new ->           %s\n", new_node->str);
		}
		temp = (temp)->next;
	}
}

char *get_next_line(int fd)
{
	int len;
	char *buff = malloc (SIZE + 1);
	 t_list *list;
	static char *rest;
	char *line;
	t_list *new_node;
	list = NULL;
	int bytes;
	len = 0;
	printf("REST HAD %s\n", rest);
	if (rest)
	{
		new_node = ft_lstnew(rest);
		ft_lstadd_back(&list, new_node, &len);
	}

	while ((bytes = read(fd, buff, SIZE)) > 0)
	{
		new_node = ft_lstnew(buff);
		ft_lstadd_back(&list, new_node, &len);
		if (found_nl(buff))
		{
			line = get_line(list);
			cleaner(&list, new_node, &rest);
			printf("line ->  %s\n", line);
		}
	}
}
#include <string.h>
int main()
{

	int fd = open("FILE", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
#endif
