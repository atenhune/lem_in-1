/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:49:06 by altikka           #+#    #+#             */
/*   Updated: 2022/05/26 14:49:18 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vasprintf(char **str, const char *format, va_list ap)
{
	t_vec	print;
	t_stat	info;
	int		ret;

	if (ft_vecnew(&print, 1, sizeof(char)) < 0)
		return (-1);
	init_stats(&info, ap);
	ret = press(&print, format, info);
	if (ret < 0)
	{
		ft_vecdel(&print);
		return (-1);
	}
	if (ft_vecpush(&print, "\0") < 0)
	{
		ft_vecdel(&print);
		return (-1);
	}
	*str = print.data;
	va_end(info.ap);
	return (print.len - 1);
}
