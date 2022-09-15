/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:07:32 by altikka           #+#    #+#             */
/*   Updated: 2021/11/27 13:33:34 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasechr(char const *s, int c)
{
	char	*ptr;
	int		ch;

	ptr = (char *) s;
	ch = ft_tolower(c);
	while (ft_tolower(*ptr) != ch)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}
