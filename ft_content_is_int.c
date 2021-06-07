/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:23:21 by apinto            #+#    #+#             */
/*   Updated: 2021/06/07 10:10:45 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_content_is_int(char	*content)
{
	int sign;

	sign = 0;
	if (ft_strcmp(content, "-") == 0)
		return (0);
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
