/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_3_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:26:00 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/24 23:43:57 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new != NULL)
	{
		if (*lst != NULL)
		{
			temp = ft_lstlast((*lst));
			temp -> next = new;
		}
		else
			(*lst) = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		ft_lstclear(lst);
	else if (new != NULL)
	{
		if (*lst != NULL)
			new -> next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (*lst != NULL)
	{
		while ((*lst) != NULL)
		{
			temp = (*lst)->next;
			free(*lst);
			(*lst) = temp;
		}
	}
	lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst -> next;
		return (lst);
	}
	return (NULL);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	new -> nbr = nb;
	new -> local = 0;
	return (new);
}
