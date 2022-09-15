/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:38:15 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:49:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecresize(t_vec *src, size_t new_size)
{
	t_vec	temp;
	size_t	new_len;

	if (!src)
		return (-1);
	new_len = new_size / src->type;
	if (ft_vecnew(&temp, new_len, src->type) < 0)
		return (-1);
	if (ft_veccpy(&temp, src) < 0)
		return (-1);
	if (new_len > src->len)
		temp.len = src->len;
	else
		temp.len = new_len;
	ft_vecdel(src);
	*src = temp;
	return (1);
}
