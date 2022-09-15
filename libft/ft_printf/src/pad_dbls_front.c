/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_dbls_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:00:46 by altikka           #+#    #+#             */
/*   Updated: 2022/05/18 11:21:45 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vec	*pad_dbls_front(t_vec *src, t_vec *temp, size_t src_len, t_stat *info)
{
	char	*pad;

	info->preci_on = false;
	info->preci = 0;
	pad = pad_nums_front(info, src_len);
	if (pad && ft_vecncat(temp, pad, ft_strlen(pad)) < 0)
	{
		ft_strdel(&pad);
		ft_vecdel(temp);
		return (NULL);
	}
	ft_strdel(&pad);
	if (ft_vecappend(temp, src) < 0)
	{
		ft_vecdel(temp);
		ft_vecdel(src);
		return (NULL);
	}
	ft_vecdel(src);
	return (temp);
}
