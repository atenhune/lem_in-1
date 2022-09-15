/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:47 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 22:44:57 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_base(const char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o')
		return (8);
	else if (c == 'b')
		return (2);
	else
		return (10);
}

int	pad(t_vec *dest, int len, char c, int flag)
{
	if (flag == 0)
		return (0);
	while (len-- > 0)
		if (ft_vecpush(dest, &c) < 0)
			return (-1);
	return (1);
}

void	reset_stats(t_stat *info)
{
	info->val = 0;
	info->sign = 0;
	info->is_signed = false;
	info->hash = false;
	info->dash = false;
	info->plus = false;
	info->space = false;
	info->zero = false;
	info->width = 0;
	info->preci = 0;
	info->preci_on = false;
	info->length = 0;
	info->type = ' ';
	info->pad = ' ';
}

void	init_stats(t_stat *info, va_list ap)
{
	va_copy(info->ap, ap);
	reset_stats(info);
}
