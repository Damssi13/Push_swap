#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_stack{
    int     content;
    int     index;
    struct s_stack *next;
}t_stack;


#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void        destroy_res(char **res);
char         **parsing_args(int ac, char **av);
void        double_num_check(int   *arrat, int size, char **res);
int         *fill_array(char **res);
void        check_unit(char *str, char **res, int *array);
void        space_check(char *str, char *to_be_free);
void        sort_array(int *a, int size);

void    init_stack(t_stack **a, char **str, int *array);
void    clear_stack(t_stack *a);
#endif