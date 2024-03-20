/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracontrols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:12:55 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 00:22:07 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_null(char *char_a)
{
	int	int_i;

	int_i = 0;
	while (char_a[int_i] != '\0' && char_a[int_i] != '\n')
		int_i++;
	if (char_a[int_i] == '\n')
		return (1);
	else
		return (0);
	return (0);
}

void	if_null(int int_len, char *char_a, int int_c, int int_d)
{
	if (char_a == NULL && int_d == 0)
		error();
	if (int_len != (ft_strlen(char_a) + int_c) && int_d == 1)
		error();
}
