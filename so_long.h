/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:45:01 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 01:23:36 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line_bonus.h"
# include "minilibx/mlx.h"

typedef struct s_list
{
	char	*mapname;
	char	**map;
	char	**tempmap;
	int		playerrow;
	int		playercolumn;
	int		accessexit;
	int		maprow;
	int		mapcolumn;
	int		collectablecount;
	int		exitcount;
	int		playercount;
	int		move;
}	t_list;

typedef struct s_mlxlist
{
	void	*data;
	void	*mlxinit;
	void	*screen;
	void	*coin1;
	void	*manl;
	void	*manr;
	void	*manfront;
	void	*manback;
	void	*one;
	void	*zero;
	void	*exit;
	int		height;
	int		width;
}	t_mlxlist;

void	ft_print(char *char_a);
void	process_map_file(char *char_map, t_list *t_data);
void	error(void);
void	map_control(t_list *t_data);
void	map_accessible(t_list *t_data, int int_row, int int_col);
void	map_accessible_check(t_list *t_data);
void	find_player(t_list *t_data);
void	mlx_operations(t_list *t_data);
int		press_w(t_mlxlist *t_m, t_list *t_data);
int		press_a(t_mlxlist *t_m, t_list *t_data);
int		press_d(t_mlxlist *t_m, t_list *t_data);
int		press_s(t_mlxlist *t_m, t_list *t_data);
int		press_esc(t_mlxlist *t_m);
void	drawextras(t_mlxlist *m, t_list *data);
void	drawoneandzero(t_mlxlist *t_m, t_list *t_data);
void	mlximages(t_mlxlist *mlxdata);
void	print_step(void);
void	if_exit_and_character(t_list *t_data);
char	*ft_itoa(int int_n);
int		is_null(char *char_a);
void	if_null(int int_len, char *char_a, int int_c, int int_d);

#endif