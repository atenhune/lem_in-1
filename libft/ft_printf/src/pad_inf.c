/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:20:15 by altikka           #+#    #+#             */
/*   Updated: 2022/06/03 12:37:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	pad_inf(t_vec *dest, t_stat *info, int inf)
{
	char	*temp;
	char	*res;
	size_t	len;

	info->zero = false;
	info->pad = ' ';
	info->preci_on = false;
	info->preci = 0;
	info->sign = inf;
	temp = pad_nums_front(info, 3);
	res = ft_strjoin(temp, "inf");
	ft_strdel(&temp);
	len = ft_strlen(res);
	if (ft_vecncat(dest, res, len) < 0)
	{
		ft_strdel(&res);
		return (-1);
	}
	ft_strdel(&res);
	if (pad(dest, (info->width - len), info->pad, (info->dash)) < 0)
		return (-1);
	return (1);
}
