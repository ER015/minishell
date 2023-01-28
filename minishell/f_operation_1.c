#include "minishell.h"

int f_find_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int f_var_checker(char *ptr, t_par *par)
{
	t_env *env;
	int p_len;
	int k_len;
	int num;
	char *temp;

	temp = ptr;
	if (*temp == '$')
	{
		if (*(temp + 1) == ' ')
			return (-2);
		temp = temp + 1;
		p_len = ft_strlen(temp);
		env = *par->env;
		while (env != NULL)
		{
			k_len = ft_strlen(env->key);
			num = f_find_max(p_len, k_len);
			if (ft_strncmp(temp, env->key, num) == 0)
				return (env->ind);
			env = env->next;
		}
		return (-1);
	}
	else
		return (-3);
}

char *f_env_ind(int ind, t_par **par)
{
	t_env *env;
	env = *((*par)->env);
	while (env != NULL)
	{
		if (env->ind == ind)
		{
			if (!f_env_val_chk(env->value))
				return (env->value);
		}
		env = env->next;
	}
	
	return (NULL);
}

int f_env_val_chk(char *val)
{
	char *tmp;

	tmp = val;
	while (*tmp != '\0')
	{
		if (*tmp == '/')
			return (1);
		tmp++;
	}
	return (0);
}