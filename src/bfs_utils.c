/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:10:45 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:26:42 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	place_flow(t_bfs *bf, int cur, int next)
{
	if (bf->flow[cur][next] == 0)
	{
		bf->flow[next][cur] = 1;
		bf->flow[cur][next] = -1;
	}
	else
	{
		bf->flow[next][cur] = 0;
		bf->flow[cur][next] = 0;
	}
}

static int	is_child(int *list, int prev)
{
	int	i;

	i = 0;
	while (list[i] != -1)
	{
		if (list[i] == prev)
			return (1);
		i++;
	}
	return (0);
}

void	set_flow(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	cur;
	int	prev;

	cur = set->parent[d->end];
	prev = d->end;
	bf->flow[cur][d->end] = 1;
	bf->flow[d->end][cur] = -1;
	while (cur != d->start)
	{
		if (is_child(set->child[cur], prev))
		{
			place_flow(bf, cur, set->parent[cur]);
			prev = cur;
			cur = set->parent[cur];
		}
		else
		{
			place_flow(bf, cur, set->from[cur]);
			prev = cur;
			cur = set->from[cur];
		}
	}
}

void	set_flow_dir(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;
	int	j;
	int	cur;

	i = 0;
	j = 0;
	ft_memset(bf->fl_dir, -1, sizeof(int) * d->room_count);
	while (set->paths[i][j] != -1)
	{
		while (set->paths[i][j] != -1)
		{
			cur = set->paths[i][j];
			if (cur == d->end)
				break ;
			if (j == 0)
				bf->fl_dir[cur] = d->start;
			else
				bf->fl_dir[cur] = set->paths[i][j - 1];
			j++;
		}
		j = 0;
		i++;
	}
}
