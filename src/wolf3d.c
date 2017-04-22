/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:25:37 by thou              #+#    #+#             */
/*   Updated: 2017/04/22 17:40:13 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main(int ac, char **av)
{
	int	i;
	t_a	a;

	if (ac < 2)
		ft_error("\033[31;1m: Please specify at least one level map file\n"
				"\033[32;1mUsage: ./wolf3d mapfile0 [mapfile1 [...]]\n");
	i = ac;
	a.file = (char**)malloc(sizeof(char*) * i);
	a.file[i - 1] = "";
	while (--i > 1)
		a.file[i - 1] = ft_strdup(av[i]);
	return (0);
}
