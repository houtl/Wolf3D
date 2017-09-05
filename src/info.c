/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:01:00 by thou              #+#    #+#             */
/*   Updated: 2017/07/23 12:27:14 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_error(char *str)
{
	ft_printf(str);
	exit(0);
	return (1);
}

void	ft_xpmtoimg(t_a *a)
{
	int	i;
	int	j;
	ft_printf("1111");
	a->xpm.start = mlx_xpm_file_to_image(a->mlx, "./assets/images/start/start.xpm", &i, &j);
	a->xpm.prods = mlx_xpm_file_to_image(a->mlx, "./assets/images/start/prods.xpm", &i, &j);
	ft_printf("2222");
}
