#include "minishell.h"

t_node	*ft_lstnew(int type, char *token)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof (t_node));
	ptr->prior = 0;
	ptr->fd = -1;
    ptr->type = type;
    ptr->token = token;
	ptr->ind = -1;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*ptr;
	static int ind = 0;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		ind = 0;
		new->ind = ind;
		ind++;	
	}
	else
	{
	ptr = ft_lstlast(*lst);
	ptr->next = new;
	new->prev = ptr;
	new->ind = ind;
	ind++;
	}
}

int	ft_lstsize(t_node *lst)
{
	int	size;

	size = 1;
	if (NULL == lst)
		return (0);
	while (lst->next != NULL)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (*lst == NULL || lst == NULL)
	{
			*lst = new;
			(*lst)->next = NULL;
			(*lst)->prev = NULL;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}