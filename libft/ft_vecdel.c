/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:23:57 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:48:27 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	ft_vecdel(t_vec *src)
{
	if (src && src->alloc_size != 0)
	{
		free(src->data);
		src->data = NULL;
		src->alloc_size = 0;
		src->type = 0;
		src->len = 0;
	}
}
