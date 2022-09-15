/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:36:05 by altikka           #+#    #+#             */
/*   Updated: 2022/09/14 16:49:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecremove(t_vec *src, size_t index)
{
	if (!src || index > src->len)
		return (-1);
	if (index == src->len)
	{
		src->len--;
		return (1);
	}
	ft_memmove(
		ft_vecget(src, index),
		&src->data[src->type * (index + 1)],
		(src->len - index) * src->type);
	src->len--;
	return (1);
}
