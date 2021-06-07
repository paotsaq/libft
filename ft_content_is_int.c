/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:23:21 by apinto            #+#    #+#             */
/*   Updated: 2021/06/07 10:13:50 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_content_is_int(char	*content)
{
	int sign;

	sign = 0;
	if (ft_strcmp(content, "") == 0 || ft_strcmp(content, "-") == 0)
		return (0);
	if (*(content++) == '-')
		continue;
	while (*content)
		if (!(ft_isdigit(*content++))
			return (0);
	return (1);
}
