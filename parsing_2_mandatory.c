/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2_mandatory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:04:28 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/26 20:59:47 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	for_norm(char c)
{
	if (c == 45 || c == 32 || c == 43 || c == 0)
		return (-1);
	return (0);
}

int	help_func(char **str, int len_str)
{
	int	i;
	int	s;
	int	l;

	s = 1;
	while (s < len_str)
	{
		l = 1;
		i = 0;
		while (str[s][i] != 0)
		{
			if (str[s][i] >= 48 && str[s][i] <= 57)
				l = 0;
			if (str[s][i] != 32 && str[s][i] != 45 && str[s][i] != 43)
				if (str[s][i] < 48 || str[s][i] > 57)
					return (-1);
			i++;
		}
		if (l == 1)
			return (-1);
		s++;
	}
	return (0);
}

void	clean_buffer(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	help_parsing(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (result > 2147483647 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (-1);
	return (0);
}
