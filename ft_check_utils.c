/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:12:29 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 21:53:07 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_str(int ac, char **av, t_stacks *s)
{
	int		i;

	i = 1;
	s->str = ft_strdup(av[1]);
	while (++i < ac)
		s->str = ft_strjoin(ft_strjoin(s->str, " "), av[i]);
	s->len = 0;
	while (ft_split(s->str, ' ')[s->len])
		s->len++;
	s->nums = malloc(sizeof(int *) * (s->len));
	if (!s->nums)
		ft_error();
	i = -1;
	while (++i < s->len)
		s->nums[i] = ft_atoi(ft_split(s->str, ' ')[i]);
}

void	ft_check_args(t_stacks *s)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i + 1 < s->len)
	{
		j = i + 1;
		while (j < s->len)
			if (s->nums[i] == s->nums[j++])
				ft_error();
		if (s->nums[i] > s->nums[i + 1])
			flag = 1;
	}
	if (!flag)
		exit(0);
}
