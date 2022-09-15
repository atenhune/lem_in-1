/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:24:15 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:48:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_veccpy(t_vec *dest, t_vec *src)
{
	size_t	bytes_to_copy;

	if (!dest || !src || !src->data)
		return (-1);
	if (!dest->data)
		if (ft_vecnew(dest, src->len, dest->type) < 0)
			return (-1);
	if (src->type * src->len < dest->alloc_size)
		bytes_to_copy = src->type * src->len;
	else
		bytes_to_copy = dest->alloc_size;
	ft_memcpy(dest->data, src->data, bytes_to_copy);
	dest->len = bytes_to_copy / dest->type;
	return (1);
}
