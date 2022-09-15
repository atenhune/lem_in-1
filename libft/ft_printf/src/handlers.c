/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:33:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/23 21:32:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*pad_num(t_stat *info, char *str)
{
	char	*pad;
	char	*res;

	if (!info->val && info->preci_on && !(info->hash && info->type == 'o'))
		*str = '\0';
	pad = pad_nums_front(info, ft_strlen(str));
	res = ft_strjoin(pad, str);
	ft_strdel(&pad);
	ft_strdel(&str);
	return (res);
}

char	*handle_char(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	if (info->type == 'd' || info->type == 'i')
		info->sign = 1 - (2 * ((char ) info->val < 0));
	else
		info->sign = 1;
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned char ) info->val,
			set_base(info->type), 1, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_short(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	if (info->type == 'd' || info->type == 'i')
		info->sign = 1 - (2 * ((short ) info->val < 0));
	else
		info->sign = 1;
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned short ) info->val,
			set_base(info->type), 1, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_int(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	if (info->type == 'd' || info->type == 'i')
		info->sign = 1 - (2 * (info->val < 0));
	else
		info->sign = 1;
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned int ) info->val,
			set_base(info->type), 1, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_long(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, long);
	if (info->type == 'd' || info->type == 'i')
		info->sign = 1 - (2 * (info->val < 0));
	else
		info->sign = 1;
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned long ) info->val,
			set_base(info->type), 1, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}
