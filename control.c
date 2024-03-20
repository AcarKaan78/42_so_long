/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:49:32 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 01:04:39 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_extension(char *char_map)
{
	int	int_len;

	int_len = ft_strlen(char_map) - 1;
	if (char_map[int_len] != 'r' || char_map[int_len - 1] != 'e'
		|| char_map[int_len - 2] != 'b'
		|| char_map[int_len - 3] != '.')
		error();
	if (char_map[int_len - 4] == '/' || ft_strlen(char_map) < 5)
		error();
}

static void	fill_map_data(t_list *t_data, int int_i, int int_len)
{
	int		int_row;
	int		int_column;
	int		int_fd;
	char	*char_a;

	int_row = 0;
	int_column = 0;
	int_fd = open(t_data->mapname, O_RDONLY);
	while (int_row <= int_i)
	{
		char_a = get_next_line(int_fd);
		while (int_column <= int_len)
		{
			t_data->map[int_row][int_column] = char_a[int_column];
			t_data->tempmap[int_row][int_column] = char_a[int_column];
			int_column++;
		}
		free(char_a);
		int_column = 0;
		int_row++;
	}
	t_data->maprow = int_i;
	t_data->mapcolumn = int_len;
	map_control(t_data);
}

static void	allocate_map_memory(t_list *t_data, char *char_map
							, int int_i, int int_len)
{
	int	int_m;

	int_m = 0;
	if (int_len > 41 || int_i > 21)
		error();
	t_data->mapname = char_map;
	t_data->map = malloc(sizeof(char *) * (int_i + 1));
	t_data->tempmap = malloc(sizeof(char *) * (int_i + 1));
	while (int_m <= int_i)
	{
		t_data->map[int_m] = malloc(sizeof(char) * int_len);
		t_data->tempmap[int_m] = malloc(sizeof(char) * int_len);
		int_m++;
	}
	fill_map_data(t_data, int_i, int_len);
}

static void	transfer_map_data(char *char_map, t_list *t_data)
{
	int			int_fd;
	int			int_len;
	char		*char_a;
	static int	int_i = 1;
	static int	int_c = 0;

	int_fd = open(char_map, O_RDONLY);
	char_a = get_next_line(int_fd);
	if_null(0, char_a, 0, 0);
	int_len = ft_strlen(char_a);
	while (char_a != NULL)
	{
		free(char_a);
		char_a = get_next_line(int_fd);
		if_null(0, char_a, 0, 0);
		if (is_null(char_a) == 0)
			int_c = 1;
		if_null(int_len, char_a, int_c, 1);
		int_i++;
		if (is_null(char_a) == 0)
			break ;
	}
	free(char_a);
	close(int_fd);
	allocate_map_memory(t_data, char_map, int_i - 1, int_len - 2);
}

void	process_map_file(char *char_map, t_list *t_data)
{
	int	int_fd;

	int_fd = open(char_map, O_RDONLY);
	if (int_fd != 3)
	{
		ft_print("Error!\n");
		exit(-1);
	}
	close(int_fd);
	check_map_extension(char_map);
	transfer_map_data(char_map, t_data);
	find_player(t_data);
	map_accessible(t_data, t_data->playerrow, t_data->playercolumn);
	t_data->accessexit = 0;
	map_accessible_check(t_data);
	if (t_data->accessexit != 1)
		error();
}
