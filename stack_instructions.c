/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:26:37 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:31:40 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = (*stack)->next;
	if ((*stack)->next == NULL)
		return (0);
	else
	{
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	return (1);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last_node = second_last->next;
	second_last->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
	return (1);
}

int	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first_node = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first_node;
	first_node->next = NULL;
	return (1);
}

int	push(t_stack **send, t_stack **receive)
{
	t_stack	*tmp;

	tmp = *send;
	if (*send == NULL)
		return (0);
	ft_lstadd_front(receive, ft_lstnew((*send)->content));
	*send = (*send)->next;
	free(tmp);
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
