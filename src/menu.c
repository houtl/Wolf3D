/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:01:06 by thou              #+#    #+#             */
/*   Updated: 2017/09/10 17:25:02 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_choise_1(t_a *a)
{
	if (a->m.choise == 1)
		mlx_string_put(a->mlx, a->win, 900, 575, GREEN, "=> NEW GAME");
	else if (a->m.choise == 2)
		mlx_string_put(a->mlx, a->win, 919, 590, GREEN, "=> GOOD");
	else if (a->m.choise == 3)
		mlx_string_put(a->mlx, a->win, 919, 605, GREEN, "=> EXIT");
	else if (a->m.choise == 4)
		mlx_string_put(a->mlx, a->win, 908, 560, GREEN, "=> CONTINU");
}

void	ft_choise(t_a *a, int keycode)
{
	if (keycode == KEY_UP)
	{
		if (a->m.choise > 1)
			a->m.choise--;
		else if (a->game_start == 1)
			a->m.choise = 4;
		else
			a->m.choise = 3;
	}
	else if (keycode == KEY_DOWN)
	{
		if (a->m.choise == 3 && a->game_start != 1)
			a->m.choise = 1;
		else if (a->m.choise == 4)
			a->m.choise = 1;
		else
			a->m.choise++;
	}
	ft_choise_1(a);
}

void	ft_menu(t_a *a, int keycode)
{
	mlx_clear_window(a->mlx, a->win);
	a->img = mlx_xpm_file_to_image(a->mlx, MENU, &(a->i), &(a->j));
	mlx_put_image_to_window(a->mlx, a->win, a->img,
			(WIDTH - a->i) / 2, (HEIGHT - a->j) / 2);
	mlx_string_put(a->mlx, a->win, 940, 500, GRAY, "WOLF3D");
	if (a->game_start == 1)
		mlx_string_put(a->mlx, a->win, 938, 560, GOLD, "CONTINU");
	mlx_string_put(a->mlx, a->win, 930, 575, GOLD, "NEW GAME");
	mlx_string_put(a->mlx, a->win, 949, 590, GOLD, "GOOD");
	mlx_string_put(a->mlx, a->win, 949, 605, GOLD, "EXIT");
	ft_choise(a, keycode);
	if (keycode == KEY_ENTER && a->m.choise == 3)
		ft_error("EXIT");
	if (keycode == KEY_ENTER && a->m.choise == 2)
	{
	}
	if (keycode == KEY_ENTER && a->m.choise == 1)
	{
	}
	if (keycode == KEY_ENTER && a->m.choise == 4)
	{
	}
}
