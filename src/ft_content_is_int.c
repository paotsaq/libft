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

static int	ft_isspace(int chr)
{
	return (chr == 9 || chr == 10 || chr == 11
		|| chr == 12 || chr == 13 || chr == 0 || chr == ' ');
}

static int	ft_issign(char chr)
{
	return (chr == '-' || chr == '+');
}

static int	ft_turbo_atoi(const char *str, int *error)
{
	int	sign;
	int	res;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		if ((res * 10 + (*(str) - 48)) < res)
			*error = 1;
		res = res * 10 + (*(str++) - 48);
	}
	if (*str && !ft_isdigit(*str))
		*error = 1;
	return (res * sign);
}

int	ft_content_is_int(char *src)
{
	int		value;
	int		error;

	error = 0;
	value = ft_turbo_atoi(src, &error);
	if (!error)
		return (1);
	else
		return (0);
}
