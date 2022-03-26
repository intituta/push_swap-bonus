/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:05:54 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:05:59 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *s, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!s->a || !s->a->next)
		return ;
	tmp2 = s->a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp = s->a;
	s->a = s->a->next;
	tmp2->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *s, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!s->b || !s->b->next)
		return ;
	tmp2 = s->b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp = s->b;
	s->b = s->b->next;
	tmp2->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *s, int flag)
{
	ft_ra(s, 0);
	ft_rb(s, 0);
	if (flag)
		write(1, "rr\n", 3);
}
