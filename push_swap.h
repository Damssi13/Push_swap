#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_stack{
    int value;
    struct s_stack *next;
}stack;


#include "./Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

stack    *add_node(stack *a, int value);

#endif