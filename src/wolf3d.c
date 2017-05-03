/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:25:37 by thou              #+#    #+#             */
/*   Updated: 2017/05/03 18:26:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void ft_checkfile(int fd)
{
	int		i;
	int		x;
	char	*line;
	int		len;
	int		last;

	i = 0;
	x = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		i++;
		if (i == 1)
			if ((len = ft_strlen(line)) < 3 || ft_stricmp(line, "1") == 0)
				ft_error("file invalide");
		else if (i > 1)
			if (len != ft_strlen(line) || ft_stricmp(line, "01x") == 0 ||
					line[0] != '1' || line[ft_strlen(line) - 1] != 1)
				ft_error("file invalide");
		if (ft_stricmp(line, "x"))
			x = 1;
		last = (ft_stricmp(line, "1") == 0) ? 0 : 1;
		free(line);
	}
	if (x != 1 || last != 1)
		ft_error("file invalide");
}

static void	ft_checkfiles(t_a *a)
{
	int		i;

	i = 0;
	while (a->file[i])
	{
		a->fd = open(a->file[i], O_RDONLY);
		ft_checkfile(fd);
		close(fd);
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
	while (--i > 1)
		a.file[i - 1] = ft_strdup(av[i]);
	ft_checkfiles(&a);
	if (!(a.mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a.win = mlx_new_window(a.mlx, WIDTH, HEIGHT, "WOLF3D")))
		ft_error("mlx_new_window error");
	ft_menu(&a);
	return (0);
}
