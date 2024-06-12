#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_stack{
    int     value;
    int     len;
    int     *array;
    struct s_stack *next;
}t_stack;


#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    destroy_res(char **res);

#endif