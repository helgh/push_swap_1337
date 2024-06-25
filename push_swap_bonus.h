/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:05 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/25 20:50:54 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/************************_libft_functions_************************/

int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const	*s1, char const *s2, char *str);
size_t	ft_strlen(const char *s);
typedef struct s_list
{
	int				nbr;
	int				local;
	struct s_list	*next;
}					t_list;
t_list	*ft_lstnew(int nb);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

/************************_parsing_functions_************************/

int		check_all_args(char **str, int len_str, t_list **stack_a);
int		help_parsing(const char *str);
void	clean_buffer(char **str);
int		help_func(char **str, int len_str);
int		for_norm(char c);
int		check_sort(t_list *stack_a);

/************************_moves_functions_************************/

void	pa_pb(t_list **stack_a, t_list **stack_b, char c);
void	sa_sb_ss(t_list **stack_a, t_list **stack_b, char c);
void	ra_rb_rr(t_list **stack_a, t_list **stack_b, char c);
void	rra_rrb_rrr(t_list **stack_a, t_list **stack_b, char c);

/************************_sort_functions_************************/
char	*get_next_line(int fd);
char	*find_leak(char *all);
char	*mul_str(char *all, char *str);
char	*copy_line(char *str);
char	*save_free(char *str, char *p);
int		leng(char *str);

#endif