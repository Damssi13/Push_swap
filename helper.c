#include "push_swap.h"
void     sort_array(int *array, int size)
{
    int i;
    int tmp;

    i = 0;
    while(i < size - 1)
    {
        if(array[i] > array[i + 1])
        {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

void    destroy_res(char **res)
{
    int i;

    i = 0;
    while(res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

void    clear_stack(t_stack *a)
{
    t_stack *tmp;

    while(a)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
}

