/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:56:51 by altikka           #+#    #+#             */
/*   Updated: 2022/09/28 09:33:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	init_data(t_lem *d, t_vec *farm)
{
	ft_bzero(d, sizeof(*d));
	if (ft_vecnew(&d->rooms, 2, sizeof(t_room)) < 0)
		return (panic(NULL, "Error: Couldn't initialize rooms."));
	if (ft_vecnew(farm, 32, sizeof(char)) < 0) //32 min chars in map
		return (-1); //what
	d->start = -1;
	d->end = -1;
	return (1);
}
