/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:33:48 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:49:34 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecnew(t_vec *dest, size_t init_len, size_t type)
{
	if (!dest || init_len == 0 || type == 0)
		return (-1);
	dest->alloc_size = type * init_len;
	dest->type = type;
	dest->len = 0;
	if (init_len == 0)
		dest->data = NULL;
	else
	{
		dest->data = malloc(dest->alloc_size);
		if (!dest->data)
		{
			dest->alloc_size = 0;
			dest->type = 0;
			return (-1);
		}
	}
	return (1);
}
