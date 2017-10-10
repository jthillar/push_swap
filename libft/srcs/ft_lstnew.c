/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:59:48 by jthillar          #+#    #+#             */
/*   Updated: 2016/11/23 17:12:59 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = malloc(sizeof(t_list) * (content_size))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if ((list->content = malloc(sizeof(content) * content_size)) == NULL)
		{
			free(list);
			return (NULL);
		}
		else
		{
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
	}
	list->next = NULL;
	return (list);
}
