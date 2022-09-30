/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:56:51 by altikka           #+#    #+#             */
/*   Updated: 2022/09/30 22:49:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_hash_table(t_parser *p)
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		p->table[i].room = NULL;
		p->table[i].index = -1;
		i++;
	}
}

int	init_parser(t_parser *p)
{
	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->inputs, 32, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize inputs."));
	p->line = NULL;
	p->start = 0;
	p->end = 0;
	p->state = ANTS;
	init_hash_table(p);
	return (1);
}

int	init_data(t_lem *d, t_vec *farm)
{
	ft_bzero(d, sizeof(*d));
	if (ft_vecnew(&d->rooms, 2, sizeof(t_room)) < 0)
		return (panic(NULL, "Error: Couldn't initialize rooms."));
	if (ft_vecnew(farm, 32, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize farm."));
	d->links = NULL;
	d->start = -1;
	d->end = -1;
	return (1);
}
