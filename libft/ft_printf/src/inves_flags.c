/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:48:11 by altikka           #+#    #+#             */
/*   Updated: 2022/05/30 12:05:22 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	inves_flags(const char **fptr, t_stat *info)
{
	while (ft_strchr(FLAGS, **fptr))
	{
		if (**fptr == '#')
			info->hash = true;
		if (**fptr == '0')
		{
			info->zero = true;
			info->pad = '0';
		}
		if (**fptr == '-')
			info->dash = true;
		if (**fptr == ' ')
			info->space = true;
		if (**fptr == '+')
			info->plus = true;
		(*fptr)++;
	}
	if (info->zero && info->dash)
	{
		info->zero = false;
		info->pad = ' ';
	}
	return (1);
}
