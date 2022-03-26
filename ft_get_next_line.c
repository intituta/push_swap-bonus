/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:06:19 by kferterb          #+#    #+#             */
/*   Updated: 2022/03/26 22:06:21 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	i = -1;
	buf = (char *)malloc(5);
	j = read(0, &buf[++i], 1);
	while (j > 0 && buf[i] != '\n' && buf[i] != '\0')
		j = read(0, &buf[++i], 1);
	buf[i] = '\n';
	i++;
	buf[i] = '\0';
	*line = buf;
	return (j);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1 ++;
		s2 ++;
	}
	return (0);
}
