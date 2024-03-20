/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:44:40 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:13:50 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *char_s, int int_start, size_t size_len)
{
	char	*char_str;
	size_t	size_i;

	size_i = 0;
	if (!char_s)
		return (NULL);
	if (ft_strlen(char_s) < int_start)
		return (ft_strdup(""));
	char_str = (char *)malloc(sizeof(char) * (size_len + 1));
	if (!char_str)
		return (NULL);
	while (size_i < size_len && char_s[int_start] != '\0')
	{
		char_str[size_i] = char_s[int_start];
		size_i++;
		int_start++;
	}
	char_str[size_i] = '\0';
	return (char_str);
}

char	*ft_strdup(const char *char_s1)
{
	char	*char_str;
	int		int_i;

	int_i = 0;
	char_str = (char *)malloc(sizeof(char) * (ft_strlen(char_s1) + 1));
	if (!char_str)
		return (NULL);
	while (char_s1[int_i] != '\0')
	{
		char_str[int_i] = char_s1[int_i];
		int_i++;
	}
	char_str[int_i] = '\0';
	return (char_str);
}

int	ft_strlen(const char *char_str)
{
	int	int_i;

	int_i = 0;
	while (char_str[int_i] != '\0')
		int_i++;
	return (int_i);
}

char	*ft_strchr(const char *char_s, int int_c)
{
	int	int_i;

	int_i = 0;
	if (!char_s)
		return (NULL);
	while (char_s[int_i] != '\0')
	{
		if (char_s[int_i] == int_c)
			return ((char *)char_s + int_i);
		int_i++;
	}
	if (char_s[int_i] == int_c)
		return ((char *)char_s + int_i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
