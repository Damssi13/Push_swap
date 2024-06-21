#include "push_swap.h"

/***********************THE_ALGORITHEM************************/

int main(t_stack **a)
{
    init_index();//you label the index to each node;
    
    //you count the len of the stack

    int i = 0;
    int stack_len = 0; //you can have it by counting the len fun
    int range = 0; // befor you excute the algo you will need to
        //set up the range depending on the len of the stack
    while(a)
    {
        if((*a)->index <= i)
        {
            //push_to_B
            //rotate_B
            i++;
        }
        else if((*a)->index <= i + range)
        {
            //push_to_B
            i++;
        }
        // in_index func return the position of the closest value to the minimum
        // basically u check if the index's position is smaller/equal than len + range
        else if(in_index(a, i, range) <= stack_len / 2)
            //rotate_A
            ;
        else
            //reverse_rotate_A
            ;

    }
}