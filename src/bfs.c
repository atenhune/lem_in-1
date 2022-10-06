/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:23:31 by antti             #+#    #+#             */
/*   Updated: 2022/10/06 08:06:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	is_best(t_lem *d, t_bfs *bf, t_pathset *set)
{
	if (!bf->best || set->turns < bf->best->turns)
	{
		if (bf->best)
			free_pathset(d, bf->best);
		bf->best = set;
	}
	else
		free_pathset(d, set);
}

int	stepped_on_a_path(t_bfs *bf, t_pathset *set)
{
	int	cur;

	cur = set->seen[set->index];
	if (bf->fl_dir[cur] != -1)
	{
		if (set->child[cur][0] == -1)
		{
			if (bf->flow[cur][set->parent[cur]] == 0)
				return (1);
		}
		else
		{
			if (bf->flow[cur][set->from[cur]] == 0)
				return (1);
		}
	}
	return (0);
}

int	is_next(t_bfs *bf, t_pathset *set)
{
	while (set->seen[set->index] != -1)
	{
		set->index++;
		if (set->seen[set->index] != -1)
		{
			if (stepped_on_a_path(bf, set))
				set->flag = 1;
			set->cur = set->seen[set->index];
			return (1);
		}
	}
	return (0);
}

void	set_seen_from_start(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;

	i = 0;
	set->cur = d->start;
	set->seen[set->seen_len++] = d->start;
	while (d->links[d->start][i] != -1)
	{
		if (bf->flow[d->start][d->links[d->start][i]] != 1)
		{
			set->seen[set->seen_len++] = d->links[d->start][i];
			set->parent[d->links[d->start][i]] = d->start;
			set->entries[d->links[d->start][i]][0] = 1;
			set->from[d->links[d->start][i]] = d->start;
		}
		i++;
	}
}

int	bfs(t_lem *d, t_bfs *bf)
{
	t_pathset	*set;

	set = (t_pathset *)malloc(sizeof(t_pathset));
	if (!set)
		return (panic(NULL, "Couldn't initialize pathset."));
	if (init_pathset(d, set) < 0)
		return (panic_pathset(d, set, "Error: Initializing pathset failed."));
	set_seen_from_start(d, bf, set);
	while (set->cur != d->end)
	{
		if (!is_next(bf, set))
		{
			free_pathset(d, set);
			return (0);
		}
		update_seen(d, bf, set);
	}
	set_flow(d, bf, set);
	path_collector(d, bf, set);
	set_flow_dir(d, bf, set);
	set->turns = turn_amount(d, set);
	is_best(d, bf, set);
	return (1);
}
