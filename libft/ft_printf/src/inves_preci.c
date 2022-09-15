/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_preci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:38:17 by altikka           #+#    #+#             */
/*   Updated: 2022/05/25 23:30:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	inves_preci_asterisk(const char **fptr, t_stat *info)
{
	int	preci;

	(*fptr)++;
	preci = va_arg(info->ap, int);
	if (preci < 0)
	{
		info->preci_on = false;
		info->preci = 0;
	}
	else
	{
		info->preci_on = true;
		info->preci = (unsigned int ) preci;
	}
	return (1);
}

int	inves_preci(const char **fptr, t_stat *info)
{
	size_t	hop;

	if (**fptr != '.')
		return (-1);
	(*fptr)++;
	if (**fptr == '*')
		return (inves_preci_asterisk(fptr, info));
	while (**fptr == '0')
		(*fptr)++;
	info->preci_on = true;
	info->preci = (unsigned int ) ft_atoi(*fptr);
	if (info->preci)
	{
		hop = ft_anylen(info->preci, 10, 1);
		(*fptr) = (*fptr) + hop;
	}
	while (**fptr == '0')
		(*fptr)++;
	return (1);
}
