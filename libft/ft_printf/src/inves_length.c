/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:09:25 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 22:42:16 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lima(const char **fptr, t_stat *info)
{
	if (*(*fptr + 1) == 'l')
	{
		info->length = ll;
		(*fptr) = (*fptr) + 2;
	}
	else
	{
		info->length = l;
		(*fptr)++;
	}
	return (1);
}

static int	hotel(const char **fptr, t_stat *info)
{
	if (*(*fptr + 1) == 'h')
	{
		info->length = hh;
		(*fptr) = (*fptr) + 2;
	}
	else
	{
		info->length = h;
		(*fptr)++;
	}
	return (1);
}

int	inves_length(const char **fptr, t_stat *info)
{
	if (**fptr == 'h')
		return (hotel(fptr, info));
	if (**fptr == 'l' || **fptr == 'j' || **fptr == 'z')
		return (lima(fptr, info));
	if (**fptr == 'L')
	{
		info->length = L;
		(*fptr)++;
	}
	return (1);
}
