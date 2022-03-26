/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:11 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:06:14 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stacks *s)
{
	free(s->str);
	free(s->nums);
	while (s->a)
	{
		free (s->a);
		s->a = s->a->next;
	}
}

void	ft_put_index(t_stacks *s)
{
	int		i;
	t_list	*tmp;

	tmp = s->a;
	while (tmp)
	{
		i = -1;
		while (++i < s->len)
			if (tmp->num == s->nums[i])
				tmp->index = i;
		tmp = tmp->next;
	}
}

void	ft_sort_args(t_stacks *s)
{
	int	i;
	int	tmp;
	int	flag;

	flag = 1;
	while (flag == 1)
	{
		i = -1;
		flag = 0;
		while (++i < s->len - 1)
		{
			if (s->nums[i] > s->nums[i + 1])
			{
				tmp = s->nums[i];
				s->nums[i] = s->nums[i + 1];
				s->nums[i + 1] = tmp;
				flag = 1;
			}
		}
	}
}

t_list	*ft_init_list(int num)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		ft_error();
	tmp->flag = 0;
	tmp->num = num;
	tmp->next = NULL;
	return (tmp);
}

void	ft_create_lists(t_stacks *s)
{
	int		i;
	t_list	*tmp;

	i = 0;
	s->a = ft_init_list(s->nums[i]);
	tmp = s->a;
	while (++i < s->len)
	{
		tmp->next = ft_init_list(s->nums[i]);
		tmp = tmp->next;
	}
}
