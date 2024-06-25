/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:05:12 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/23 21:05:35 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	find_local(*stack_a);
	i = find_small_nbr(*stack_a);
	while (i > 0 && i < ft_lstsize(*stack_a))
	{
		if (i > ft_lstsize(*stack_a) / 2)
		{
			rra_rrb_rrr(stack_a, stack_b, 'a');
			i++;
		}
		else
		{
			ra_rb_rr(stack_a, stack_b, 'a');
			i--;
		}
	}
}

int	find_larger_nbr(t_list *stack)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = stack;
	while (tmp != NULL)
	{
		lst = stack;
		while (lst != NULL)
		{
			if (tmp->nbr < lst->nbr)
				break ;
			lst = lst->next;
		}
		if (lst == NULL)
			return (tmp->local);
		tmp = tmp->next;
	}
	return (0);
}

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

void	find_local(t_list *stack)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = stack;
	while (lst != NULL)
	{
		lst->local = i;
		i++;
		lst = lst->next;
	}
}

int	find_small_nbr(t_list *stack)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = stack;
	while (tmp != NULL)
	{
		lst = stack;
		while (lst != NULL)
		{
			if (tmp->nbr > lst->nbr)
				break ;
			lst = lst->next;
		}
		if (lst == NULL)
			return (tmp->local);
		tmp = tmp->next;
	}
	return (0);
}
