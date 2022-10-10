/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:34:44 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:29:14 by altikka          ###   ########.fr       */
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
