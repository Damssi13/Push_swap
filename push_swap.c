#include "push_swap.h"


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

    str = parsing_args(ac,av); // you joing all the args,to parse the string
    array = fill_array(str); // filling an array; //doubleCheck
    init_stack(&a, str, array); // initializing the stack
    while(str[i])
        i++;
    sort_array(array, i); //u sort the array so later you can get the index
    init_index(&a,array);

    if(!stack_sorted(a))
        sort_stack(&a,&b);


    destroy_res(str); //free the **str
    free(array); //you free the array;
    clear_stack(a); //free the stack
}


