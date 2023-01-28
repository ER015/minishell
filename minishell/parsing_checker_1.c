#include "minishell.h"
/*
 функция p_check_6 обеспечивает 
 опредиление количества пробелов и их токенизацию 
*/

int p_check_6(char *line, t_node **list, int i)
{
	int i_start;

	i_start = i;
	lst_add(list, ft_substr(line, i, 1), _SPC_);
	while(line[i] && line[i] == ' ')
		i++;
	return (i - i_start);
}

int p_check_7(char *line, t_node **list, int i)
{
	int	i_start;

	i_start = i;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '>' || line[i] == '<')
		{
			lst_add(list, ft_substr(line, i_start, i - i_start), _TEXT_);
			return (i - i_start);
		}
		//line[i] == '$' ||  // #1
		if (line[i] == '|' || line[i] == 39)
		{
			lst_add(list, ft_substr(line, i_start, i - i_start), _TEXT_);
			return (i - i_start);
		}
		if (line[i] == 34)
		{
			lst_add(list, ft_substr(line, i_start, i - i_start), _TEXT_);
			return (i - i_start);
		}
		i++;
	}
	lst_add(list, ft_substr(line, i_start, i - i_start), _TEXT_);
	return (i - i_start);
}