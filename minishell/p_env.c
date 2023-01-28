#include "minishell.h"

/*
Parsing envirement
*/

t_env   *p_env(char **envp)
{
    t_env   *env;
    int     len;
    int     i;
    int     j;

    i = 0;
    env = NULL;
    while(envp[i] != 0)
    {
        j = 0;
        while(envp[i][j] != '\0')
        {
            len = ft_strlen(envp[i]) - 1;
            if(envp[i][j] == '=')
            {
                lst_add_env(&env, ft_substr(envp[i], 0, j),\
                 ft_substr(envp[i], j + 1 , len));
                    break ;
            }
            j++;
        }
        i++;
    }
    return (env);
}