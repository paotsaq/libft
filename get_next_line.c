/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:21:27 by apinto            #+#    #+#             */
/*   Updated: 2021/04/25 08:06:21 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void    advance_buffer_index(char **buffer, int index)
{
	if (*(buffer) + index)
		*buffer = *(buffer) + index;
	else
		*buffer = 0;
}

static	int		handles_memory(storage *result, int initialise)
{
	if (initialise)
	{
		result->content = ft_calloc(1, sizeof(char *));
		if (!result->content)
			return (-1);
		if (!result->buffer)
			result->buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!result->buffer)
		{
			free(result->content);
			return (-1);
		}
		result->i = 0;
		result->eof = 0;
		return (1);
	}
	else
	{
		free(result->content);
		result->content = 0;
		free(result->buffer);
		result->buffer = 0;
		return (0);
	}
}

static	void	handle_copies(char *s, int size, storage *result, int finish)
{
	char	*old_string;

	if (!result->content[result->i])
		result->content[result->i] = ft_calloc(size, sizeof(char));
	else
	{
		old_string = result->content[result->i];
		size = ft_strlen(old_string) + size;
		result->content[result->i] = ft_reallocates_memory(old_string,
			size, sizeof(char), 0);
	}
	ft_strlcat(result->content[result->i], s, size);
	if (finish)
		result->content = ft_reallocates_memory(result->content,
			(++result->i) + 1, sizeof(char *), 0);
}

static	int		retrieve_split_lines(int fd, char *buffer, storage *result, int buf_size)
{
	int			read_value;
	int			i;

	while (result->i == 0 && !result->eof)
	{
		read_value = read(fd, buffer, buf_size);
		if (read_value < 0)
			return (-1);
		if (read_value < buf_size || !read_value)
			result->eof = 1;
		i = 0;
		while (buffer && buffer[i] && i < read_value)
		{
			if (buffer[i] == '\n')
			{
				handle_copies(buffer, i + 1, result, 1);
				advance_buffer_index(&buffer, i + 1);
				read_value = read_value - i - 1;
				i = -1;
			}
			i++;
		}
		if (read_value || !(read_value || result->content[0]))
			handle_copies(buffer, i + 1, result, 0);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static storage	result;

	if (fd < 0 || fd > 4096 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!result.content && !(handles_memory(&result, 1)))
		return (-1);
	if (retrieve_split_lines(fd, result.buffer, &result, BUFFER_SIZE) == -1)
	{
		handles_memory(&result, 0);
		return (-1);
	}
	if (result.content[0])
		*line = result.content[0];
	else
		*line = ft_calloc(1, sizeof(char));
	result.content = ft_reallocates_memory(result.content, (result.i)-- + 1, sizeof(char *), 1);
	if (result.eof && result.i == -1)
		return (handles_memory(&result, 0));
	else
		return (1);
}
