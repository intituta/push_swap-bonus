/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:41 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:06:43 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parser(char *str, t_stacks *s)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(s, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(s, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(s, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(s, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(s, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(s, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(s, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(s, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(s, 0);
	else
		write(1, "Error\n", 6);
}

void	ft_put_in(t_stacks *s)
{
	char	*str;

	while (ft_get_next_line(&str) > 0)
	{
		ft_parser(str, s);
		free(str);
	}
	free(str);
	if (ft_check_sort_lists(s) != 0 && !s->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 4);
}

int	main(int ac, char **av)
{
	t_stacks	s;

	if (ac == 1)
		return (0);
	ft_create_str(ac, av, &s);
	ft_check_args(&s);
	ft_create_lists(&s);
	ft_sort_args(&s);
	ft_put_index(&s);
	ft_put_in(&s);
	ft_free(&s);
}
