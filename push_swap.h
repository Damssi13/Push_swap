/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:39:54 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:23:59 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*get_max(t_stack *stack);
t_stack				*ft_lstnew(int content);
t_stack				*get_min(t_stack *stack);
t_stack				*last_node(t_stack *stack);
char				**parsing_args(int ac, char **av);
void				destroy_res(char **res);
void				double_num_check(int *arrat, int size, char **res);
void				check_unit(char *str, char **res, int *array);
void				space_check(char *str, char *to_be_free);
void				sort_array(int *a, int size);

void				init_stack(t_stack **a, char **str, int *array);
void				ft_lstadd_back(t_stack **a, t_stack *new);
void				ft_lstadd_front(t_stack **a, t_stack *new);
void				clear_stack(t_stack *a);

void				sort_stack(t_stack **a, t_stack **b);
void				sort_three(t_stack **a, t_stack **b);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_algo(t_stack **a, t_stack **b);
void				push_back(t_stack **a, t_stack **b);
void				init_index(t_stack **stack, int *array);
void				ft_rs(t_stack **a, t_stack **b, char c);
void				ft_rrs(t_stack **a, t_stack **b, char c);
void				ft_ss(t_stack **a, t_stack **b, char c);
void				ft_ps(t_stack **a, t_stack **b, char c);
void				clear_all(t_stack **a, char **str, int *array);

int					*fill_array(char **res);
int					stack_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
int					find_index(t_stack *stack, t_stack *toFind);
int					init_range(int size);
int					in_index(t_stack *a, int len, int range);
int					get_index(int content, int *array, int len);
int					push(t_stack **send, t_stack **receive);
int					rotate(t_stack **stack);
int					reverse_rotate(t_stack **stack);
int					swap(t_stack **stack);

#endif