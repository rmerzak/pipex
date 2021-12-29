/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:01:05 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/29 18:54:18 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
#include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);

char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
