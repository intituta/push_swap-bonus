/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:03 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:06:07 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stacks *s, int flag)
{
	t_list	*tmp;

	if (!s->a)
		return ;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	if (flag)
		write(1, "pb\n", 3);
}

void	ft_pa(t_stacks *s, int flag)
{
	t_list	*tmp;

	if (!s->b)
		return ;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	if (flag)
		write(1, "pa\n", 3);
}
