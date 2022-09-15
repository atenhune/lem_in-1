/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_nums_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:40:33 by altikka           #+#    #+#             */
/*   Updated: 2022/06/01 21:16:32 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*format_width(t_stat *info, char *pad, size_t len, int is_signed)
{
	char	*temp;
	char	*res;

	if (!info->dash && info->width > len
		&& info->width > (info->preci + is_signed))
	{
		if (info->preci)
			len = info->width - info->preci - is_signed;
		else
			len = info->width - len - is_signed;
		temp = ft_strnew(len);
		if ((info->zero && !info->hash) || info->width > info->preci)
			info->pad = ' ';
		ft_memset(temp, info->pad, len);
		res = ft_strjoin(temp, pad);
		ft_strdel(&temp);
		ft_strdel(&pad);
		return (res);
	}
	return (pad);
}

static char	*format_prefix(t_stat *info, char *pad)
{
	char	*res;

	if (info->hash)
	{
		if (info->type == 'p' || (ft_tolower(info->type) == 'x' && info->val)
			|| (info->type == 'b' && info->val))
		{
			if (info->type == 'X')
				res = ft_strjoin("0X", pad);
			else if (info->type == 'b')
				res = ft_strjoin("0b", pad);
			else
				res = ft_strjoin("0x", pad);
			ft_strdel(&pad);
			return (res);
		}
		if (info->type == 'o' && info->val)
		{
			res = ft_strjoin("0", pad);
			ft_strdel(&pad);
			return (res);
		}
	}
	return (pad);
}

static char	*format_sign(t_stat *info)
{
	char	*sign;

	sign = ft_strnew(1);
	if (info->sign == -1)
		*sign = '-';
	if (info->space && info->sign != -1 && info->is_signed)
		*sign = ' ';
	if (info->plus && info->sign != -1 && info->is_signed)
		*sign = '+';
	if (*sign == '\0')
		ft_strdel(&sign);
	return (sign);
}

static char	*format_preci(t_stat *info, size_t len, int is_signed)
{
	char	*sign;
	char	*temp;
	char	*res;

	sign = format_sign(info);
	if (info->zero && info->width && !info->preci && !info->preci_on)
		info->preci = info->width - is_signed;
	if (info->preci > len)
	{
		len = info->preci - len;
		temp = ft_strnew(len);
		ft_memset(temp, '0', len);
		res = ft_strjoin(sign, temp);
		ft_strdel(&temp);
		ft_strdel(&sign);
		return (res);
	}
	else
		info->preci = 0;
	return (sign);
}

char	*pad_nums_front(t_stat *info, size_t len)
{
	size_t	px_len;
	char	*pad;
	int		isd;

	if ((!info->val && info->type != 'p')
		|| (info->preci > len && info->type == 'o'))
		info->hash = false;
	if (info->hash)
	{
		px_len = 2 - 1 * (info->type == 'o');
		if (!info->dash && info->preci_on
			&& (info->width >= px_len + info->preci))
			info->width -= px_len;
		else if (info->preci
			&& (info->type == 'x' || info->type == 'X' || info->type == 'p'))
			px_len = 0;
		else
			len += px_len;
	}
	isd = info->is_signed * (info->sign < 0 || info->plus || info->space);
	pad = format_preci(info, len, isd);
	pad = format_prefix(info, pad);
	pad = format_width(info, pad, len, isd);
	return (pad);
}
