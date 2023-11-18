#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == 0)
		return (0);
	new_node->next = NULL;
	new_node->content = content;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
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
}

void ft_lstprint(t_list *head)
{
	int i = 0;
	while (head)
	{
		printf("[%i] -> %s\n", ++i, head->content);
		head = head->next;
	}
}


static int	len(char const *s1)
{
	int	l;

	l = 0;
	while (s1[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (strdup(s2));
	if (s2 == NULL)
		return (strdup(s1));
	output = (char *)malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len(s1))
	{
		output[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len(s2))
		output[i++] = s2[j++];
	output[i] = '\0';
	return (output);
}
