/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:47:58 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 02:12:56 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*delete_line(char *char_left)
{
	char	*char_buff;
	int		int_i;

	int_i = 0;
	while (char_left[int_i] && char_left[int_i] != '\n')
		int_i++;
	if (!char_left[int_i])
	{
		free(char_left);
		return (NULL);
	}
	int_i++;
	char_buff = ft_substr(char_left, int_i, (ft_strlen(char_left) - int_i));
	if (!char_buff)
		return (NULL);
	free(char_left);
	return (char_buff);
}

static char	*come_line(char *char_buffer)
{
	char	*char_line;
	int		int_i;

	int_i = 0;
	if (!(char_buffer[int_i]))
		return (NULL);
	while (char_buffer[int_i] != '\n' && char_buffer[int_i] != '\0')
		int_i++;
	if (char_buffer[int_i] == '\n')
		char_line = ft_substr(char_buffer, 0, int_i + 1);
	else
		char_line = ft_substr(char_buffer, 0, int_i);
	if (!char_line)
		return (NULL);
	return (char_line);
}

static char	*reading_file(int int_fd, char *char_buffer)
{
	char	*char_buff;
	int		int_byte;

	char_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!char_buff)
		return (NULL);
	int_byte = 1;
	while (!ft_strchr(char_buffer, '\n') && int_byte != 0)
	{
		int_byte = read(int_fd, char_buff, BUFFER_SIZE);
		if (int_byte == -1)
		{
			free(char_buff);
			free(char_buffer);
			return (NULL);
		}
		char_buff[int_byte] = '\0';
		char_buffer = ft_strjoin(char_buffer, char_buff);
	}
	free(char_buff);
	return (char_buffer);
}

char	*get_next_line(int int_fd)
{
	static char	*char_buffer[10240];
	char		*char_line;

	if (int_fd < 0 || BUFFER_SIZE <= 0 || int_fd > 10240)
		return (NULL);
	char_buffer[int_fd] = reading_file(int_fd, char_buffer[int_fd]);
	if (!char_buffer[int_fd])
		return (NULL);
	char_line = come_line(char_buffer[int_fd]);
	char_buffer[int_fd] = delete_line(char_buffer[int_fd]);
	return (char_line);
}
