/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anylen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:42:13 by altikka           #+#    #+#             */
/*   Updated: 2022/05/08 22:31:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

size_t	ft_anylen(uintmax_t n, int base, int sign)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (sign == -1)
		len++;
	while (n != 0)
	{
		n /= (unsigned long ) base;
		len++;
	}
	return (len);
}
