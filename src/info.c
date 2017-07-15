/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:01:00 by thou              #+#    #+#             */
/*   Updated: 2017/07/15 18:25:03 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(char *str)
{
	ft_printf(str);
	exit(0);
}

void	ft_xpmtoimg(t_a *a)
{
	a->xpm.start = mlx_xpm_to_img(a->mlx, "./assets/images/start/start.xpm");
	a->prods.prods = mlx_xpm_to_img(a->mlx, "./assets/images/start/prods.xpm");
}
