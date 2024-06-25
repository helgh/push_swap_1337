/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:16:27 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/24 23:43:06 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	coppy(char *all, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		all[i] = s[i];
		i++;
	}
	all[i] = 0;
}

char	*ft_strjoin(char const	*s1, char const *s2, char *str)
{
	int		i;
	int		s;
	char	*all;

	i = 0;
	s = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		s = ft_strlen(s2);
	all = malloc(sizeof(char) * (i + s + 1));
	if (all == NULL && str != NULL)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	else if (all == NULL)
		exit(EXIT_FAILURE);
	if (s1 != NULL)
		coppy(all, s1);
	if (s2 != NULL)
		coppy((all + i), s2);
	return (all);
}

int	ft_atoi(const char *str)
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
	return (result * sign);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}
