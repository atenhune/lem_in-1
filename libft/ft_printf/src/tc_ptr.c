/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:12:42 by altikka           #+#    #+#             */
/*   Updated: 2022/06/06 22:44:41 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vec.h"

int	tc_ptr(t_vec *dest, t_stat *info)
{
	info->hash = true;
	info->length = l;
	return (tc_num(dest, info));
}
