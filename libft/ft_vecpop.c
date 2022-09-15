/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:18:26 by altikka           #+#    #+#             */
/*   Updated: 2022/09/14 09:39:39 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecpop(void *dest, t_vec *src)
{
	if (!dest || !src)
		return (-1);
	if (!src->data || src->len == 0)
		return (0);
	ft_memcpy(dest, ft_vecget(src, src->len - 1), src->type);
	src->len--;
	return (1);
}
