/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:20:57 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/19 11:27:14 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countsubs(const char *str, char c)
{
	int	i;
	int	newsub;

	i = 0;
	newsub = 0;
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != c && newsub == 0)
		{
			newsub = 1;
			i++;
		}
		else if (*str == c)
		{
			newsub = 0;
		}
		str++;
	}
	return (i);
}

static char	**ft_dostrstr(char **strstr, char const *s, char c, int numsubs)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	start = 0;
	while (s[k] && (i < numsubs))
	{
		while (s[k] && (s[k] == c))
			k++;
		start = k;
		while (s[k] && (s[k] != c))
			k++;
		strstr[i] = (char *)malloc(sizeof(char) *(k - start + 2));
		if (!strstr[i])
			return (0);
		ft_strlcpy(strstr[i], s + start, k - start + 1);
		i++;
	}
	return (strstr);
}

char	**ft_split(char const *s, char c)
{
	char	**strstr;
	int		numsubs;

	if (!s)
		return (NULL);
	numsubs = ft_countsubs(s, c);
	strstr = (char **)malloc(sizeof(char **) * (numsubs + 1));
	if (!strstr)
		return (0);
	strstr[numsubs] = 0;
	strstr = ft_dostrstr(strstr, s, c, numsubs);
	return (strstr);
}
