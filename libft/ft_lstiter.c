/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:30:20 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/18 16:59:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*currentnode;

	if ((!lst) || (!f))
		return ;
	currentnode = lst;
	while (currentnode)
	{
		f(currentnode->content);
		currentnode = currentnode->next;
	}
}
