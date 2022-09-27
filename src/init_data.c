/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:56:51 by altikka           #+#    #+#             */
/*   Updated: 2022/09/27 16:33:53 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	init_data(t_lem *d)
{
	ft_bzero(d, sizeof(*d));
	if (ft_vecnew(&d->rooms, 2, sizeof(t_room)) < 0)
		return (panic(NULL, "Error: Couldn't initialize rooms."));
	d->start = -1;
	d->end = -1;
	return (1);
}
