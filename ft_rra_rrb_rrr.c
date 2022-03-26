/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:05:47 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:05:50 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *s, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!s->a || !s->a->next)
		return ;
	tmp = s->a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = s->a;
	s->a = tmp2;
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks *s, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!s->b || !s->b->next)
		return ;
	tmp = s->b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = s->b;
	s->b = tmp2;
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *s, int flag)
{
	ft_rra(s, 0);
	ft_rrb(s, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
