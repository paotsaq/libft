/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:51:08 by apinto            #+#    #+#             */
/*   Updated: 2021/04/26 15:17:53 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int chr)
{
	return (chr == 9 || chr == 10 || chr == 11
		|| chr == 12 || chr == 13 || chr == 0 || chr == ' ');
}

static	int	ft_issign(char chr)
{
	return (chr == '-' || chr == '+');
}

static	double	ft_power(double n, int i)
{
	if (i == 1)
		return (n);
	else
		return (n * ft_power(n, i - 1));
}

double	ft_atof(const char *str)
{
	int		sign;
	double	res;
	int		power;

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
		res = res * 10 + (*(str++) - 48);
	if (*(str++) == '.')
	{
		power = 1;
		while (ft_isdigit(*str))
			res += (*(str++) - 48) / ft_power(10, power++);
	}
	return (res * sign);
}
