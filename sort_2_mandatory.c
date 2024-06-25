/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:02:42 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/28 16:57:36 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_number(t_list *stack_a, t_list *tmp_b)
{
	t_list	*tmp_a;
	t_list	*lst;
	int		i;

	tmp_a = (stack_a);
	i = 0;
	find_local(stack_a);
	while (tmp_a != NULL)
	{
		lst = tmp_a->next;
		while (lst != NULL && tmp_a->nbr > tmp_b->nbr)
		{
			if (tmp_a->nbr > lst->nbr && lst->nbr > tmp_b->nbr)
				tmp_a = lst;
			lst = lst->next;
		}
		if (lst == NULL)
			return (tmp_a->local);
		tmp_a = tmp_a->next;
	}
	return (-1);
}

t_move	*initial_move(int nb, t_move *str)
{
	t_move	*new;

	new = (t_move *) malloc(sizeof(t_move));
	if (new == NULL && str != NULL)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	else if (new == NULL)
		return (NULL);
	new -> cost = -1;
	new -> ra = nb;
	new -> rra = nb;
	new -> rb = nb;
	new -> rrb = nb;
	new -> next = NULL;
	return (new);
}

static void	re_place(t_move **m1, t_move *fake_mv, int *arr, t_list *stack_b)
{
	if (ft_lstsize(stack_b) > 1 && arr[1] > (ft_lstsize(stack_b) / 2))
		fake_mv->rrb = ft_lstsize(stack_b) - arr[1];
	else if (ft_lstsize(stack_b) > 1 && arr[1] <= ft_lstsize(stack_b) / 2)
		fake_mv->rb = arr[1];
	fake_mv->cost = fake_mv->rb + fake_mv->rrb + fake_mv->ra + fake_mv->rra;
	if (arr[0] == -1)
		arr[0] = fake_mv->cost;
	if (arr[0] >= fake_mv->cost)
	{
		(*m1)->ra = fake_mv->ra;
		(*m1)->rra = fake_mv->rra;
		(*m1)->rb = fake_mv->rb;
		(*m1)->rrb = fake_mv->rrb;
		arr[0] = fake_mv->cost;
		(*m1)->cost = arr[0];
	}
	fake_mv->ra = 0;
	fake_mv->rra = 0;
	fake_mv->rb = 0;
	fake_mv->rrb = 0;
	fake_mv->cost = 0;
}

int	count_move(t_list *stack_a, t_list *stack_b, t_move **m1)
{
	int		i_a;
	int		arr[2];
	t_list	*tmp_b;
	t_move	*fake_mv;

	arr[0] = -1;
	arr[1] = 0;
	fake_mv = initial_move(0, *m1);
	if (fake_mv == NULL)
		return (-1);
	tmp_b = stack_b;
	while (tmp_b != NULL)
	{
		i_a = get_index_number(stack_a, tmp_b);
		if (i_a > (ft_lstsize(stack_a) / 2))
			fake_mv->rra = ft_lstsize(stack_a) - i_a;
		else if (i_a <= (ft_lstsize(stack_a) / 2))
			fake_mv->ra = i_a;
		re_place(m1, fake_mv, arr, stack_b);
		tmp_b = tmp_b->next;
		arr[1] += 1;
	}
	free(fake_mv);
	return (0);
}
