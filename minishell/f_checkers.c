#include "minishell.h"

/*
20230121
Checker_1 for > outfile case
Checker_2 for >> append case
20230215
Checker_3 for < infile case
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
			if (f_var_checker(ptr, *par) == -2)
                f_chk_3(ptr, &temp);
            else if (f_var_checker(ptr, *par) == -1)
                printf("%s :ambiguous redirect\n",ptr);
            else if (f_var_checker(ptr, *par) >= 0)
                f_chk_4(ptr, &temp, par);
        }
        temp = temp->next;
    }
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
			tmp_chk = ptr;
			if (f_var_checker(ptr, *par) == -2)
                f_chk_5(ptr, &temp);
            else if (f_var_checker(ptr, *par) == -1)
                printf("%s :ambiguous redirect\n",ptr);
            else if (f_var_checker(ptr, *par) >= 0)
                f_chk_6(ptr, &temp, par);
        }
        temp = temp->next;
    }
}


void f_checker_3(t_par **par)
{
    t_node  *temp;
    temp = *(*par)->list;
    char *ptr;
	char *tmp_chk;

    while (temp != NULL)
    {
        if (temp->type == 6)
        {
            if (temp->next->type == 1)
                ptr = temp->next->next->token;
            else
               ptr = temp->next->token;
            if (f_var_checker(ptr, *par) == -2)
                f_chk_7(ptr, &temp);
            else if (f_var_checker(ptr, *par) == -1)
                printf("%s :no such file or directory\n",ptr);
            else if (f_var_checker(ptr, *par) >= 0)
                f_chk_8(ptr, &temp, par);    
        }
        temp = temp->next;
    }
}

//##f_checker_3 u petqa uxxel vor goyutyun chunecox 
//##fileri anunneri depqum gri vor tenc file chka,
//##da f_chk_7 f_chk_8 uma 
//##es arinq
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//##bayc urish ban mnac petqa nenc anel vor noderi filename dashtum
//## lracni file anun@ menak heredoc i jamanaka lracnum!!!!!!!!!!
