/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:04:42 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:04:47 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				flag;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		len;
	int		next;
	int		*nums;
	char	*str;
	t_list	*a;
	t_list	*b;
}	t_stacks;

t_list	*ft_lst_list(t_list *s);

int		ft_strlen(char *s);
int		ft_atoi(const char *str);
int		ft_check_next(t_stacks *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_get_next_line(char **line);
int		ft_check_sort_lists(t_stacks *s);

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

void	ft_error(void);
void	ft_free(t_stacks *s);
void	ft_put_in(t_stacks *s);
void	ft_big_sort(t_stacks *s);
void	ft_sort_args(t_stacks *s);
void	ft_put_index(t_stacks *s);
void	ft_sort_five(t_stacks *s);
void	ft_sort_three(t_stacks *s);
void	ft_check_args(t_stacks *s);
void	ft_check_args(t_stacks *s);
void	ft_create_lists(t_stacks *s);
void	ft_rr(t_stacks *s, int flag);
void	ft_ss(t_stacks *s, int flag);
void	ft_sa(t_stacks *s, int flag);
void	ft_sb(t_stacks *s, int flag);
void	ft_ra(t_stacks *s, int flag);
void	ft_rb(t_stacks *s, int flag);
void	ft_pb(t_stacks *s, int flag);
void	ft_pa(t_stacks *s, int flag);
void	ft_rrr(t_stacks *s, int flag);
void	ft_rra(t_stacks *s, int flag);
void	ft_rrb(t_stacks *s, int flag);
void	ft_parser(char *str, t_stacks *s);
void	ft_create_str(int argc, char **argv, t_stacks *s);

#endif
