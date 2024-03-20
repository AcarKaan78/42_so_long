/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:56:04 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:31 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawextras(t_mlxlist *m, t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->maprow)
	{
		while (j < data->mapcolumn)
		{
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(m, m->screen, m->manr, j * 64, i * 64);
				data->map[i][j] = '0';
			}
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(m, m->screen, m->exit, j * 64, i * 64);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(m, m->screen, m->coin1, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	drawoneandzero(t_mlxlist *t_m, t_list *t_data)
{
	int	int_i;
	int	int_j;

	int_i = 0;
	int_j = 0;
	while (int_i <= t_data->maprow)
	{
		while (int_j <= t_data->mapcolumn)
		{
			if (t_data->map[int_i][int_j] == '1')
				mlx_put_image_to_window(t_m, t_m->screen,
					t_m->one, int_j * 64, int_i * 64);
			else
				mlx_put_image_to_window(t_m, t_m->screen,
					t_m->zero, int_j * 64, int_i * 64);
			int_j++;
		}
		int_j = 0;
		int_i++;
	}
}

void	mlximages(t_mlxlist *t_mlx_data)
{
	t_mlx_data->zero = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/back.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->one = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/wall.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->manl = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/manl.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->manr = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/manr.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->exit = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/exit.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->manfront = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/manf.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->manback = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/manb.xpm", &t_mlx_data->width, &t_mlx_data->height);
	t_mlx_data->coin1 = mlx_xpm_file_to_image(t_mlx_data->mlxinit,
			"textures/coin1.xpm", &t_mlx_data->width, &t_mlx_data->height);
}
