/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:43:55 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:12:47 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(char *char_a)
{
	int	int_i;

	int_i = -1;
	while (char_a[++int_i])
		write(1, &char_a[int_i], 1);
}

void	error(void)
{
	ft_print("Error!\n");
	exit(-1);
}

void	print_step(void)
{
	static int	int_i = 0;

	ft_print("Step : ");
	ft_print(ft_itoa(int_i));
	ft_print("\n");
	int_i++;
}
