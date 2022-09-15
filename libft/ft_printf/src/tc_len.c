/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:57:06 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 22:44:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lima_ptr(t_vec *dest, t_stat *info)
{
	long		*lptr;

	lptr = va_arg(info->ap, long *);
	*lptr = (long ) dest->len;
	return (1);
}

static int	hotel_ptr(t_vec *dest, t_stat *info)
{
	signed char	*cptr;
	short		*sptr;

	if (info->length == hh)
	{
		cptr = va_arg(info->ap, signed char *);
		*cptr = (signed char ) dest->len;
	}
	else
	{
		sptr = va_arg(info->ap, short *);
		*sptr = (short ) dest->len;
	}
	return (1);
}

int	tc_len(t_vec *dest, t_stat *info)
{
	int			*iptr;

	if (info->length == hh || info->length == h)
		return (hotel_ptr(dest, info));
	else if (info->length == l)
		return (lima_ptr(dest, info));
	else
	{
		iptr = va_arg(info->ap, int *);
		*iptr = (int ) dest->len;
	}
	return (1);
}
