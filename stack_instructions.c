#include "push_swap.h"


int    swap(t_stack **stack)
{
    t_stack *tmp;

    if(*stack == NULL || (*stack)->next == NULL)
        return 0;
    tmp = (*stack)->next;
    if((*stack)->next == NULL)
        return 0;
    else
    {
      (*stack)->next = (*stack)->next->next;
      tmp->next = *stack;
      *stack = tmp;
    }
    return 1;
}
int     reverse_rotate(t_stack **stack)
{
    if(*stack == NULL || (*stack)->next == NULL)
        return 0;
    t_stack *secondLast;
    t_stack *lastNode;

    secondLast = *stack;
    while(secondLast->next->next)
        secondLast = secondLast->next;
    
    lastNode = secondLast->next;
    secondLast->next = NULL;
    lastNode->next = *stack;
    *stack = lastNode;
    return 1;
}

int     rotate(t_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return 0;

    t_stack *firstNode;
    t_stack *tmp;

    firstNode = *stack;
    *stack = (*stack)->next;
    tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = firstNode;
    firstNode->next = NULL;
    return 1;
}

int    push(t_stack **send, t_stack **receive)
{
  t_stack *tmp;
  
  tmp = *send;
  if(*send == NULL)
    return 0;

  ft_lstadd_front(receive, ft_lstnew((*send)->content));
  *send = (*send)->next;
  free(tmp);
  return 1;
}





void    ft_ps(t_stack **a, t_stack **b, char c)/////PUSH_A
{
    if(c == 'a')
    {
        if(push(a,b))
            write(1,"pb\n",3);
    }
    else
    {
        if(push(b,a))
            write(1,"pa\n",3);
    }
}

void    ft_ss(t_stack **a, t_stack **b, char c)
{
    if(c == 'a')
    {
        if(swap(a))
            write(1, "sa\n",3);
    }
    else
    {
        if(swap(b))
            write(1, "sb\n",3);
    }
}



void    ft_rs(t_stack **a, t_stack **b, char c)
{
    if(c == 'a')
    {
        if(rotate(a))
            write(1,"ra\n",3); 
    }
    else
        if(rotate(b))
            write(1,"rb\n",3); 
        
}

void    ft_rrs(t_stack **a, t_stack **b, char c)
{
    if(c == 'a')
    {
        if(reverse_rotate(a))
            write(1, "rra\n", 4);
    }
    else
        if(reverse_rotate(b))
            write(1, "rrb\n",4);

}