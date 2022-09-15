/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_dbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:10:57 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 22:43:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

static int	add_point(t_vec *src, char *dec, size_t dec_len, t_stat *info)
{
	if (info->preci || (info->preci_on && info->hash))
	{
		if (ft_vecpush(src, ".") < 0)
		{
			ft_strdel(&dec);
			ft_vecdel(src);
			return (-1);
		}
		if (info->preci && pad(src, (info->preci - dec_len), '0', 1) < 0)
		{
			ft_strdel(&dec);
			ft_vecdel(src);
			return (-1);
		}
	}
	return (1);
}

static int	add_parts(t_vec *src, char *whl, char *dec, t_stat *info)
{
	size_t	whl_len;
	size_t	dec_len;

	whl_len = ft_strlen(whl);
	dec_len = ft_strlen(dec);
	if (ft_vecncat(src, whl, whl_len) < 0)
	{
		ft_strdel(&whl);
		ft_strdel(&dec);
		ft_vecdel(src);
		return (-1);
	}
	ft_strdel(&whl);
	if (add_point(src, dec, dec_len, info) < 0)
		return (-1);
	if (info->preci != 0 && ft_vecncat(src, dec, dec_len) < 0)
	{
		ft_strdel(&dec);
		ft_vecdel(src);
		return (-1);
	}
	ft_strdel(&dec);
	return (1);
}

static int	get_parts(t_vec *src, long double val, t_stat *info)
{
	char		*whl;
	char		*dec;
	long double	d;

	whl = ft_anytoa((unsigned long ) val, 10, 1, false);
	if (!whl)
	{
		ft_vecdel(src);
		return (-1);
	}
	d = (val - (unsigned long ) val) * ft_pow(10, info->preci);
	dec = ft_anytoa((unsigned long ) d, 10, 1, false);
	if (!dec)
	{
		ft_strdel(&whl);
		ft_vecdel(src);
		return (-1);
	}
	return (add_parts(src, whl, dec, info));
}

static int	pad_dbl(t_vec *dest, t_vec *src, long double val, t_stat *info)
{
	t_vec	temp;
	size_t	len;

	if (get_parts(src, val, info) < 0)
		return (-1);
	if (ft_vecnew(&temp, 1, sizeof(char)) < 0)
	{
		ft_vecdel(src);
		return (-1);
	}
	src = pad_dbls_front(src, &temp, src->len, info);
	if (!src)
		return (-1);
	len = src->len;
	if (ft_vecappend(dest, src) < 0)
	{
		ft_vecdel(src);
		return (-1);
	}
	ft_vecdel(src);
	if (pad(dest, (info->width - len), info->pad, (info->dash)) < 0)
		return (-1);
	return (1);
}

int	tc_dbl(t_vec *dest, t_stat *info)
{
	long double		val;
	t_vec			temp;
	int				inf;

	if (info->length == L)
		val = va_arg(info->ap, long double);
	else
		val = va_arg(info->ap, double);
	if (val != val)
	{
		if (info->zero)
			info->pad = ' ';
		return (pad_str(dest, info, "nan", 3));
	}
	inf = ft_isinf((double ) val);
	if (inf != 0)
		return (pad_inf(dest, info, inf));
	info->sign = 1 - (2 * ((1 / val) < 0));
	if (info->is_signed)
		val *= info->sign;
	info->preci = 6 * !info->preci_on + info->preci;
	val = round_dbl(val, info->preci);
	if (ft_vecnew(&temp, 1, sizeof(char)) < 0)
		return (-1);
	return (pad_dbl(dest, &temp, val, info));
}
