#include "minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
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

t_env	*ft_lstnew_env(char *key, char *value)
{
	t_env	*ptr;

	ptr = (t_env *)malloc(sizeof (t_env));
    ptr->key = key;
    ptr->value = value;
	ptr->ind = -1;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*ptr;
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
	ptr = ft_lstlast_env(*lst);
	ptr->next = new;
	new->prev = ptr;
	new->ind = ind;
	ind++;
	}
}

void lst_add_env(t_env **env, char *key, char *value)
{
    ft_lstadd_back_env(env, ft_lstnew_env(key, value));
}
