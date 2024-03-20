/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:47:02 by asenel            #+#    #+#             */
/*   Updated: 2023/12/27 00:27:42 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_substr(char const *char_s, int int_start, size_t size_len);
char	*ft_strdup(const char *char_s1);
int		ft_strlen(const char *char_str);
char	*ft_strchr(const char *char_s, int int_c);
char	*ft_strjoin(char *char_s1, char const *char_s2);
char	*get_next_line(int fd);

#endif