/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:05:40 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:05:42 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *s, int flag)
{
	t_list	*tmp;

	if (!s->a || !s->a->next)
		return ;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->a->next;
	s->a->next = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stacks *s, int flag)
{
	t_list	*tmp;

	if (!s->b || !s->b->next)
		return ;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->b->next;
	s->b->next = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stacks *s, int flag)
{
	ft_sa(s, 0);
	ft_sb(s, 0);
	if (flag)
		write(1, "ss\n", 3);
}
