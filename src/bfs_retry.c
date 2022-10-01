/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_retry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:23:23 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/01 17:39:32 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clear_flows(t_lem *d, t_bfs *bf, int start_point)
{
	int	cur;
	int	prev;

	cur = start_point;
	prev = start_point;
	bf->flow[cur][d->end] = 0;
	bf->flow[d->end][cur] = 0;
	while (cur != d->start)
	{
		cur = bf->fl_dir[cur];
		bf->fl_dir[prev] = -1;
		bf->flow[cur][prev] = 0;
		bf->flow[prev][cur] = 0;
		prev = cur;
	}
}

static void	add_to_seen(t_lem *d, t_bfs *bf, t_pathset *fresh)
{
	int	i;
	int	j;
	int	prev;

	i = 0;
	j = 0;
	//Cases II & III
	if (bf->fl_dir[fresh->cur] != -1)
	{
		fresh->flag = 0;
		return ;
	}
	//Case I
	while (d->links[fresh->cur][i] != -1)
	{
		prev = (fresh->child[fresh->cur][0] != -1) ? fresh->from[fresh->cur] : fresh->parent[fresh->cur];
		if (fresh->entries[d->links[fresh->cur][i]][0] != 1
			&& d->links[fresh->cur][i] != d->start
			&& d->links[fresh->cur][i] != prev
			&& bf->fl_dir[d->links[fresh->cur][i]] == -1)
		{
			if (fresh->parent[d->links[fresh->cur][i]] == -1)
				fresh->parent[d->links[fresh->cur][i]] = fresh->cur;
			fresh->from[d->links[fresh->cur][i]] = fresh->cur;
			fresh->seen[fresh->seen_len++] = d->links[fresh->cur][i];
			fresh->entries[d->links[fresh->cur][i]][0] = 1;
			if (!fresh->first[fresh->cur])
			{
				fresh->child[fresh->cur][j++] = d->links[fresh->cur][i];
				fresh->child[fresh->cur][j] = -1;
			}
			else
			{
				fresh->to[fresh->cur][j++] = d->links[fresh->cur][i];
				fresh->to[fresh->cur][j] = -1;
			}
		}
		i++;
	}
	fresh->first[fresh->cur] = 1;
}

int		second_bfs(t_lem *d, t_bfs *bf)
{
	t_pathset	*set;
	static int	flag = 0;

	set = (t_pathset *)malloc(sizeof(t_pathset));
	init_pathset(d, set);
	set->cur = d->start;
	set_seen_from_start(d, bf, set);
	while (set->cur != d->end)
	{
		if (!is_next(set, bf, d))
		{
			return (0);
		}
		set->cur = set->seen[set->index];
		add_to_seen(d, bf, set);
		flag++;
	}
	secure_write_path_2(d, bf, set);
	path_collector(d, bf, set);
	ft_memset(bf->fl_dir, -1, sizeof(int) * d->room_count);
	set_fl_dir(set, bf, d);
	set->turns = turn_amount(d, set);
	if	(!bf->best || set->turns < bf->best->turns)
	{
		// if (bf->best)
			// del_set(d, bf->best);
		bf->best = set;
	}
	printf("TURNS: %d\n", set->turns);
	return (1);
}

static void	copy_flow_chart(t_lem *d, t_bfs *bf, int **paths)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (paths[i][j] != -1)
	{
		bf->flow[d->start][paths[i][j]] = 1;
		bf->flow[paths[i][j]][d->start] = -1;
		while (paths[i][j] != -1)
		{
			if (paths[i][j + 1] != -1)
			{
				bf->flow[paths[i][j]][paths[i][j + 1]] = 1;
				bf->flow[paths[i][j + 1]][paths[i][j]] = -1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	clear_all_flows(t_lem *d, t_bfs *bf)
{
	int	i;

	ft_memset(bf->fl_dir, -1, sizeof(int) * d->room_count);
	i = 0;
	while (i < d->room_count)
		ft_memset(bf->flow[i++], 0, sizeof(int) * d->room_count);
}

static void	fl_dir_copy(t_lem *d, t_bfs *bf, int **paths)
{
	int	i;
	int	j;
	int	cur;

	i = 0;
	j = 0;

	while (paths[i][j] != -1)
	{
		while(paths[i][j] != -1)
		{
			cur = paths[i][j];
			if (cur == d->end)
				break ;
			if (j == 0)
				bf->fl_dir[cur] = d->start;
			else
				bf->fl_dir[cur] = paths[i][j - 1];
			j++;
		}
		j = 0;
		i++;
	}
}


void	double_check_paths(t_lem *d, t_bfs *bf)
{
	int	i;

	i = 0;
	clear_all_flows(d, bf);
	copy_flow_chart(d, bf, bf->best->paths);
	fl_dir_copy(d, bf, bf->best->paths);
	while (d->links[d->end][i] != -1)
	{
		if (bf->flow[d->end][d->links[d->end][i]] == -1)
		{
			clear_flows(d, bf, d->links[d->end][i]);
			second_bfs(d, bf);
		}
		i++;
	}
}