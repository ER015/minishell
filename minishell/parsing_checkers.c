#include "minishell.h"

/*
функция p_check_1 обеспечивает проверку количества символов < или наличие | 
и создает соответствующий токен 
*/

int p_check_1(char *line, t_node **list, int i)
{
	if (line[i] == '<' && line[i + 1] == '<')
	{
		lst_add(list, ft_substr(line, i, 2), _H_DOC_);
			return (2);
	}
	if (line[i] == '<' && line[i + 1] != '<')
	{
		lst_add(list, ft_substr(line, i, 1), _IN_F_);
			return (1);
	}
	if (line[i] == '|')
	{
		lst_add(list, ft_substr(line, i, 1), _PIPE_);
		return (1);
	}
	return (0);
}	
/*
функция p_check_2 обеспечивает проверку количества символов > и создает
соответствующий токен 
*/
int p_check_2(char *line, t_node **list, int i)
{
	if (line[i] == '>' && line[i + 1] == '>')
	{
		lst_add(list, ft_substr(line, i, 2), _APPD_);
			return (2);
	}
	if (line[i] == '>' && line[i + 1] != '>')
	{
		lst_add(list, ft_substr(line, i, 1), _OUT_F_);
			return (1);
	}
	return (0);
}

/*функция p_check_3 обеспечивает проверку одинарныч квот ' 
и их токенизацию, если квота не закрыта токен TYPE будет _ERROR_
*/

int p_check_3(char *line, t_node **list, int i)
{
	int i_start;

	i_start = i;
	i++;
	while (line [i] != '\0')
	{
		if (line[i] == 39)
		{
			lst_add(list, ft_substr(line, i_start + 1, i - i_start -1), _S_QUT_);
			return (i - i_start + 1);
		}
		i++;
	}
	lst_add(list, ft_substr(line, i_start, 1), _ERROR_);
	return(i - i_start);
}

/*функция p_check_4 обеспечивает проверку двоиных квот " 
и иx токенизацию, если квота не закрыта токен TYPE будет _ERROR_
*/

int p_check_4(char *line, t_node **list, int i)
{
	int i_start;

	i_start = i;
	i++;
	while (line[i] != '\0')
	{
		if (line[i] == 34)
		{
			lst_add(list, ft_substr(line, i_start + 1, i - i_start -1), _D_QUT_);
			return (i - i_start + 1);
		}
		i++;
	}
	lst_add(list, ft_substr(line, i_start, 1), _ERROR_);
	return(i - i_start);
}

/*функция p_check_5 обеспечивает проверку переменных 
и иx токенизацию */

int p_check_5(char *line, t_node **list, int i)
{
	int i_start;

	i++;
	i_start = i;
	while (line[i] != '\0')
	{
		if (line[i] == '<' || line[i] == '>' || line[i] == ' ')
		{
			lst_add(list, ft_substr(line, i_start, i - i_start),_VAR_);
			return (i - i_start + 1);
		}
		if (line[i] == '|')
		{
			lst_add(list, ft_substr(line, i_start, i - i_start),_VAR_);
			return (i - i_start + 1);
		}
		i++;
	}
	lst_add(list, ft_substr(line, i_start, i - i_start),_VAR_);
	return (i - i_start + 1);
}