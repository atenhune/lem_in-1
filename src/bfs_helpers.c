/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:20:29 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 09:05:42 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	path_mapping(t_lem *d, t_bfs *bf, t_pathset *set, int i)
{
	int	j;

	set->cur = d->links[d->start][i];
	set->paths[set->index][set->seen_len++] = set->cur;
	set->paths[set->index][set->seen_len] = -1;
	while (set->cur != d->end)
	{
		j = 0;
		while (j < d->room_count
			&& bf->flow[set->cur][d->links[set->cur][j]] != 1)
			j++;
		if (j == d->room_count) //flow chart fail safe, remove later
		{
			ft_printf("path_collector exit %d cur name: \n", i); //
			exit(0);
		}
		set->cur = d->links[set->cur][j];
		set->paths[set->index][set->seen_len++] = set->cur;
		set->paths[set->index][set->seen_len] = -1;
		set->len++;
	}
	set->weight[set->index] = set->len;
	set->index++;
	set->count++;
	set->len = 0;
	set->seen_len = 0;
	set->cur = d->start;
}

void	path_collector(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;

	set->index = 0;
	set->seen_len = 0;
	set->cur = d->start;
	i = 0;
	while (d->links[d->start][i] != -1)
	{
		if (bf->flow[d->start][d->links[d->start][i]] == 1)
			path_mapping(d, bf, set, i);
		i++;
	}
}
