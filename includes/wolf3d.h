/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:42:05 by thou              #+#    #+#             */
/*   Updated: 2017/04/22 17:07:02 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include "mlx.h"
#include "libft.h"
#include "mlx_key.h"
#include <math.h>

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**file;
	char		*date;
	int			color;
	int			bpp;
	int			sl;
	int			ed;
	int			pos_x;
	int			pos_y;
}				t_a;

/*
**				info.c
*/

void			ft_error(char *str);

#endif
