/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocates_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:30:18 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 08:47:14 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reallocates_memory(void *old, size_t count, size_t size, int offset)
{
	void	*ptr;
	int		i;

	i = -1;
	if (count == 0 || size == 0)
		free(old);
	ptr = ft_calloc(count, size);
	if (ptr)
	{
		while (++i < (int)count - 1)
		{
			if (size == 1)
				((char *) ptr)[i] = ((char *) old)[i + offset];
			else
				((char **) ptr)[i] = ((char **) old)[i + offset];
		}
		if (size == 1)
			((char *)ptr)[i] = 0;
		else
			((char **)ptr)[i] = 0;
		free(old);
	}
	return (ptr);
}
