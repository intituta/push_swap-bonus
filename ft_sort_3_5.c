/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:05:32 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:05:36 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_path(int min, t_stacks *s)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = s->a;
	while (tmp)
	{
		if (tmp->index == min)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	ft_sort_five(t_stacks *s)
{
	int	len;

	s->next = 0;
	len = s->len;
	while (len-- != 3)
	{
		while (s->a->index != s->next)
		{
			if (ft_find_path(s->next, s) <= 3)
				ft_ra(s, 1);
			else
				ft_rra(s, 1);
		}
		ft_pb(s, 1);
		s->next++;
	}
	ft_sort_three(s);
	while (s->b)
		ft_pa(s, 1);
}

t_list	*ft_lst_list(t_list *s)
{
	t_list	*tmp;

	tmp = s;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_check_sort_lists(t_stacks *s)
{
	t_list	*tmp;

	tmp = s->a;
	if (!s->a)
		return (0);
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_three(t_stacks *s)
{
	while (!ft_check_sort_lists(s))
	{
		if (s->a->index > s->a->next->index
			&& s->a->index > ft_lst_list(s->a)->index)
			ft_ra(s, 1);
		else if (s->a->index > s->a->next->index)
			ft_sa(s, 1);
		else
			ft_rra(s, 1);
	}
}
