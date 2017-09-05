/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:01:06 by thou              #+#    #+#             */
/*   Updated: 2017/09/05 18:20:39 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void ft_menu(t_a *a)
{
	if (a->game_start == 1)
		mlx_string_put(a->mlx, a->win, 960, 545, BLUE, "CONTINU");
	mlx_string_put(a->mlx, a->win, 960, 575, GOLD, "NEW GAME");
	mlx_string_put(a->mlx, a->win, 960, 590, GOLD, "EXIT");
	a->menu++;
}	
