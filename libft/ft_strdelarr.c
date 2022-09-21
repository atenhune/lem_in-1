/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:11:23 by altikka           #+#    #+#             */
/*   Updated: 2022/06/24 09:18:27 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdelarr(char ***asa)
{
	char	**temp;

	if (*asa != NULL)
	{
		temp = *asa;
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(*asa);
		*asa = NULL;
	}
}
