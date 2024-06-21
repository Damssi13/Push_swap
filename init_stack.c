#include "push_swap.h"


t_stack     *ft_lstnew(int content)
{
    t_stack *newnode;

    newnode = malloc(sizeof(t_stack));
    if(!newnode)
        return NULL;
    newnode->content = content;
    newnode->next = NULL;
    return(newnode);
}

void    ft_lstadd_back(t_stack **a, t_stack *new)
{
    t_stack *tmp;

    tmp = *a;
    if(*a == NULL)
    {
        *a = new;
        return ;
    }
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;

}

void    init_stack(t_stack **a, char **str, int *array)
{
    int i;
    int content;

    i = 0;
    while(str[i])
    {
        content = ft_atoi(str[i], array, str);
        ft_lstadd_back(a, ft_lstnew(content));
        i++;
    }

}

int main()
{
    t_stack     *head;
    
    head = NULL;
    char *str = "-3 13 19 28 22 092";
    char **res;
    int *array;
    res = ft_split(str, ' ');

    array = malloc(sizeof(int));
    
    init_stack(&head, res, array);

    while(head)
    {
        printf("|%d|\n", head->content);
        head = head->next;
    }

    // ft_lstadd_back(&head, ft_lstnew(10));
}
