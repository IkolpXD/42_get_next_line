/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:52:48 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:10 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
ssize_t	handle_read(int fd, char *buff);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
int		ft_newline(char *buff);
char	*ft_strchr(char *s, int c);

#endif