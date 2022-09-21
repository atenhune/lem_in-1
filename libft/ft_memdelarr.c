/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:55:28 by altikka           #+#    #+#             */
/*   Updated: 2022/06/24 09:18:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelarr(void ***apa)
{
	void	**temp;

	if (*apa != NULL)
	{
		temp = *apa;
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(*apa);
		*apa = NULL;
	}
}
