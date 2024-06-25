/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions_1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:52:44 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/24 23:36:21 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

static int	check_value_and_duplicate(char **str)
{
	int	i;
	int	nb;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		nb = help_parsing(str[i]);
		if (nb == -1)
			return (-1);
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**join_and_split_all_args(char **str, int len_str)
{
	int		i;
	char	*swap;
	char	*tmp;
	char	**spl;

	i = 1;
	tmp = NULL;
	swap = ft_strjoin(str[i], " ", NULL);
	while (++i < len_str)
	{
		tmp = ft_strjoin(swap, " ", swap);
		free(swap);
		swap = ft_strjoin(tmp, str[i], tmp);
		free(tmp);
	}
	spl = ft_split(swap, 32);
	if (spl == NULL)
	{
		free(swap);
		exit(EXIT_FAILURE);
	}
	free(swap);
	return (spl);
}

static int	check_special_args(char **str, int len_str)
{
	int	i;
	int	s;

	i = 1;
	if (help_func(str, len_str) == -1)
		return (-1);
	while (i < len_str)
	{
		s = 0;
		while (str[i][s] != 0)
		{
			if ((str[i][s] == 45 || str[i][s] == 43) && s - 1 >= 0)
				if (str[i][s - 1] != 32)
					return (-1);
			if (str[i][s] == 45 || str[i][s] == 43)
				if (for_norm(str[i][s + 1]) == -1)
					return (-1);
			s++;
		}
		i++;
	}
	if (i == len_str)
		return (0);
	return (-1);
}

int	check_all_args(char **str, int len_str, t_list **stack_a)
{
	int		i;
	char	**buf;

	i = 0;
	if (check_special_args(str, len_str) == -1)
		return (-1);
	buf = join_and_split_all_args(str, len_str);
	if (check_value_and_duplicate(buf) == -1)
		return (clean_buffer(buf), -1);
	while (buf[i] != NULL)
		i++;
	while (--i >= 0)
	{
		ft_lstadd_front(stack_a, ft_lstnew(ft_atoi(buf[i])));
		free(buf[i]);
	}
	free(buf);
	return (0);
}
