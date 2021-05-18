/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:23:21 by apinto            #+#    #+#             */
/*   Updated: 2021/05/18 09:51:21 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_content_is_int(char	*content)
{
	while (*content)
		if (!(ft_isdigit(*content++)))
			return (0);
	return (1);
}
