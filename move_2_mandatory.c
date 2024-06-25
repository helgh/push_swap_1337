/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:22:19 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/23 17:34:38 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_element(t_list **stack)
{
	int	nb;

	nb = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = nb;
}

void	sa_sb_ss(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a' && ft_lstsize(*stack_a) > 1)
	{
		swap_element(stack_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b' && ft_lstsize(*stack_b) > 1)
	{
		swap_element(stack_b);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
			return ;
		swap_element(stack_a);
		swap_element(stack_b);
		write(1, "ss\n", 3);
	}
}

void	pa_pb(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*tmp;

	if (c == 'a')
	{
		if (ft_lstsize(*stack_b) == 0)
			return ;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_a, tmp);
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		if (ft_lstsize(*stack_a) == 0)
			return ;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_b, tmp);
		write(1, "pb\n", 3);
	}
}
