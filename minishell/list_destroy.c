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
	ft_stack_del(par->list);
	ft_env_del(par->env);
	//free(par);
}