/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:03:39 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:11:00 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_accessible(t_list *t_data, int int_row, int int_col)
{
	t_data->tempmap[int_row][int_col] = '*';
	if (t_data->tempmap[int_row - 1][int_col] != '1'
		&& t_data->tempmap[int_row - 1][int_col] != '*')
		map_accessible(t_data, int_row - 1, int_col);
	if (t_data->tempmap[int_row][int_col + 1] != '1'
		&& t_data->tempmap[int_row][int_col + 1] != '*')
		map_accessible(t_data, int_row, int_col + 1);
	if (t_data->tempmap[int_row + 1][int_col] != '1'
		&& t_data->tempmap[int_row + 1][int_col] != '*')
		map_accessible(t_data, int_row + 1, int_col);
	if (t_data->tempmap[int_row][int_col - 1] != '1'
		&& t_data->tempmap[int_row][int_col - 1] != '*')
		map_accessible(t_data, int_row, int_col - 1);
}

void	map_accessible_check(t_list *t_data)
{
	int	int_i;
	int	int_j;

	int_i = 0;
	int_j = 0;
	while (int_i < t_data->maprow)
	{
		while (int_j < t_data->mapcolumn)
		{
			if (t_data->tempmap[int_i][int_j] == 'C' ||
				t_data->tempmap[int_i][int_j] == 'P'
				|| t_data->tempmap[int_i][int_j] == 'E')
				error();
			int_j++;
		}
		int_j = 0;
		int_i++;
	}
	t_data->accessexit = 1;
}

void	find_player(t_list *t_data)
{
	int	int_i;
	int	int_j;

	int_i = 0;
	int_j = 0;
	while (int_i < t_data->maprow)
	{
		while (int_j < t_data->mapcolumn)
		{
			if (t_data->map[int_i][int_j] == 'P')
			{
				t_data->playerrow = int_i;
				t_data->playercolumn = int_j;
			}
			int_j++;
		}
		int_j = 0;
		int_i++;
	}
}
