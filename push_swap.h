/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-ghd <hael-ghd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:05 by hael-ghd          #+#    #+#             */
/*   Updated: 2024/03/25 20:51:05 by hael-ghd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/************************_libft_functions_************************/

int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const	*s1, char const *s2, char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
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

typedef struct s_move
{
	int				cost;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	struct s_move	*next;
}				t_move;
int		find_small_nbr(t_list *stack_a);
int		find_larger_nbr(t_list *stack_a);
void	find_local(t_list *stack);
void	sort_3_number(t_list **stack_a, t_list **stack_b);
void	sort_4_number(t_list **stack_a, t_list **stack_b);
void	sort_5_number(t_list **stack_a, t_list **stack_b);
int		sort_more_than_5_number(t_list **stack_a, t_list **stack_b);
int		get_index_number(t_list *stack_a, t_list *tmp_b);
int		count_move(t_list *stack_a, t_list *stack_b, t_move **m1);
void	do_move(t_list **stack_a, t_list **stack_b, t_move **m1);
void	cont_work(t_list **stack_a, t_list **stack_b, t_move **m1);
t_move	*initial_move(int nb, t_move *str);
void	finish_sort(t_list **stack_a, t_list **stack_b);

#endif