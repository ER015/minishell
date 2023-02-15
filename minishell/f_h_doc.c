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
	while (ft_strcmp(dlmt, line,len))
	{
		if (line == NULL)
			break;
		else
			ln_chk(line,*par,fd);
		write(fd,"\n",1);//*
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
//heredoc@ grvuma arandzin forkov arandzin processi mej vorpeszi ctrl^C ashxati

void	ln_chk(char *line, t_par *par, int fd)
{
	char *tmp;
	char *start;
	int	i;
	char *chk;

	start = line;
	i = 0;
	while (*start != '\0')
	{
		while (*start == ' ')
			write(fd,start++,1);
		tmp = start;
		i = 0;
		while (*tmp != ' ' &&  *tmp != '\0')
			{
				i++;
				tmp++;
			}
		chk = ft_substr(start, 0, i);
		i = f_var_checker(chk, par);
		f_h_writer_1(i, fd, par, chk);
		start += ft_strlen(chk);
		free(chk);
	}
}

void f_h_writer_1(int i, int fd, t_par *par, char *chk)
{
	char *prn;
	char *temp;

	temp = chk;
	if (i >= 0)
	{
		prn = f_env_ind(i, &par);
		write(fd, prn, ft_strlen(prn));
	}
	if(*temp == '$' && (*(temp +1) == '\0' || *(temp + 1) == '$'))
		{
			write(fd, "$", 1);
			f_h_writer_1(i,fd,par,temp + 1);
		}
	else if (i == -2)
	{
		while (*temp != '$' && *temp != '\0')
			write(fd,temp++,1);
		if (*temp == '$')
		{		
			i = f_var_checker(temp, par);
			f_h_writer_1(i,fd,par,temp);	
		}
	}
}


/*
void f_h_writer_2(char *chk, int i, int fd, char *par)
{

}*/