/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:23:31 by antti             #+#    #+#             */
/*   Updated: 2022/10/04 22:06:32 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	zero_pathset(t_lem *d, t_pathset *set)
{
	int	i;

	set->len = 0;
	set->count = 0;
	set->turns = 0;
	set->index = 0;
	set->seen_len = 0;
	set->flag = 0;
	ft_memset(set->seen, -1, sizeof(int) * (d->room_count * 2));
	ft_memset(set->first, 0, sizeof(int) * (d->room_count));
	ft_memset(set->parent, -1, sizeof(int) * (d->room_count));
	ft_memset(set->used, 0, sizeof(int) * (d->room_count));
	ft_memset(set->weight, -1, sizeof(int) * (d->room_count));
	ft_memset(set->from, -1, sizeof(int) * (d->room_count));
	i = 0;
	while (i < d->room_count)
	{
		set->paths[i][0] = -1;
		set->child[i][0] = -1;
		set->to[i][0] = -1;
		set->entries[i][0] = 0;
		set->entries[i][1] = 0;
		i++;
	}
}

void	init_pathset(t_lem *d, t_pathset *set)
{
	int		i;

	i = 0;
	set->seen = malloc(sizeof(int) * (d->room_count * 2)); // remember meeee!!!!!!!!!!!!1
	set->used = malloc(sizeof(int) * d->room_count);
	set->first = malloc(sizeof(int) * d->room_count);
	set->weight = malloc(sizeof(int) * d->room_count);
	set->parent = malloc(sizeof(int) * d->room_count);
	set->from = malloc(sizeof(int) * d->room_count);

	set->paths = (int **)malloc(sizeof(int *) * d->room_count);
	set->entries = (int **)malloc(sizeof(int *) * d->room_count);
	set->child = (int **)malloc(sizeof(int *) * d->room_count);
	set->to = (int **)malloc(sizeof(int *) * d->room_count);
	while (i < d->room_count)
	{
		set->entries[i] = (int *)malloc(sizeof(int) * 2);
		set->to[i] = (int *)malloc(sizeof(int) * d->room_count);
		set->child[i] =(int *)malloc(sizeof(int) * d->room_count);
		set->paths[i++] = (int *)malloc(sizeof(int) * d->room_count);
	}
	zero_pathset(d, set);
}

int	stepped_on_a_path(t_bfs *bf, t_pathset *set, t_lem *d)
{
	int	cur;

	(void)d; //helo o/
	cur = set->seen[set->index];
	if (bf->fl_dir[cur] != -1)
	{
		if (set->child[cur][0] == -1)// WAESGRDHTJH??????????????
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

int	is_next(t_pathset *set, t_bfs *bf, t_lem *d)
{
	(void)d;
	while(set->seen[set->index] != -1)
	{
		set->index++;
		if (set->seen[set->index] != -1)
		{
			if (stepped_on_a_path(bf, set, d))
				set->flag = 1;
			return (1);
		}
	}
	return (0);
}

void	set_seen_from_start(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;

	i = 0;
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

void	back_flow(t_bfs *bf, t_pathset *set, t_lem *d)
{
	if (bf->fl_dir[set->cur] != d->start && !set->entries[bf->fl_dir[set->cur]][1])
		set->seen[set->seen_len++] = bf->fl_dir[set->cur];
	set->entries[bf->fl_dir[set->cur]][1] = 1;
	if (set->parent[bf->fl_dir[set->cur]] == -1)
		set->parent[bf->fl_dir[set->cur]] = set->cur;
	set->from[bf->fl_dir[set->cur]] = set->cur;
	if (!set->first[set->cur])
	{
		set->child[set->cur][0] =  bf->fl_dir[set->cur];
		set->child[set->cur][1] =  -1;
	}
	else
	{
		set->to[set->cur][0] = bf->fl_dir[set->cur];
		set->to[set->cur][1] = -1;
	}
	set->flag = 0;
	set->first[set->cur] = 1;
}

void	update_seen(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;
	int	j;
	int	prev;
	int	on_path;

	i = 0;
	j = 0;
	// CASE II
	if (set->flag)
	{
		back_flow(bf, set, d);
		return ;
	}
	// CASE III
	if (bf->fl_dir[set->cur] != -1)
	{
		while (d->links[set->cur][i] != -1)
		{
			prev = (set->child[set->cur][0] != -1) ? set->from[set->cur] : set->parent[set->cur];
			on_path = (d->links[set->cur][i] == bf->fl_dir[set->cur]) ? 1 : 0;
			if (set->entries[d->links[set->cur][i]][on_path] != 1
				&& d->links[set->cur][i] != d->start
				&& d->links[set->cur][i] != prev)
			{
				if (set->parent[d->links[set->cur][i]] == -1)
					set->parent[d->links[set->cur][i]] = set->cur;
				set->from[d->links[set->cur][i]] = set->cur;
				set->seen[set->seen_len++] = d->links[set->cur][i];
				set->entries[d->links[set->cur][i]][on_path] = 1;
				// if (set->parent[set->cur] == set->from[set->cur])
					// set->child[set->cur][j++] = d->links[set->cur][i];
				if (!set->first[set->cur])
				{
					set->child[set->cur][j++] = d->links[set->cur][i];
					set->child[set->cur][j] = -1;
				}
				else
				{
					set->to[set->cur][j++] = d->links[set->cur][i];
					set->to[set->cur][j] = -1;
				}
			}
			i++;
		}
		set->first[set->cur] = 1;
		return ;
	}
	// CASE I
	while (d->links[set->cur][i] != -1)
	{
		prev = (set->child[set->cur][0] != -1) ? set->from[set->cur] : set->parent[set->cur];
		if (set->entries[d->links[set->cur][i]][0] != 1
			&& d->links[set->cur][i] != d->start
			&& d->links[set->cur][i] != prev)
		{
			if (set->parent[d->links[set->cur][i]] == -1)
				set->parent[d->links[set->cur][i]] = set->cur;
			set->from[d->links[set->cur][i]] = set->cur;
			set->seen[set->seen_len++] = d->links[set->cur][i];
			set->entries[d->links[set->cur][i]][0] = 1;
			if (!set->first[set->cur])
			{
				set->child[set->cur][j++] = d->links[set->cur][i];
				set->child[set->cur][j] = -1;
			}
			else
			{
				set->to[set->cur][j++] = d->links[set->cur][i];
				set->to[set->cur][j] = -1;
			}
		}
		i++;
	}
	set->first[set->cur] = 1;
	set->entries[set->cur][0] = 1; // <----------------- MUISTA
}

int	follow_flow(t_lem *d, t_bfs *bf, int cur)
{
	int	i;

	i = 0;
	while(d->links[cur][i] != -1)
	{
		if (bf->flow[cur][d->links[cur][i]] == 1)
			break ;
		i++;
	}
	return (d->links[cur][i]);
}

void	place_flow(t_bfs *bf, int cur, int next)
{
	if(bf->flow[cur][next] == 0)
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

int		is_child(int *list, int prev)
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

void	secure_write_path_2(t_lem *d, t_bfs *bf, t_pathset *set)
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

void	path_collector(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;
	int	j;

	i = 0;
	set->index = 0;
	set->seen_len = 0;
	set->cur = d->start;
	while (d->links[d->start][i] != -1)
	{
		if (bf->flow[d->start][d->links[d->start][i]] == 1)
		{
			set->cur = d->links[d->start][i];
			set->paths[set->index][set->seen_len++] = set->cur;
			set->paths[set->index][set->seen_len] = -1;
			while (set->cur != d->end)
			{
				j = 0;
				while(j < d->room_count && bf->flow[set->cur][d->links[set->cur][j]] != 1)
					j++;
				if (j == d->room_count)//flow chart failsafe, remove lter
				{
					printf("path_collector exit %d cur name: \n", i); //
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
		i++;
	}
}

void	place_ant(t_pathset *set)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 2147483647;
	while (set->weight[i] != -1)
	{
		if (set->weight[i] < temp)
		{
			temp = set->weight[i];
			j = i;
		}
		i++;
	}
	set->weight[j]++;
	set->used[j] = 1;
}

int		last_ant(t_pathset *set)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = -1;
	while (set->weight[i] != -1)
	{
		if (set->weight[i] > temp && set->used[i])
		{
			temp = set->weight[i];
			j = i;
		}
		i++;
	}
	return (set->weight[j]);
}

int		turn_amount(t_lem *d, t_pathset *set)
{
	int	ants;

	ants = d->ants;
	while (ants > 0)
	{
		place_ant(set);
		ants--;
	}
	return (last_ant(set));
}

void	set_fl_dir(t_pathset *set, t_bfs *bf, t_lem *d)
{
	int	i;
	int	j;
	int	cur;

	i = 0;
	j = 0;

	while (set->paths[i][j] != -1)
	{
		while(set->paths[i][j] != -1)
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

void	debug_bfs(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i = 0;
	int	j = 0;
	t_room *room;
	
	printf("FLOW CHART:\n");
	while(i < d->room_count)
	{
		while(j < d->room_count)
			printf("%2d ", bf->flow[i][j++]);
		printf("\n");
		i++;
		j = 0;
	}
	printf("\n SEEN:\n");
	i=0;
	j=0;
	while(i < d->room_count * 2)
	{
		room = ft_vecget(&d->rooms, set->seen[i]);
		if (set->seen[i] != -1 && i != set->index)
			printf("%2s ", room->name);
		else if (set->seen[i] != -1)
			printf(""BLUE"%2s"WHITE" ", room->name);
		else
			printf("%2d ", set->seen[i]);
		i++;
	}
	printf("\n PARENT:\n");
	while(j < d->room_count)
	{
		room = ft_vecget(&d->rooms, j);
		printf("|%s =",  room->name);
		if (set->parent[j] != -1)
			printf("%2s| ", room->name);
		else
			printf(" -1| ");
		j++;
	}
	j = 0;
	printf("\n FROM:\n");
	while(j < d->room_count)
	{
		room = ft_vecget(&d->rooms, j);
		printf("|%s =", room->name);
		if (set->from[j] != -1)
			printf("%2s| ", room->name);
		else
			printf(" -1| ");
		j++;
	}
	i=0;
	j=0;
	printf("\n FLOW_DIR:\n");
	while(j < d->room_count)
		printf("%2d ", bf->fl_dir[j++]);
	printf("\n USED:\n");
	while(i < d->room_count)
	{
		room = ft_vecget(&d->rooms, i);
		if (set->entries[i][0] + set->entries[i][1] == 0)
			printf(""GREEN"%s"WHITE" ", room->name);
		if (set->entries[i][0] + set->entries[i][1] == 1)
			printf(""YELLOW"%s"WHITE" ", room->name);
		if (set->entries[i][0] + set->entries[i][1] == 2)
			printf(""RED"%s"WHITE" ", room->name);
		i++;
	}
	printf("\n");
	room = ft_vecget(&d->rooms, set->cur);
	printf("\nCUR ROOM: "BLUE"%s"WHITE"\n",  room->name);
}

void	clear_fl_dir(t_lem *d, t_bfs *bf)
{
	int	i;

	i = 0;
	while (i < d->room_count)
		bf->fl_dir[i++] = -1;
}


void	del_set(t_lem *d, t_pathset *set)
{
	free(set->parent);
	free(set->seen);
	free(set->used);
	free(set->from);
	free(set->first);
	ft_intdelarr((void *)set->paths, d->room_count);
	ft_intdelarr((void *)set->child, d->room_count);
	ft_intdelarr((void *)set->entries, d->room_count);
	ft_intdelarr((void *)set->to, d->room_count);
	free(set);
}

int	bfs(t_lem *d, t_bfs *bf)
{
	t_pathset	*set;

	set = (t_pathset*)malloc(sizeof(t_pathset));
	init_pathset(d, set);
	set->cur = d->start;
	set_seen_from_start(d, bf, set);
	while (set->cur != d->end)
	{
		if (!is_next(set, bf, d))
		{
			del_set(d, set);
			return (0);
		}
		set->cur = set->seen[set->index];
		update_seen(d, bf, set);
	}
	secure_write_path_2(d, bf, set);
	path_collector(d, bf, set);
	// clear_fl_dir(d, bf);
	ft_memset(bf->fl_dir, -1, sizeof(int) * d->room_count);
	set_fl_dir(set, bf, d);
	set->turns = turn_amount(d, set);
	if	(!bf->best || set->turns < bf->best->turns) //<= if double_check()
	{
		if (bf->best)
			del_set(d, bf->best);
		bf->best = set;
	}
	else
		del_set(d, set);
	return (1);
}
