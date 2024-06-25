/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:35:13 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/24 23:44:25 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*find_leak(char *all)
{
	if (all == NULL)
		return (NULL);
	free(all);
	return (NULL);
}

int	check_new_line(char *all)
{
	if (all == NULL)
		return (0);
	while (*all != 0)
	{
		if (*all == 10)
			return (1);
		all++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*part;
	int			i;

	part = malloc(sizeof(char) * 1 + 1);
	if (part == NULL)
		return (all = find_leak(all));
	i = 1;
	while (i != 0)
	{
		if (check_new_line(all) == 1)
			break ;
		i = read(fd, part, 1);
		if (i == -1)
			return (free(part), all = find_leak(all));
		part[i] = 0;
		all = mul_str(all, part);
	}
	free(part);
	part = copy_line(all);
	all = save_free(all, part);
	return (part);
}
