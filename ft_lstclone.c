/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:25:25 by apinto            #+#    #+#             */
/*   Updated: 2021/06/10 08:26:04 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstclone(t_list **list_to_clone)
{
	t_list **new_list;
	t_list *begg_new_list;

	new_list = malloc(sizeof(t_list **));
	if (!new_list)
		return;
	begg_new_list = *new_list;
	while (*list_to_clone)
	{
		*new_list = lst_new(*(list_to_clone)->content);
		if (!(*new_list))
			ft_lstclear(begg_new_list);
		(*list_to_clone) = (*list_to_clone)->next;
	}
	return (begg_new_list);
}
