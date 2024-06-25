/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:25:39 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/28 17:00:20 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sort(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		lst = tmp->next;
		while (lst != NULL)
		{
			if (tmp->nbr > lst->nbr)
				return (-1);
			lst = lst->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	camp_move(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp("ra\n", str) == 0)
		ra_rb_rr(stack_a, stack_b, 'a');
	else if (ft_strcmp("rb\n", str) == 0)
		ra_rb_rr(stack_a, stack_b, 'b');
	else if (ft_strcmp("rr\n", str) == 0)
		ra_rb_rr(stack_a, stack_b, 'r');
	else if (ft_strcmp("rra\n", str) == 0)
		rra_rrb_rrr(stack_a, stack_b, 'a');
	else if (ft_strcmp("rrb\n", str) == 0)
		rra_rrb_rrr(stack_a, stack_b, 'b');
	else if (ft_strcmp("rrr\n", str) == 0)
		rra_rrb_rrr(stack_a, stack_b, 'r');
	else if (ft_strcmp("sa\n", str) == 0)
		sa_sb_ss(stack_a, stack_b, 'a');
	else if (ft_strcmp("sb\n", str) == 0)
		sa_sb_ss(stack_a, stack_b, 'b');
	else if (ft_strcmp("ss\n", str) == 0)
		sa_sb_ss(stack_a, stack_b, 's');
	else if (ft_strcmp("pa\n", str) == 0)
		pa_pb(stack_a, stack_b, 'a');
	else if (ft_strcmp("pb\n", str) == 0)
		pa_pb(stack_a, stack_b, 'b');
	else
		return (-1);
	return (0);
}

static int	checker_work(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move != NULL)
	{
		if (camp_move(stack_a, stack_b, move) == -1)
		{
			free(move);
			return (-1);
		}
		free(move);
		move = get_next_line(0);
	}
	free(move);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (check_all_args(av, ac, &stack_a) == -1)
		ft_putendl_fd("Error", 2);
	if (checker_work(&stack_a, &stack_b) == -1)
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		ft_putendl_fd("Error", 2);
	}
	if (stack_a == NULL || check_sort(stack_a) == -1 || stack_b != NULL)
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		ft_putendl_fd("KO", 1);
	}
	write(1, "OK\n", 3);
	ft_lstclear(&stack_a);
}
