/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:20:33 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:10 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	number_length(int int_n)
{
	long	long_a;
	int		int_i;

	int_i = 0;
	long_a = int_n;
	if (long_a == 0)
		return (1);
	if (long_a < 0)
	{
		long_a *= -1;
		int_i++;
	}
	while (long_a > 0)
	{
		long_a /= 10;
		int_i++;
	}
	return (int_i);
}

static void	put_str(char *char_string, int int_a, int int_num_len)
{
	long	long_n;

	long_n = int_a;
	if (long_n < 0)
	{
		char_string[0] = '-';
		long_n *= -1;
	}
	if (long_n >= 10)
	{
		put_str(char_string, long_n / 10, int_num_len - 1);
		put_str(char_string, long_n % 10, int_num_len);
	}
	if (long_n < 10)
		char_string[int_num_len] = long_n + 48;
}

char	*ft_itoa(int int_n)
{
	int		int_num_len;
	char	*char_string;

	int_num_len = number_length(int_n);
	char_string = malloc((sizeof(char) * int_num_len) + 1);
	if (!char_string)
		return (0);
	put_str(char_string, int_n, int_num_len - 1);
	char_string[int_num_len] = '\0';
	return (char_string);
}
