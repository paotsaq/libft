/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:23:21 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 09:13:39 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_content_is_int(char *src)
{
	int		size;
	int		value;
	char	*number_in_string;

	size = ft_strlen(src);
	number_in_string = ft_itoa(ft_atoi(src));
	value = (!(size != ft_strlen(number_in_string)
		|| ft_strncmp(src, number_in_string, size)));
	free(number_in_string);
	return (value);
}
