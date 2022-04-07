/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:30:14 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/02 13:14:13 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*swap;
	unsigned char	*swap2;

	swap = (unsigned char *) dst;
	swap2 = (unsigned char *) src;
	if ((swap == swap2) && (!swap))
		return (dst);
	if ((swap > swap2) && ((swap2 + n) > swap))
	{
		swap = swap + n - 1;
		swap2 = swap2 + n - 1;
		while (n-- > 0)
			*swap-- = *swap2--;
	}
	else
	{
		while (n-- > 0)
			*swap++ = *swap2++;
	}
	return (dst);
}
