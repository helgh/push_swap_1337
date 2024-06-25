/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:24:26 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/23 17:38:18 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	retate_stack(t_list **stack)
{
	t_list	*lst;

	lst = *stack;
	(*stack) = (*stack)->next;
	lst->next = NULL;
	ft_lstadd_back(stack, lst);
}

void	ra_rb_rr(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a' && ft_lstsize(*stack_a) > 1)
	{
		retate_stack(stack_a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b' && ft_lstsize(*stack_b) > 1)
	{
		retate_stack(stack_b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
			return ;
		retate_stack(stack_a);
		retate_stack(stack_b);
		write(1, "rr\n", 3);
	}
}

static void	reverse_retate_stack(t_list **stack)
{
	t_list	*lst;
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	lst = tmp->next;
	ft_lstadd_front(stack, lst);
	tmp->next = NULL;
}

void	rra_rrb_rrr(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a' && ft_lstsize(*stack_a) > 1)
	{
		reverse_retate_stack(stack_a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b' && ft_lstsize(*stack_b) > 1)
	{
		reverse_retate_stack(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
			return ;
		reverse_retate_stack(stack_a);
		reverse_retate_stack(stack_b);
		write(1, "rrr\n", 4);
	}
}
