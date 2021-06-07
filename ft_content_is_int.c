/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:23:21 by apinto            #+#    #+#             */
/*   Updated: 2021/06/07 05:44:26 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_content_is_int(char	*content)
{
	int sign;

	sign = 0;
	while (*content)
	{
		if ((!(ft_isdigit(*content)) && *content != '-') ||
			(*content == '-' && sign == 1))
			return (0);
		if (*content == '-')
			sign = 1;
		content++;
	}
	return (1);
}
