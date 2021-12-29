/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:03:51 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/28 21:41:23 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	k;
	size_t	l;

	k = 0;
	l = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[k] != '\0')
	{
		s[k] = s1[k];
		k++;
	}
	while (s2[l] != '\0')
	{
		s[k] = s2[l];
		l++;
		k++;
	}
	s[k] = '\0';
	return (s);
}
