/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:57:02 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:25 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_code(int int_code, t_mlxlist *t_mlx_data)
{
	if (int_code == 13)
		press_w(t_mlx_data, t_mlx_data->data);
	else if (int_code == 1)
		press_s(t_mlx_data, t_mlx_data->data);
	else if (int_code == 2)
		press_d(t_mlx_data, t_mlx_data->data);
	else if (int_code == 0)
		press_a(t_mlx_data, t_mlx_data->data);
	else if (int_code == 53 || int_code == 17)
		press_esc(t_mlx_data);
	return (0);
}

static void	draw_map(t_mlxlist *t_mlx_data, t_list *t_data)
{
	drawoneandzero(t_mlx_data, t_data);
	drawextras(t_mlx_data, t_data);
}

static void	mlx_initialize(t_mlxlist *t_mlx_data, t_list *t_data)
{
	t_mlx_data->mlxinit = mlx_init();
	t_mlx_data->screen = mlx_new_window(t_mlx_data->mlxinit,
			(t_data->mapcolumn + 1) * 64, (t_data->maprow + 1) * 64,
			"Run Jerry Run, Tom Is Coming!");
}

void	mlx_operations(t_list *t_data)
{
	t_mlxlist	*t_mlx_data;

	t_mlx_data = malloc(sizeof(t_mlxlist));
	mlx_initialize(t_mlx_data, t_data);
	mlximages(t_mlx_data);
	draw_map(t_mlx_data, t_data);
	print_step();
	t_mlx_data->data = t_data;
	mlx_hook(t_mlx_data->screen, 2, 0, key_code, t_mlx_data);
	mlx_hook(t_mlx_data->screen, 17, 0, press_esc, t_mlx_data);
	mlx_loop(t_mlx_data->mlxinit);
}

void	if_exit_and_character(t_list *t_data)
{
	if (t_data->map[t_data->playerrow][t_data->playercolumn] == 'E'
		&& t_data->collectablecount == 0)
	{
		ft_print("Well Done! Happy ending!\n");
		exit(0);
	}
}
