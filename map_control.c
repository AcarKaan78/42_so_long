/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:36:59 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:19 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_check(t_list *t_data, int int_i, int int_j)
{
	if (t_data->map[int_i][int_j] == 'P')
		t_data->playercount++;
	else if (t_data->map[int_i][int_j] == 'E')
		t_data->exitcount++;
	else if (t_data->map[int_i][int_j] == 'C')
		t_data->collectablecount++;
	else if (t_data->map[int_i][int_j] != '1'
		&& t_data->map[int_i][int_j] != '0' &&
		t_data->map[int_i][int_j] != '\n' && t_data->map[int_i][int_j] != '\0')
		error();
}

static void	map_check2(t_list *t_data)
{
	int	int_i;
	int	int_j;

	int_i = 0;
	int_j = 0;
	while (int_i <= t_data->maprow)
	{
		if (t_data->map[int_i][0] != '1' ||
			t_data->map[int_i][t_data->mapcolumn] != '1')
			error();
		while (int_j <= t_data->mapcolumn)
		{
			if (t_data->map[0][int_j] != '1' ||
				t_data->map[t_data->maprow][int_j] != '1')
				error();
			int_j++;
		}
		int_j = 0;
		int_i++;
	}
}

void	map_control(t_list *t_data)
{
	int	int_i;
	int	int_j;

	int_i = 0;
	int_j = 0;
	t_data->collectablecount = 0;
	t_data->exitcount = 0;
	t_data->playercount = 0;
	map_check2(t_data);
	while (int_i < t_data->maprow)
	{
		while (int_j < t_data->mapcolumn)
		{
			char_check(t_data, int_i, int_j);
			int_j++;
		}
		int_j = 0;
		int_i++;
	}
	if (t_data->playercount != 1 || t_data->collectablecount < 1
		|| t_data->exitcount != 1)
		error();
}
