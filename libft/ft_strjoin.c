/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:21:03 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/18 14:48:27 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	char	*string;
	int		totalsize;

	if ((!s1) || (!s2))
		return (NULL);
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	pos = (size_t)totalsize + 1;
	string = (char *)malloc(sizeof(char) * (totalsize) + 1);
	if (!string)
		return (0);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	ft_strlcat(string, s2, pos);
	string[ft_strlen(string)] = 00;
	return (string);
}
