/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:56:51 by altikka           #+#    #+#             */
/*   Updated: 2022/10/05 18:54:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	zero_bfs(t_lem *d, t_bfs *bf)
{
	int	i;

	ft_memset(bf->fl_dir, -1, sizeof(int) * d->room_count);
	i = 0;
	while (i < d->room_count)
		ft_memset(bf->flow[i++], 0, sizeof(int) * d->room_count);
}

int	init_bfs(t_lem *d, t_bfs *bfs)
{
	int	i;

	ft_bzero(bfs, sizeof(*bfs));
	bfs->best = NULL;
	bfs->fl_dir = malloc(sizeof(int) * d->room_count);
	if (!bfs->fl_dir)
		return (panic(NULL, "Error: Couldn't initialize flow directions."));
	bfs->flow = (int **)malloc(sizeof(int *) * d->room_count);
	if (!bfs->flow)
		return (panic(NULL, "Error: Couldn't initialize flow chart."));
	i = 0;
	while (i < d->room_count)
	{
		bfs->flow[i] = malloc(sizeof(int) * d->room_count);
		if (!bfs->flow[i])
			return (panic(NULL, "Error: Couldn't initialize flow chart."));
		i++;
	}
	zero_bfs(d, bfs);
	return (1);
}

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
	d->room_count = 0;
	d->start_to_end = false;
	d->start = -1;
	d->end = -1;
	return (1);
}
