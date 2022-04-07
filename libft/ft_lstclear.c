/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:06:12 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/19 13:43:17 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*currentnode;

	if ((!lst) || (!del))
		return ;
	while (*lst)
	{
		del((*lst)->content);
		currentnode = *lst;
		*lst = currentnode->next;
		free(currentnode);
	}
	*lst = NULL;
}
