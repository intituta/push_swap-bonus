/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:04:58 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:05:02 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	s;

	if (ac == 1)
		return (1);
	ft_create_str(ac, av, &s);
	ft_check_args(&s);
	ft_create_lists(&s);
	ft_sort_args(&s);
	ft_put_index(&s);
	if (s.len <= 3)
		ft_sort_three(&s);
	else if (s.len <= 5)
		ft_sort_five(&s);
	else
		ft_big_sort(&s);
	ft_free(&s);
}
