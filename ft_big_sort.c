/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:31 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:06:33 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(t_list *s)
{
	int		i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int	ft_push_to_sort(t_stacks *s, int flag)
{
	if (flag)
		ft_pa(s, 1);
	s->a->flag = -1;
	ft_ra(s, 1);
	s->next++;
	ft_check_next(s);
	return (1);
}

int	ft_check_next(t_stacks *s)
{
	if (s->a->index == s->next)
		return (ft_push_to_sort(s, 0));
	if (ft_count(s->b) > 0 && s->b->index == s->next)
		return (ft_push_to_sort(s, 1));
	if (ft_count(s->b) >= 3 && ft_lst_list(s->b)->index == s->next)
	{
		ft_rrb(s, 1);
		return (ft_push_to_sort(s, 1));
	}
	if (ft_count(s->b) > 1 && s->b->next->index == s->next + 1
		&& s->a->next->index == s->next)
	{
		ft_ss(s, 1);
		s->a->flag = -1;
		ft_ra(s, 1);
		s->next++;
		return (ft_push_to_sort(s, 1));
	}
	return (0);
}

void	ft_empty_b(t_stacks *s, int flag)
{
	int	i;
	int	k;
	int	mid;

	while (s->b)
	{
		i = 0;
		flag++;
		k = ft_count(s->b);
		mid = k / 2 + s->next + 2;
		while (s->b && i++ < k)
		{
			s->b->flag = flag;
			if (s->b->index >= mid || s->b->index == s->next)
			{
				ft_pa(s, 1);
				ft_check_next(s);
			}
			else
				ft_rb(s, 1);
		}
	}
}

void	ft_big_sort(t_stacks *s)
{
	int	i;
	int	flag;

	i = 0;
	s->next = 0;
	while (i++ < s->len)
	{
		if (s->a->index <= s->len / 2)
			ft_pb(s, 1);
		else
			ft_ra(s, 1);
	}
	while (s->next < s->len)
	{
		flag = s->a->flag;
		while (s->a && s->a->flag == flag && s->next > 0)
			if (!ft_check_next(s))
				ft_pb(s, 1);
		ft_empty_b(s, flag);
	}
}
