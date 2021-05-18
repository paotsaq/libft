/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:52:39 by apinto            #+#    #+#             */
/*   Updated: 2021/05/18 09:53:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	copies_memory(char *src, char *dest, int n, int term, int clean)
{
	while (*src && n--)
		*(dest++) = *(src++);
	if (term)
		*dest++ = '\0';
		if (clean)
			while(*dest)
				*dest++ = '\0';
}

static int	reads_content(int fd, char **line, char *buffer)
{
	int		length;
	int		read_res;
	char	*begg_buffer;

	begg_buffer = buffer;
	while (1)
	{
		if (!(*buffer))
			read_res = read(fd, buffer, BUFFER_SIZE);
		while(*buffer && *buffer != '\n')
			buffer++;
		if ((*buffer && *buffer == '\n') || read_res == 0)
		{
			length = buffer - begg_buffer;
			*line = malloc(length + 1);
			if (!(*line))
				return (-1);
			copies_memory(begg_buffer, *line, length, 1, 0);
			copies_memory(++buffer, begg_buffer, 1000, 1, 1);
			if (read_res != 0)
				return (1);
			else
				return (0);
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static char buffer[100][4096];

	if (!line || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	return(reads_content(fd, line, buffer[fd]));
}
