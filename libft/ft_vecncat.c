/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:11:05 by altikka           #+#    #+#             */
/*   Updated: 2022/09/13 14:09:21 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecncat(t_vec *dest, const void *src, size_t n)
{
	size_t	new_size;
	int		ret;

	if (!dest || !src)
		return (-1);
	if (!dest->data)
		if (ft_vecnew(dest, 1, dest->type) < 0)
			return (-1);
	new_size = (dest->len + n) * dest->type;
	if (dest->alloc_size < new_size)
	{
		if (dest->alloc_size * RESIZE_FAC < new_size)
			ret = ft_vecresize(dest, new_size);
		else
			ret = ft_vecresize(dest, dest->alloc_size * RESIZE_FAC);
		if (ret < 0)
			return (-1);
	}
	ft_memcpy(&dest->data[dest->type * dest->len], src, dest->type * n);
	dest->len += n;
	return (1);
}
