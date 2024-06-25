/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:25:39 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/25 20:37:44 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_number(t_list **stack_a, t_list **stack_b)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*stack_a)->nbr;
	nb2 = (*stack_a)->next->nbr;
	nb3 = (*stack_a)->next->next->nbr;
	if (nb1 > nb2 && nb2 > nb3 && nb1 > nb3)
	{
		ra_rb_rr(stack_a, stack_b, 'a');
		sa_sb_ss(stack_a, stack_b, 'a');
	}
	else if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
		ra_rb_rr(stack_a, stack_b, 'a');
	else if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
		sa_sb_ss(stack_a, stack_b, 'a');
	else if (nb1 < nb2 && nb1 > nb3 && nb3 < nb2)
		rra_rrb_rrr(stack_a, stack_b, 'a');
	else if (nb2 > nb3)
	{
		rra_rrb_rrr(stack_a, stack_b, 'a');
		sa_sb_ss(stack_a, stack_b, 'a');
	}
}

void	sort_4_number(t_list **stack_a, t_list **stack_b)
{
	int	i;

	find_local(*stack_a);
	i = find_small_nbr(*stack_a);
	if (i == 1)
		ra_rb_rr(stack_a, stack_b, 'a');
	else if (i == 2)
	{
		ra_rb_rr(stack_a, stack_b, 'a');
		ra_rb_rr(stack_a, stack_b, 'a');
	}
	else if (i == 3)
		rra_rrb_rrr(stack_a, stack_b, 'a');
	pa_pb(stack_a, stack_b, 'b');
	sort_3_number(stack_a, stack_b);
	pa_pb(stack_a, stack_b, 'a');
}

void	sort_5_number(t_list **stack_a, t_list **stack_b)
{
	int	i;

	find_local(*stack_a);
	i = find_small_nbr(*stack_a);
	if (i == 1)
		ra_rb_rr(stack_a, stack_b, 'a');
	else if (i == 2)
	{
		ra_rb_rr(stack_a, stack_b, 'a');
		ra_rb_rr(stack_a, stack_b, 'a');
	}
	else if (i == 3)
	{
		rra_rrb_rrr(stack_a, stack_b, 'a');
		rra_rrb_rrr(stack_a, stack_b, 'a');
	}
	else if (i == 4)
		rra_rrb_rrr(stack_a, stack_b, 'a');
	pa_pb(stack_a, stack_b, 'b');
	if (check_sort(*stack_a) == -1)
		sort_4_number(stack_a, stack_b);
	pa_pb(stack_a, stack_b, 'a');
}

void	size_stack(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*stack_a);
	count = ft_lstsize(tmp);
	if (count == 2)
		sa_sb_ss(stack_a, stack_b, 'a');
	else if (count == 3)
		sort_3_number(stack_a, stack_b);
	else if (count == 4)
		sort_4_number(stack_a, stack_b);
	else if (count == 5)
		sort_5_number(stack_a, stack_b);
	else
		i = sort_more_than_5_number(stack_a, stack_b);
	if (i == -1)
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	if (check_all_args(av, ac, &stack_a) == -1)
		ft_putendl_fd("Error", 2);
	size_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
