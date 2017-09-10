/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:30:45 by thou              #+#    #+#             */
/*   Updated: 2017/09/10 17:05:21 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook_func(int keycode, t_a *a)
{
	if (keycode == KEY_ESC)
		ft_error("EXIT\n");
	if (a->m.menu < 0 && keycode == KEY_ENTER)
		a->m.menu = 0;
	if (a->m.menu == 0)
	{
		ft_menu(a, keycode);
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
