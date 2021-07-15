/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 08:25:25 by apinto            #+#    #+#             */
/*   Updated: 2021/07/15 08:48:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstclone(t_list *list_to_clone)
{
	t_list	*new_list;
	t_list	*begg_new_list;

	begg_new_list = NULL;
	if (list_to_clone)
	{
		new_list = ft_lstnew(list_to_clone->content);
		if (!(new_list))
		{
			ft_lstclear(&begg_new_list, &ft_free_list_content);
			return (NULL);
		}
		begg_new_list = new_list;
		while (list_to_clone->next)
		{
			new_list->next = ft_lstnew(list_to_clone->next->content);
			list_to_clone = list_to_clone->next;
			new_list = new_list->next;
		}
	}
	return (begg_new_list);
}
