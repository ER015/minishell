#include "minishell.h"

/*
20230121
Checker_1 for > outfile case
*/

void f_checker_1(t_par **par)
{
    t_node  *temp;
    temp = *(*par)->list;
    char *ptr;
	char *tmp_chk;

    while (temp != NULL)
    {
        if (temp->type == 4)
        {
            if (temp->next->type == 1)
                ptr = temp->next->next->token;
            else
               ptr = temp->next->token;
			tmp_chk = ptr;
			if (f_var_checker(ptr, *par) == -3 || f_var_checker(ptr, *par) == -2)
                temp->fd = open(ptr, O_WRONLY | O_TRUNC | O_CREAT, 0644);
            else if (f_var_checker(ptr, *par) == -1)
                printf("%s :ambigious redirect\n",ptr);
            else if (f_var_checker(ptr, *par) >= 0)
            {
                tmp_chk = f_env_ind(f_var_checker(ptr, *par), par);
                printf("%s\n",tmp_chk);
                if (!f_env_val_chk(tmp_chk))
                    temp->fd = open(tmp_chk, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                else 
                    printf("%s :Is a directory\n",tmp_chk);
            }



			//else if (f_var_checker(ptr, *par) = -2)
			//	temp->fd = open(ptr, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			//else if (f_var_checker(ptr, *par) = -2)
			//	ptr = f_env_ind(f_var_checker(ptr, *par), par);
			//if (!f_env_val_chk(ptr))
            //	temp->fd = open(ptr, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			//else
			//	temp->fd = open(tmp_chk, O_WRONLY | O_TRUNC | O_CREAT, 0644);
				//printf("%s :Is a directory\n",tmp_chk);
			
        }
        temp = temp->next;
    }
    //stugum enq 5, 6, 7, 4, 9 TYPE CHLINI HETEVIC EKACOX@ NOR ENQ VERCNUM
    //VERCNUM  
}

void f_checker_2(t_par **par)
{
    t_node  *temp;
    temp = *(*par)->list;
    char *ptr;
	char *tmp_chk;

    while (temp != NULL)
    {
        if (temp->type == 5)
        {
            if (temp->next->type == 1)
                ptr = temp->next->next->token;
            else
               ptr = temp->next->token;
			if (f_var_checker(ptr, *par) >= 0)
				tmp_chk = f_env_ind(f_var_checker(ptr, *par), par);
			if (!f_env_val_chk(tmp_chk))
				temp->fd = open(tmp_chk, O_WRONLY | O_APPEND | O_CREAT, 0644);
			else
            	temp->fd = open(ptr, O_WRONLY | O_APPEND | O_CREAT, 0644);
				//printf("%s :Is a directory\n",tmp_chk);
        }
        temp = temp->next;
    }
}
