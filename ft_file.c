/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:02:00 by rmerzak           #+#    #+#             */
/*   Updated: 2022/01/02 22:53:25 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_file(int f)
{
	if (f < 0)
	{
		write (1, "No such file or directory\n", 26);
		exit(1);
	}
}
