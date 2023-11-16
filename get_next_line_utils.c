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
