/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:06:07 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 01:24:13 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_list));
		process_map_file(argv[1], data);
		mlx_operations(data);
	}
	else
		error();
	return (0);
}
