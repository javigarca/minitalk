/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:06:44 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/17 13:28:21 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*currentnode;

	count = 0;
	currentnode = lst;
	while (currentnode != NULL)
	{
		count++;
		currentnode = currentnode->next;
	}
	return (count);
}
