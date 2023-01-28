#include "minishell.h"

int p_fin_check(t_node *list)
{
    int size;

    size = ft_lstsize(list) - 1;
    while (list != NULL)
    {
        if (list->ind == 0 && list->type == 9)
            return (1);
        if (list->ind == size && list->type == 9)
            return (1);
        if ((list->type == 9) && list->prev->type == 9)
            return (1);
        if (list->type == -1)
            return (1);
        if (list->ind == size && 
        (list->type == 7 || list->type == 4 || list->type == 5 || list->type == 6))
            return (1);
        if ((list->type == 4 || list->type == 5 || list->type == 9) && 
            (list->next->type == 4 || list->next->type == 5 || list->next->type == 6 || list->next-> type == 7))
            return (1);
        if ((list->type == 4 || list->type == 5 || list->type == 9) && list->next->type == 1 && 
            (list->next->next->type == 4 || list->next->next->type == 5 || list->next->next->type == 6 || list->next->next->type == 7))
            return (1);
        list = list->next;
    }
    return (0);
}

