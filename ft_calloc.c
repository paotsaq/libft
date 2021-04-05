/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:12:20 by apinto            #+#    #+#             */
/*   Updated: 2021/02/23 14:03:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		amount;

	if (count == 0 || size == 0)
		amount = 1;
	else
		amount = count * size;
	ptr = malloc(amount);
	if (ptr)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	else
		return (0);
}
