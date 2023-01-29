#include "minishell.h"

void f_h_doc(t_par **par)
{
	t_node *list;
	t_h_ret ret;
	list = *(*par)->list;
	while (list != NULL)
	{
		if (list->type == 7 && list->next->type == 1)
			ret = f_h_read(par, list->next->next->token);
		if (list->type == 7 && list->next->type != 1)
			ret = f_h_read(par, list->next->token);
		if (list->type == 7)
		{
		list->fd = ret.fd;
		list->f_name = ret.f_name;
		}
		list = list->next;
	}
}

t_h_ret f_h_read(t_par **par, char *dlmt)
{
	char *filename;
	char *line;
	int	fd;
	int len;
	t_h_ret ret;

	filename = f_h_cr_nm();
	fd = open(filename,O_RDWR | O_CREAT, 0600);
	line = readline(">");
	len = ft_strlen(line);
	while (ft_strncmp(dlmt, line,len))
	{
		if (line == NULL)
			write(fd,"\n",1);
		else
			write(fd,line,len);
		write(fd,"\n",1);*
		line = readline(">");
		len = ft_strlen(line);
	}
	ret.fd = fd;
	ret.f_name = filename;
	return (ret);
}

char *f_h_cr_nm(void)
{
	static char f_count = 48;
	char *filename;
	char *pref;
	int	i;

	i = 0;
	pref = "/tmp/h_doc_";
	filename = (char *)malloc(13);
	while (*pref != '\0')
		filename[i++] = *pref++;
	filename[i++] = f_count;
	filename[i++] = '\0';
	f_count++;
	if (f_count == 48 + 9)
		f_count = 48;
	return (filename);
}

//petqa stugel $ - i pah@ u * ov toxum writein tal chisht parametr
//ev dup ov kapel miangamic input kam output in misht ashxatuma verjin inputn u output@ 
// myusneri hamar petq chi dup anel uxaki bacvum pakvum en 

char *ln_chk(char *line)
{
	char *tmp;
	char *ret;
	int v_chk;

	tmp = line;
	while (tmp != '\0')
	{
		if (*tmp == '$')
		break ;
		tmp++;
	}
	v_chk = f_var_checker(tmp, par);
}