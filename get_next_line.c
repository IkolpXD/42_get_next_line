/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:52:48 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:10 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (*buff || bytes_read > 0)
	{
		if (!*buff)
		{
			bytes_read = handle_read(fd, buff);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_strjoin(line, buff);
		if (ft_newline(buff))
			break ;
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("Test1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
