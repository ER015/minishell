#include "minishell.h"

void printer_1(t_node *temp)
{
    t_node *lst;

    lst = temp;
    while (lst != NULL)
    {
        printf("token:%s\t\ttype:%d\t\tind:%d\t\tfd:%d\n",lst->token,lst->type,lst->ind,lst->fd);
        lst = lst->next;
    }
}

void printer_2(char **str)
{
    int i = 0;
    while(str[i] != 0)
    {
        int j = 0;
        while(str[i][j] != '\0')
        {
            write(1,&str[i][j],1);
            j++;
        }
        write(1,"\n",1);
        i++;
    }
}

void printer_3(t_env *lst)
{
    while (lst != NULL)
    {
        printf("key:%s\t\tvalue:%s\n",lst->key,lst->value);
        lst = lst->next;
    }
}