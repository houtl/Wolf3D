/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:25:37 by thou              #+#    #+#             */
/*   Updated: 2017/09/05 18:08:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>
void	ft_init(t_a *a)
{
	a->menu = -1;
	a->game_start = 0;
	a->img = mlx_xpm_file_to_image(a->mlx, "assets/images/start/start.xpm", &(a->i), &(a->j));
	mlx_put_image_to_window(a->mlx, a->win, a->img, (1920 - a->i) / 2, (1080 - a->j) / 2);
	mlx_string_put(a->mlx, a->win, 960, 530, GREEN, "WOLF3D");
	mlx_string_put(a->mlx, a->win, 830, 640, YELLOW, "APPUYER SUR ENTRER POUR CONTINUER");
}

static void ft_checkfile(int fd)
{
	int		i;
	int		x;
	char	*line;
	size_t	len;
	int		last;

	i = 0;
	x = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		i++;
		if (i == 1)
			if ((len = ft_strlen(line)) < 3 || ft_stricmp(line, "1") == 0)
				ft_error("file invalide");
		if (i > 1)
			if (len != ft_strlen(line) || ft_stricmp(line, "01X") == 0 ||
					line[0] != '1' || line[ft_strlen(line) - 1] != '1')
				ft_error("file invalide");
		x += ft_charnb(line, 'X');
		last = (ft_stricmp(line, "1") == 0) ? 0 : 1;
		free(line);
	}
	if (x != 1 || last != 1 || i < 3)
		ft_error("file invalide");
}

static void	ft_checkfiles(t_a *a)
{
	int		i;

	i = 0;
	while (a->file[i])
	{
		a->fd = open(a->file[i], O_RDONLY);
		ft_checkfile(a->fd);
		close(a->fd);
		i++;
	}
}

int 		main(int ac, char **av)
{
	int		i;
	t_a		a;

	if (ac < 2)
		ft_error("\033[31;1m: Please specify at least one level map file\n"
				"\033[32;1mUsage: ./wolf3d mapfile0 [mapfile1 [...]]\n");
	i = ac;
	a.file = (char**)malloc(sizeof(char*) * i);
	a.file[i - 1] = NULL;
	while (--i > 0)
		a.file[i - 1] = ft_strdup(av[i]);
	ft_checkfiles(&a);
	if (!(a.mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a.win = mlx_new_window(a.mlx, WIDTH, HEIGHT, "WOLF3D")))
		ft_error("mlx_new_window error");
	ft_init(&a);
	mlx_hook(a.win, 17, 18, ft_error, "EXIT");
	mlx_mouse_hook(a.win, mouse_hook_func, &a);
	mlx_hook(a.win, 2, (1L << 01), key_hook_func, &a);
	mlx_loop(a.mlx);
	return (0);
}
