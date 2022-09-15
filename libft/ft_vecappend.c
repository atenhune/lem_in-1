/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:34:14 by altikka           #+#    #+#             */
/*   Updated: 2022/09/13 14:08:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecappend(t_vec *dest, t_vec *src)
{
	size_t	new_size;
	int		ret;
	size_t	i;

	if (!dest || !src)
		return (-1);
	if (!dest->data)
		if (ft_vecnew(dest, 1, dest->type) < 0)
			return (-1);
	new_size = dest->type * dest->len + src->type * src->len;
	if (dest->alloc_size < new_size)
	{
		if (dest->alloc_size * RESIZE_FAC < new_size)
			ret = ft_vecresize(dest, new_size);
		else
			ret = ft_vecresize(dest, dest->alloc_size * RESIZE_FAC);
		if (ret < 0)
			return (-1);
	}
	i = dest->type * dest->len;
	ft_memcpy(&dest->data[i], src->data, src->type * src->len);
	dest->len += src->len;
	return (1);
}
