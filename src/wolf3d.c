/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:25:37 by thou              #+#    #+#             */
/*   Updated: 2017/05/02 18:20:10 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int ft_checkfile(t_a *a)
{
	int i;
	int j;

	i = 0;
	while (a->file[i])
	{
		j = 0;
		a->fd = open(a->file[i], O_RDONLY);
		while (get_next_line(a->fd, &line) > 0)
		{
			j++;
			if (


int main(int ac, char **av)
{
	int	i;
	t_a	a;

	if (ac < 2)
		ft_error("\033[31;1m: Please specify at least one level map file\n"
				"\033[32;1mUsage: ./wolf3d mapfile0 [mapfile1 [...]]\n");
	i = ac;
	a.file = (char**)malloc(sizeof(char*) * i);
	a.file[i - 1] = NULL;
	while (--i > 1)
		a.file[i - 1] = ft_strdup(av[i]);
	ft_checkfile(&a);
	if (!(a.mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a.win = mlx_new_window(a.mlx, WIDTH, HEIGHT, "WOLF3D")))
		ft_error("mlx_new_window error");
	ft_menu(&a);
	return (0);
}
