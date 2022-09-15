/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:53:49 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 14:20:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	inves_width_asterisk(const char **fptr, t_stat *info)
{
	int		width;
	size_t	hop;

	if (**fptr == '*')
	{
		(*fptr)++;
		width = va_arg(info->ap, int);
		if (width < 0)
			info->dash = true;
		if (!(ft_isdigit(**fptr)))
			return (width);
	}
	width = ft_atoi(*fptr);
	if (width)
	{
		hop = ft_anylen(width, 10, 1);
		(*fptr) = (*fptr) + hop;
	}
	while (**fptr == '0')
		(*fptr)++;
	return (width);
}

int	inves_width(const char **fptr, t_stat *info)
{
	int	width;

	width = inves_width_asterisk(fptr, info);
	if (width < 0)
		width *= -1;
	if (info->zero && info->dash)
	{
		info->zero = false;
		info->pad = ' ';
	}
	info->width = (unsigned int ) width;
	if (!(info->width < 2147483647))
		info->val = -1;
	return (1);
}
