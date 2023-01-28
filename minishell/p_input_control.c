#include "minishell.h"
/* фунция p_input_params разделяет line на отдельные части */
t_node	*p_input_params(char *line)
{
	int		i;
	t_node	*list;

	list = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' || line[i] == '|')
			i += p_check_1(line, &list, i);
		else if (line[i] == '>')
			i += p_check_2(line, &list, i);
		else if (line[i] == 39)
			i += p_check_3(line, &list, i);
		else if (line[i] == 34)
			i += p_check_4(line, &list, i);
		//else if (line[i] == '$') // #2
		//	i += p_check_5(line, &list, i);// #3
		else if (line[i] == ' ')
			i += p_check_6(line, &list, i);
		else
			i += p_check_7(line, &list, i);

	}
	return(list);
	//printer_1(list);
	//ft_stack_del(&list);
}


/*p_input_control гарантирует невозможность начало и конеца строки с | 
так же передачу строки для дальнейщих действий 
елси line проходит валидацию возврашается знаюение 0, в противном случаее 1*/

t_node *p_input_control(char *line, int size)
{
	//if (line[0] == '|' || line[size - 1] == '|')
	//{
	//		printf("command not found\n");
	//		return (NULL);
	//}
	if (!ft_strncmp(line, "clear",size))
	{
		write(1, "\33[H\33[2J", 7);
		return (NULL);
	}
	return (p_input_params(line));
}

