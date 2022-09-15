/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:27:49 by altikka           #+#    #+#             */
/*   Updated: 2022/09/13 18:24:49 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

void	*ft_vecget(t_vec *src, size_t index)
{
	void	*ptr;

	if (index >= src->len || !src || !src->data)
		return (NULL);
	ptr = &src->data[src->type * index];
	return (ptr);
}
