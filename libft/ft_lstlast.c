/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:29:45 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/17 13:46:09 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentnode;
	t_list	*posnode;

	if (lst)
	{
		currentnode = lst;
		while (currentnode != NULL)
		{
			posnode = currentnode;
			currentnode = currentnode->next;
		}
		return (posnode);
	}
	return (lst);
}
