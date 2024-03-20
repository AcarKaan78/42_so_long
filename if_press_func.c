/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_press_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:21:54 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:04 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_w(t_mlxlist *t_m, t_list *t_data)
{
	if (t_data->map[t_data->playerrow - 1][t_data->playercolumn] != '1')
	{
		if ((t_data->map[t_data->playerrow - 1][t_data->playercolumn] == 'E'
			&& t_data->collectablecount == 0) ||
			(t_data->map[t_data->playerrow - 1][t_data->playercolumn] != 'E'))
		{
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64 - 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->manback,
				t_data->playercolumn * 64, t_data->playerrow * 64 - 64);
			t_data->playerrow--;
			print_step();
			if (t_data->map[t_data->playerrow][t_data->playercolumn] == 'C')
			{
				t_data->collectablecount--;
				t_data->map[t_data->playerrow][t_data->playercolumn] = '0';
			}
			if_exit_and_character(t_data);
		}
	}
	return (0);
}

int	press_a(t_mlxlist *t_m, t_list *t_data)
{
	if (t_data->map[t_data->playerrow][t_data->playercolumn - 1] != '1')
	{
		if ((t_data->map[t_data->playerrow][t_data->playercolumn - 1] == 'E'
			&& t_data->collectablecount == 0) ||
			(t_data->map[t_data->playerrow][t_data->playercolumn - 1] != 'E'))
		{
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64 - 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->manl,
				t_data->playercolumn * 64 - 64, t_data->playerrow * 64);
			t_data->playercolumn--;
			print_step();
			if (t_data->map[t_data->playerrow][t_data->playercolumn] == 'C')
			{
				t_data->collectablecount--;
				t_data->map[t_data->playerrow][t_data->playercolumn] = '0';
			}
			if_exit_and_character(t_data);
		}
	}
	return (0);
}

int	press_d(t_mlxlist *t_m, t_list *t_data)
{
	if (t_data->map[t_data->playerrow][t_data->playercolumn + 1] != '1')
	{
		if ((t_data->map[t_data->playerrow][t_data->playercolumn + 1] == 'E'
			&& t_data->collectablecount == 0) ||
			(t_data->map[t_data->playerrow][t_data->playercolumn + 1] != 'E'))
		{
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64 + 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->manr,
				t_data->playercolumn * 64 + 64, t_data->playerrow * 64);
			t_data->playercolumn++;
			print_step();
			if (t_data->map[t_data->playerrow][t_data->playercolumn] == 'C')
			{
				t_data->collectablecount--;
				t_data->map[t_data->playerrow][t_data->playercolumn] = '0';
			}
			if_exit_and_character(t_data);
		}
	}
	return (0);
}

int	press_s(t_mlxlist *t_m, t_list *t_data)
{
	if (t_data->map[t_data->playerrow + 1][t_data->playercolumn] != '1')
	{
		if ((t_data->map[t_data->playerrow + 1][t_data->playercolumn] == 'E'
			&& t_data->collectablecount == 0) ||
			(t_data->map[t_data->playerrow + 1][t_data->playercolumn] != 'E'))
		{
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64 + 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->zero,
				t_data->playercolumn * 64, t_data->playerrow * 64);
			mlx_put_image_to_window(t_m, t_m->screen, t_m->manfront,
				t_data->playercolumn * 64, t_data->playerrow * 64 + 64);
			t_data->playerrow++;
			print_step();
			if (t_data->map[t_data->playerrow][t_data->playercolumn] == 'C')
			{
				t_data->collectablecount--;
				t_data->map[t_data->playerrow][t_data->playercolumn] = '0';
			}
			if_exit_and_character(t_data);
		}
	}
	return (0);
}

int	press_esc(t_mlxlist *t_m)
{
	mlx_destroy_image(t_m->mlxinit, t_m->zero);
	mlx_destroy_image(t_m->mlxinit, t_m->coin1);
	mlx_destroy_image(t_m->mlxinit, t_m->exit);
	mlx_destroy_image(t_m->mlxinit, t_m->manback);
	mlx_destroy_image(t_m->mlxinit, t_m->manfront);
	mlx_destroy_image(t_m->mlxinit, t_m->manl);
	mlx_destroy_image(t_m->mlxinit, t_m->manr);
	mlx_destroy_image(t_m->mlxinit, t_m->one);
	mlx_destroy_window(t_m->mlxinit, t_m->screen);
	ft_print("Game ended!\n");
	exit(0);
}
