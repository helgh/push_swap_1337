/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:39:36 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/23 21:02:26 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midle(t_list *stack_a)
{
	int		i;
	int		m;
	t_list	*tmp;
	t_list	*lst;

	i = 0;
	lst = stack_a;
	m = (ft_lstsize(stack_a) / 2);
	while (stack_a->next != NULL)
	{
		tmp = lst;
		i = 0;
		while (tmp != NULL)
		{
			if (stack_a->nbr < tmp->nbr)
				i += 1;
			tmp = tmp->next;
		}
		if (i == m)
			return (stack_a->nbr);
		stack_a = stack_a->next;
	}
	return (0);
}

static int	check_max(t_list *stack_a)
{
	int		i;
	t_list	*tmp;
	t_list	*lst;

	i = 0;
	lst = stack_a;
	while (lst != NULL)
	{
		tmp = stack_a;
		while (tmp != NULL)
		{
			if (tmp->nbr > lst->nbr)
				break ;
			else if (tmp->next == NULL)
				return (lst->nbr);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (-1);
}

void	cont_work(t_list **stack_a, t_list **stack_b, t_move **m1)
{
	if ((*m1)->rra > 0)
	{
		rra_rrb_rrr(stack_a, stack_b, 'a');
		(*m1)->rra--;
	}
	else if ((*m1)->ra > 0)
	{
		ra_rb_rr(stack_a, stack_b, 'a');
		(*m1)->ra--;
	}
	if ((*m1)->rrb > 0)
	{
		rra_rrb_rrr(stack_a, stack_b, 'b');
		(*m1)->rrb--;
	}
	else if ((*m1)->rb > 0)
	{
		ra_rb_rr(stack_a, stack_b, 'b');
		(*m1)->rb--;
	}
}

void	do_move(t_list **stack_a, t_list **stack_b, t_move **m1)
{
	int	i;

	i = (*m1)->cost;
	while (i > 0)
	{
		while ((*m1)->rra > 0 && (*m1)->rrb > 0)
		{
			rra_rrb_rrr(stack_a, stack_b, 'r');
			(*m1)->rra--;
			(*m1)->rrb--;
		}
		while ((*m1)->ra > 0 && (*m1)->rb > 0)
		{
			ra_rb_rr(stack_a, stack_b, 'r');
			(*m1)->ra--;
			(*m1)->rb--;
		}
		cont_work(stack_a, stack_b, m1);
		i--;
	}
	pa_pb(stack_a, stack_b, 'a');
}

int	sort_more_than_5_number(t_list **stack_a, t_list **stack_b)
{
	int		midle;
	int		max;
	t_move	*m1;

	max = check_max(*stack_a);
	midle = find_midle(*stack_a);
	while (ft_lstsize(*stack_a) > 5)
	{
		if (max == (*stack_a)->nbr)
			ra_rb_rr(stack_a, stack_b, 'a');
		pa_pb(stack_a, stack_b, 'b');
		if ((*stack_b)->nbr > midle)
			ra_rb_rr(stack_a, stack_b, 'b');
	}
	sort_5_number(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		m1 = initial_move(0, NULL);
		if (m1 == NULL || count_move(*stack_a, *stack_b, &m1) == -1)
			return (-1);
		do_move(stack_a, stack_b, &m1);
		free(m1);
	}
	finish_sort(stack_a, stack_b);
	return (0);
}
