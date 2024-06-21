#include "push_swap.h"


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

int     main(int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    char        **str;
    int         *array;
    int         i;

    a = NULL;
    b = NULL;
    i = 0;
    if(ac == 1)
        return 0;

    /*-----------------------------------------------------*/
    str = parsing_args(ac,av); // you joing all the args,to parse the string

    array = fill_array(str); // filling an array;
    init_stack(&a, str, array); // initializing the stack
    push_b(a, b);


    ///////////////////////////////////////////////////////
    int j = 0;                                           //
    while(j </*should be the size of the array*/ 5)      //
    {                                                    //
        printf("%d\n", array[j]);                        //
        j++;                                             //    
    }                                                    //
                                                         //
    ///////////////////////////////////////////////////////
    while(str[i])
        i++;
    sort_array(array, i); //u sort the array so later you can get the index

    destroy_res(str);
    free(array); //you free the array;
    clear_stack(a); //free the stack
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

