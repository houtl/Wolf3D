/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:30:45 by thou              #+#    #+#             */
/*   Updated: 2017/09/05 18:21:28 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook_func(int keycode, t_a *a)
{
	if (keycode == KEY_ESC)
		ft_error("EXIT");
	if (a->menu < 0 && keycode == KEY_ENTER)
		a->menu = 0;
	if (a->menu == 0)
	{
		mlx_clear_window(a->mlx, a->win);
		a->img = mlx_xpm_file_to_image(a->mlx, "assets/images/start/prods.xpm", &(a->i), &(a->j));
		mlx_put_image_to_window(a->mlx, a->win, a->img, (1920 - a->i) / 2, (1080 - a->j) / 2);
		mlx_string_put(a->mlx, a->win, 960, 530, GREEN, "WOLF3D");
		mlx_string_put(a->mlx, a->win, 960, 560, YELLOW, "GOOD");
		ft_menu(a);
	}
	else
	{
	}
	return (0);
}

int		mouse_hook_func(int button, int x, int y, t_a *a)
{
	a->mx = x;
	a->my = y;
	if (button == 4)
	{

	}
	if (button == 5)
	{
	}
	return (0);
}
