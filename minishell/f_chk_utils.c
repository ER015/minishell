#include "minishell.h"

void    f_chk_3(char *ptr, t_node **temp)
{
    if (!f_env_val_chk(ptr))
        (*temp)->fd = open(ptr, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    else
        printf("No such file or directory\n");
}

void    f_chk_4(char *ptr, t_node **temp, t_par **par)
{
    char *tmp_chk;

    tmp_chk = f_env_ind(f_var_checker(ptr, *par), par);
    if (!f_env_val_chk(tmp_chk))
        (*temp)->fd = open(tmp_chk, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    else 
        printf("%s :Is a directory\n",tmp_chk);

}

void    f_chk_5(char *ptr, t_node **temp)
{
    if (!f_env_val_chk(ptr))
        (*temp)->fd = open(ptr, O_WRONLY | O_APPEND | O_CREAT, 0644);
    else
        printf("No such file or directory\n");
}

void    f_chk_6(char *ptr, t_node **temp, t_par **par)
{
    char *tmp_chk;

    tmp_chk = f_env_ind(f_var_checker(ptr, *par), par);
    if (!f_env_val_chk(tmp_chk))
        (*temp)->fd = open(tmp_chk, O_WRONLY | O_APPEND| O_CREAT, 0644);
    else 
        printf("%s :Is a directory\n",tmp_chk);

}