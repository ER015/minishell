#include "minishell.h"

void	ft_stack_del_node(t_node *node)
{
	if (!node)
		return ;
	free(node->token);
	free(node);
}

void	ft_stack_del(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !stack)
		return ;
	while (*stack && stack)
	{
		temp = (*stack)->next;
		ft_stack_del_node(*stack);
		*stack = temp;
	}
}

void	ft_env_del_node(t_env *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}


void	ft_env_del(t_env **env)
{
	t_env	*temp;

	if (!*env || !env)
		return ;
	while (*env && env)
	{
		temp = (*env)->next;
		ft_env_del_node(*env);
		*env = temp;
	}
}

void	struct_free(t_par *par)
{
	fd_clear(par->list);
	ft_stack_del(par->list);
	ft_env_del(par->env);
	//free(par);
}

void	fd_clear(t_node **list)
{
	t_node	*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (temp->fd >= 0)
		{
			close(temp->fd);
			if (temp->f_name != NULL)
			{
				unlink(temp->f_name);
				free(list->f_name);
			}
		}
		temp = temp->next;
	}
}