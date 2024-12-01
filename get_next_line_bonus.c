/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:52:48 by made-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:41:10 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	while (*buff[fd] || bytes_read > 0)
	{
		if (!*buff[fd])
		{
			bytes_read = handle_read(fd, buff[fd]);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_strjoin(line, buff[fd]);
		if (ft_newline(buff[fd]))
			break ;
	}
	return (line);
}

/*int	main()
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	int		finished_fd1;
	int		finished_fd2;

	fd1 = open("Test1.txt", O_RDONLY);
	fd2 = open("Test2.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	finished_fd1 = 0;
	finished_fd2 = 0;
	while (!finished_fd1 || !finished_fd2)
	{
		if (!finished_fd1)
		{
			line1 = get_next_line(fd1);
			if (line1)
			{
				printf("FD1: %s", line1);
				free(line1);
			}
			else
				finished_fd1 = 1;
		}
		if (!finished_fd2)
		{
			line2 = get_next_line(fd2);
			if (line1)
			{
				printf("FD2: %s", line2);
				free(line2);
			}
			else
				finished_fd2 = 1;
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
