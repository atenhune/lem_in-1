/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:21:35 by altikka           #+#    #+#             */
/*   Updated: 2022/09/14 16:05:38 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecinsert(t_vec *dest, const void *src, size_t index)
{
	if (!dest || !src || index > dest->len)
		return (-1);
	if (index == dest->len)
		return (ft_vecpush(dest, src));
	if (dest->type * dest->len >= dest->alloc_size)
		if (ft_vecresize(dest, dest->alloc_size * RESIZE_FAC) < 0)
			return (-1);
	ft_memmove(
		ft_vecget(dest, index + 1),
		ft_vecget(dest, index),
		(dest->len - index) * dest->type);
	ft_memcpy(
		ft_vecget(dest, index),
		src,
		dest->type);
	dest->len++;
	return (1);
}
