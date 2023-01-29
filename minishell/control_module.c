#include "minishell.h"

/*f_checker_1 for outfile*/
/*f_checker_2 for append*/

int main_control(char **envp, char *line)
{
	t_node *list;
	t_env *env;
	t_par par;
	char *str;
	int ret;

	str = ft_strtrim(line);
	ret = 0;
	list = p_input_control(str, ft_strlen(str));
	add_history(line);
	if (p_fin_check(list))
		printf("syntax error\n");
	else
	{
		env = p_env(envp);
		par.env = &env;
		par.list = &list;
		ret = control_1(&par);
		struct_free(&par);
	}
	free(str);
	return (ret);
}

/*Продалжение контроллера*/
int control_1(t_par *par)
{
	f_h_doc(&par);
	f_checker_1(&par);
	f_checker_2(&par);
	printer_1(*par->list);
	return (0);
}
