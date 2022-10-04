/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:23:31 by antti             #+#    #+#             */
/*   Updated: 2022/10/04 19:54:44 by altikka          ###   ########.fr       */
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
	// while (i < d->room_count)
	// {
	// 	ft_memset(set->paths[i], -1, sizeof(int) * d->room_count);
	// 	ft_memset(set->child[i], -1, sizeof(int) * d->room_count);
	// 	ft_memset(set->to[i], -1, sizeof(int) * d->room_count);
	// 	if (i < 2)
	// 		ft_memset(set->entries[i], 0, sizeof(int) * 2);
	// 	i++;
	// }
}

void	init_pathset(t_lem *d, t_pathset *set)
{
	int		i;

	i = 0;
	// set->temp = malloc(sizeof(int) * d->room_count);
	// set->cur_path = malloc(sizeof(int) * d->room_count);
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
	// free(set->cur_path);
	// exit(0);
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
			// printf("flow from %s to %s  is %d\n", d->rooms[set->seen[set->index]], d->rooms[set->parent[set->seen[set->index]]], bf->flow[set->seen[set->index]][set->parent[set->seen[set->index]]]);
			if (bf->flow[cur][set->parent[cur]] == 0)
			{
				// printf("ret 1\n");
				return (1);
			}
		}
		else
		{
			if (bf->flow[cur][set->from[cur]] == 0)
			{
				// printf("ret 1\n");
				return (1);
			}
		}
	}
	// printf("ret 0\n");
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
			// printf("flag: %d\n", set->flag);
			return (1);
		}
	}
	//printf("bfs DONE.\n");
	// int temp = 0;
	// while (temp < 16)
	// 	printf("[%d] ", set->seen[temp++]);
	// printf("\n");
	return (0);
}

// int		ft_getind(const int *arr, const int target)
// {
// 	int	res;

// 	res = 0;
// 	while (arr[res] && arr[res] != target)
// 		res++;
// 	return (res);
// }

void	set_seen_from_start(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i;

	i = 0;
	// printf("ssfs start %d \n", d->start);
	set->seen[set->seen_len++] = d->start;
	// printf("%d\n", d->links[0][1]);
	// exit(0);
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
	// printf("ssfs end\n");
	// exit(0);
}

// void	init_seen(t_lem *d, t_bfs *bf, t_pathset *set)
// {
// 	int	i;
// 	// int	j;

// 	i = 0;
// 	set->seen[0] = d->start;
// 	set->used[d->start] = d->lcnt[d->start];
// 	while (d->links[set->cur][i] != -1)
// 	{
// 		if (bf->flow[set->cur][d->links[set->cur][i]] != 1)
// 		{
// 			set->seen[set->seen_len++] = d->links[set->cur][i];
// 			set->next[set->cur][set->next[set->cur][0]++] = d->links[set->cur][i];
// 			set->prev[d->links[set->cur][i]][set->prev[d->links[set->cur][i]][0]++] = set->cur;
// 			set->dist[d->links[set->cur][i]] = 1;
// 		}
// 		i++;
// 	}
// }

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
/*
**1: has to y: dont add from, else dont add parent
**2: 
**3:
*/

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
		// printf("\nKEISSI 2\n");
		// if (set->cur == 1175)
		// {
		// 	if (set->child[1175][0] != -1)
		// 		printf("Hxu2 in CASE II from: \n");
		// 	else
		// 		printf("Hxu2 in CASE II parent: \n");
		// }
		back_flow(bf, set, d);
		return ;
	}
	// CASE III
	if (bf->fl_dir[set->cur] != -1)
	{
		// if (set->cur == 1175 && set->entries[1175][1] == 1)
		// {
		// 	if (set->child[1175][0] != -1)
		// 		printf("Hxu2 in CASE III from: \n");
		// 	else
		// 		printf("Hxu2 in CASE III parent: \n");
		// }
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
	// if (set->cur == 1175)
	// {
	// 	if (set->child[1175][0] != -1)
	// 		printf("Hxu2 in CASE I from: \n");
	// 	else
	// 		printf("Hxu2 in CASE I parent: \n");
	// }
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

// int		link_check(t_lem *d, int cur)
// {
// 	int	i = 0;
// 	while(d->links[cur][i] != -1)
// 	{
// 		if (d->links[d->start][i] == cur)
// 			return (2);
// 		i++;
// 	}
// 	return (1);
// }

// void	set_parents(t_lem *d, t_bfs *bf, t_pathset *set)
// {
// 	int	i;
// 	// int	temp;

// 	i = 0;
// 	while (d->links[set->cur][i] != -1)
// 	{
// 		if (set->flag)
// 		{
// 			set->parent[bf->fl_dir[set->cur]] = set->cur;
// 			// set->v_mtx[d->links[set->cur][i]][ft_getind(set->v_mtx[d->links[set->cur][i]], -1)] = set->cur; // GUM
// 			// Case II
// 			// if (bf->fl_dir[set->cur] != d->start && bf->flow[set->cur][set->v_mtx[set->cur][set->used[d->links[set->cur][i]]]] == 0)
// 			if (bf->fl_dir[set->cur] != d->start && bf->flow[set->cur][set->parent[set->cur]] == 0)
// 			{
// 				if (d->links[set->cur][i] != d->start)
// 				{
// 					set->seen[set->seen_len++] = bf->fl_dir[set->cur];
// 					set->flag = 0;
// 					// printf("%d |%d|\n", bf->fl_dir[set->cur], set->cur);
// 				}
// 				// printf("\n flagia kaytetty cur = %d\n", set->cur);
// 				return ;
// 			}
// 			set->flag = 0;
// 		}
// 		// Case I && III
// 		if (set->used[d->links[set->cur][i]] < d->lcnt[d->links[set->cur][i]])
// 		{
// 			// printf("{%d %d}\n", d->links[0][0], d->links[0][1]);
// 			// printf("offset: %d cur: %d\n", offset, set->cur);
// 			// offset = link_check(d, set->cur);
// 			// printf("link: %6d  mtx: %6d\n", d->links[set->cur][i], set->v_mtx[set->cur][set->used[set->cur]]);
// 			// if (d->links[set->cur][i] != d->start && d->links[set->cur][i] != set->v_mtx[d->links[set->cur][i]][set->used[d->links[set->cur][i]]])
// 			// if (d->links[set->cur][i] != d->start && d->links[set->cur][i] != set->v_mtx[set->cur][set->used[set->cur]])
// 			if (d->links[set->cur][i] != d->start && d->links[set->cur][i] != set->parent[set->cur])
// 			{	
// 				set->seen[set->seen_len++] = d->links[set->cur][i];
// 				if (set->parent[d->links[set->cur][i]] == -1)
// 					set->parent[d->links[set->cur][i]] = set->cur;
// 				// 	set->v_mtx[d->links[set->cur][i]][ft_getind(set->v_mtx[d->links[set->cur][i]], -1)] = set->cur; // GUM
// 				// }
// 				// else
// 				// 	set->v_mtx[d->links[set->cur][i]][ft_getind(set->v_mtx[d->links[set->cur][i]], -1)] = set->cur; // GUM
// 			}
// 		}



// 		// if (!set->used[d->links[set->cur][i]] && bf->flow[set->cur][d->links[set->cur][i]] != 1)
// 		// {
// 		// 	set->seen[set->seen_len++] = d->links[set->cur][i];
// 		// 	set->used[d->links[set->cur][i]] = 1;
// 		// }
// 		// if (set->parent[d->links[set->cur][i]] == -1 && set->used[d->links[set->cur][i]])
// 		// 	set->parent[d->links[set->cur][i]] = set->cur;
// 		i++;
// 	}
// 	// int temp = 0;
// 	// while (temp < 8)
// 	// {
// 	// 	printf("%d = [%d] ", temp, set->parent[temp]);
// 	// 		temp++;
// 	// }
// 	// printf("\n %d  %d\n", set->cur, bf->fl_dir[set->cur]);
// }


// void	reverse_path(t_pathset *set, int *arr)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (set->temp[i] != -1)
// 		i++;
// 	i--;
// 	while (i >= 0)
// 		arr[j++] = set->temp[i--];
// }

// int	write_path(t_lem *d, t_pathset *set, int *arr)
// {
// 	int	i;
// 	int	cur;

// 	i = 0;
// 	cur = set->cur;
// 	while (cur != d->start)
// 	{
// 		// printf("[%d]\n", cur);
// 		set->temp[i++] = cur;
// 		cur = set->parent[cur];
// 	}
// 	return(reverse_path(set, arr));
// }

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
	// printf("ret = %d cur = %d\n", d->links[cur][i], cur);
	// exit(0);
	return (d->links[cur][i]);
}

// void	secure_write_path(t_lem *d, t_pathset *set, int *arr)
// {
// 	int	i;
// 	int	cur;

// 	i = 0;
// 	cur = set->cur;
// 	while (cur != d->start)
// 	{
// 		if (set->parent[cur] != set->from[cur] && !set->used[cur])
// 		{
// 			set->used[cur]++;
// 			set->temp[i++] = cur;
// 			cur = set->from[cur];
// 		}
// 		else
// 		{
// 			set->temp[i++] = cur;
// 			cur = set->parent[cur];
// 		}
// 	}
// 	reverse_path(set, arr);
// }

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
	// int	i;

	cur = set->parent[d->end];
	prev = d->end;
	bf->flow[cur][d->end] = 1;
	bf->flow[d->end][cur] = -1;
	// i = 0;
	while (cur != d->start)
	{
		// if (set->parent[cur] != set->from[cur] && !set->used[cur])
		// printf("%s\n", d->rooms[cur]);
		if (is_child(set->child[cur], prev))
		{
			// set->used[cur]++;
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

// void	set_flow(t_pathset *set, t_bfs *bf, t_lem *d)
// {
// 	int	i;
// 
// 	i = 0;
// 	set->cur = d->start;
// 	bf->flow[set->cur][set->cur_path[i]] = 1;
// 	bf->flow[set->cur_path[i]][set->cur] = -1;
// 	while (set->cur_path[i] != -1)
// 	{
// 		set->cur = set->cur_path[i];
// 		if (set->cur_path[i + 1] != -1)
// 		{
// 			if (!bf->flow[set->cur_path[i + 1]][set->cur])
// 			{
// 				bf->flow[set->cur][set->cur_path[i + 1]] = 1;
// 				bf->flow[set->cur_path[i + 1]][set->cur] = -1;
// 			}
// 			else
// 			{
// 				bf->flow[set->cur][set->cur_path[i + 1]] = 0;
// 				bf->flow[set->cur_path[i + 1]][set->cur] = 0;
// 			}
// 		}
// 		i++;
// 	}
// }

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
	int	i;

	i = 0;
	ants = d->ants;
	// while (i < d->room_count)
	// 	set->used[i++] = 0;
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
	// int temp = 0;
	// printf("\n\n||||||||||||||||||||||\n");
	// while(temp < 8)
	// 	printf("%2d ", bf->fl_dir[temp++]);
	// printf("\n\n|||||||||||||||||||||\n");
}

void	debug_bfs(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int	i = 0;
	int	j = 0;
	// (void) bf;
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

// int		integer_hash(int *arr)
// {
// 	int	i;
// 	unsigned long long pre_hash_value;

// 	i = 0;
// 	pre_hash_value = 0;
// 	while (arr[i] != -1)
// 	{
// 		pre_hash_value += (arr[i] + 1) * (i + 1);
// 		pre_hash_value = (pre_hash_value * (arr[i] + 1)) % 2147483647;
// 		i++;
// 	}
// 	return (pre_hash_value);
// }

// void	add_to_seen(t_lem *d, t_bfs *bf, t_pathset *fresh)
// {
// 	int	i;
// 	int	prev;

// 	i = 0;
// 	//Cases I & III
// 	if (bf->fl_dir[fresh->cur] != -1)
// 	{
// 		fresh->flag = 0;
// 		return ;
// 	}
// 	//Case II
// 	while (d->links[fresh->cur][i] != -1)
// 	{
// 		prev = (fresh->to[fresh->cur] != -1) ? fresh->from[fresh->cur] : fresh->parent[fresh->cur];
// 		if (fresh->entries[d->links[fresh->cur][i]][0] != 1
// 			&& d->links[fresh->cur][i] != d->start
// 			&& d->links[fresh->cur][i] != prev)
// 		{
// 			if (fresh->parent[d->links[fresh->cur][i]] == -1)
// 				fresh->parent[d->links[fresh->cur][i]] = fresh->cur;
// 			fresh->from[d->links[fresh->cur][i]] = fresh->cur;
// 			fresh->seen[fresh->seen_len++] = d->links[fresh->cur][i];
// 			fresh->entries[d->links[fresh->cur][i]][0] = 1;
// 			fresh->to[fresh->cur] = d->links[fresh->cur][i];
// 		}
// 		i++;
// 	}
// }

// int		path_check(t_pathset *set, t_lem *d)
// {
// 	// int	i;
// 	// unsigned long long pre_hash_value;

// 	// i = 0;
// 	// pre_hash_value = 0;
// 	// while (set->cur_path[i] != -1)
// 	// {
// 	// 	pre_hash_value += (set->cur_path[i] + 1) * (i + 1);
// 	// 	pre_hash_value = (pre_hash_value * (set->cur_path[i] + 1)) % 2147483647;
// 	// 	i++;
// 	// }
// 	int	pre_hash_value;

// 	pre_hash_value = integer_hash(set->switch_path);
// 	set->hash = ft_itoa(pre_hash_value);
// 	if (!hash_lookup(set->hash, d->table))
// 	{
// 		free(set->hash);
// 		return (0);
// 	}
// 	set->state = 1;
// 	return (1);
// }

// void	path_joiner(t_pathset *set, t_lem *d, t_bfs *bf)
// {
// 	int	i;
// 	int	j;
// 	int	cur;

// 	i = 0;
// 	// int temp = 0;
// 	cur = set->cur;
// 	j = write_path(d, set, set->switch_path);
// 	// temp = 0;
// 	// debug_bfs(d, bf, set);
// 	while (cur != d->end)
// 	{
// 		while (bf->flow[cur][d->links[cur][i]] != 1)
// 			i++;
// 		cur = d->links[cur][i];
// 		set->switch_path[j++] = cur;
// 		i = 0;
// 	}
// 	// while (set->switch_path[temp] != -1)
// 	// 	printf("%d ", set->switch_path[temp++]);
// 	// exit(0);
// }

// void	reset_arrays(t_pathset *set, t_lem *d)
// {
// 	int	i;

// 	i = 0;
// 	while (i < d->room_count)
// 	{
// 		set->switch_path[i] = -1;
// 		set->temp[i++] = -1;
// 	}
// }

// void	add_to_queue(t_lem *d, t_bfs *bf, t_pathset *set)
// {
// 	int	i;
// 	static int bug = 0;

// 	i = 0;
// 	while (d->links[set->cur][i] != -1)
// 	{
// 		if (set->flag)
// 		{
// 			if (set->state)
// 			{
// 				set->flag = 0;
// 				return ;
// 			}
// 			path_joiner(set, d, bf);
// 			if (path_check(set, d))
// 			{
// 				bug++;
// 				// if (bug == 2)
// 				// {
// 				// 	printf("pathcheckissä %d\n", set->cur);
// 				// 	exit(0);
// 				// }
// 				set->switch_point = set->cur;
// 				set->flag = 0;
// 				while(set->temp[i] != -1)
// 					set->temp[i++] = -1;
// 				return ;
// 			}
// 			reset_arrays(set, d);
// 			set->flag = 0;
// 			return ;
// 		}
// 		// Case I && III
// 		if (set->used[d->links[set->cur][i]] < d->lcnt[d->links[set->cur][i]])
// 		{
// 			if (d->links[set->cur][i] != d->start && d->links[set->cur][i] != set->parent[set->cur])
// 			{	
// 				set->seen[set->seen_len++] = d->links[set->cur][i];
// 				if (set->parent[d->links[set->cur][i]] == -1)
// 					set->parent[d->links[set->cur][i]] = set->cur;
// 			}
// 		}
// 		i++;
// 	}
// }

// void	reset_flow(t_lem *d, t_bfs *bf, t_pathset *set)
// {
// 	int	cur;
// 	int	prev;

// 	cur = set->switch_point;
// 	prev = set->switch_point;
// 	while (cur != d->start)
// 	{
// 		cur = bf->fl_dir[cur];
// 		bf->fl_dir[prev] = -1;
// 		bf->flow[cur][prev] = 0;
// 		bf->flow[prev][cur] = 0;
// 		prev = cur;
// 	}
// }

// void	switch_flow(t_lem *d, t_bfs *bf, t_pathset *set)
// {
// 	int	cur;
// 	int	prev;

// 	reset_flow(d, bf, set);
// 	cur = set->switch_point;
// 	prev = set->switch_point;
// 	while (cur != d->start)
// 	{
// 		cur = set->parent[cur];
// 		bf->fl_dir[prev] = cur;
// 		bf->flow[cur][prev] = 1;
// 		bf->flow[prev][cur] = -1;
// 		prev = cur;
// 	}
// }

// void	add_paths_to_table(t_lem *d, t_pathset *set)
// {
// 	int	i;

// 	i = 0;
// 	while(set->paths[i][0] != -1)
// 	{
// 		if (hash_lookup(ft_itoa(integer_hash(set->paths[i])), d->table))
// 			hash_table_insert(ft_itoa(integer_hash(set->paths[i])), d->table);
// 		i++;
// 	}
// }

// void	clear_flows(t_lem *d, t_bfs *bf, int start_point)
// {
// 	int	cur;
// 	int	prev;

// 	cur = start_point;
// 	prev = start_point;
// 	bf->flow[cur][d->end] = 0;
// 	bf->flow[d->end][cur] = 0;
// 	while (cur != d->start)
// 	{
// 		cur = bf->fl_dir[cur];
// 		bf->fl_dir[prev] = -1;
// 		bf->flow[cur][prev] = 0;
// 		bf->flow[prev][cur] = 0;
// 		prev = cur;
// 	}
// 		// printf("%d\n", cur);
// 		// exit(0);
// }

// int		second_bfs(t_lem *d, t_bfs *bf)
// {
// 	t_pathset	*set;
// 	static int	flag = 0;

// 	set = (t_pathset *)malloc(sizeof(t_pathset));
// 	init_pathset(d, set);
// 	set->cur = d->start;
// 	set_seen_from_start(d, bf, set);
// 	while (set->cur != d->end)
// 	{
// 		if (!is_next(set, bf, d))
// 		{
// 			return (0);
// 		}
// 		set->cur = set->seen[set->index];
// 		// add_to_seen(d, bf, set);
// 		//debug
// 		// debug_bfs(d, bf, set);
// 		// if (flag == 22)
// 		// 	exit(0);
// 	}
// 	flag++;
// 	secure_write_path(d, set, set->cur_path);
// 	// int q = 0;
// 	// while (set->cur_path[q] != -1)
// 	// 	printf("%s ", d->rooms[set->cur_path[q++]]);
// 	// printf("\ncur_path 2nd bfs ^^^\n");
// 	// 	if (flag == 3)
// 	// 		exit(0);
// 	set_flow(set, bf, d);
// 	path_collector(d, bf, set);
// 	clear_fl_dir(d, bf);
// 	set_fl_dir(set, bf, d);
// 	set->turns = turn_amount(d, set);
// 	// add_paths_to_table(d, set);
// 	// if	(!bf->best || set->turns < bf->best->turns)
// 	// {
// 	// 	// del_best();
// 	// 	bf->best = set;
// 	// }

// 	// free set struct
// 	return (1);
// }

// void	double_check_paths(t_lem *d, t_bfs *bf)
// {
// 	int	i;
// 	static int flag = 0;

// 	i = 0;
// 	flag++;
// 	// if (flag == 2)
// 	// {
// 	// 	debug_bfs(d, bf, set);
// 	// 	exit(0);
// 	// }
// 	while (d->links[d->end][i] != -1)
// 	{
// 		if (bf->flow[d->end][d->links[d->end][i]] == -1)
// 		{
// 			clear_flows(d, bf, d->links[d->end][i]);
// 			second_bfs(d, bf);
// 		}
// 		i++;
// 	}
// }

// void	clear_paths(t_pathset *set, t_lem *d)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < d->room_count)
// 	{
// 		while(set->paths[i][j] != -1)
// 			set->paths[i][j++] = -1;
// 		j = 0;
// 		i++;
// 	}
// }

void	clear_fl_dir(t_lem *d, t_bfs *bf)
{
	int	i;

	i = 0;
	while (i < d->room_count)
		bf->fl_dir[i++] = -1;
}


void	del_set(t_lem *d, t_pathset *set)
{
	(void)d; //gjjghjggh
	// exit(0);
	// printf("mita tapahtuu!!!\n");
	free(set->parent);
	free(set->seen);
	free(set->used);
	free(set->from);
	free(set->first);
	// while (i < d->room_count)
	// {
	// 	free(set->child[i]);
	// 	free(set->to[i]);
	// 	free(set->paths[i]);
	// 	free(set->entries[i++]);
	// }
	// free(set->paths);
	// free(set->entries);
	// free(set->child);
	// free(set->to);
	ft_intdelarr((void *)set->paths, d->room_count);
	ft_intdelarr((void *)set->child, d->room_count);
	ft_intdelarr((void *)set->entries, d->room_count);
	ft_intdelarr((void *)set->to, d->room_count);
	free(set);
}

void	print_child(t_lem *d, t_pathset *set)
{
	int	i;
	int	j;
	t_room *room;

	i = 0;
	j = 0;
	while(i < d->room_count)
	{
		room = ft_vecget(&d->rooms, i);
		printf("%s: CHILDREN\n", room->name);
		while(set->child[i][j] != -1)
		{
			room = ft_vecget(&d->rooms, set->child[i][j]);
			printf("|%s| ", room->name);
			j++;
		}
		room = ft_vecget(&d->rooms, i);
		printf("\n%s: TO\n", room->name);
		j = 0;
		while(set->to[i][j] != -1)
		{
			room = ft_vecget(&d->rooms, set->to[i][j]);
			printf("|%s| ", room->name);
			j++;
		}
		printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
		j = 0;
		i++;
	}
}

int	bfs(t_lem *d, t_bfs *bf)
{
	t_pathset	*set;
	static int	flag = 0;
	int	end = 0;

	set = (t_pathset*)malloc(sizeof(t_pathset));
	init_pathset(d, set);
	set->cur = d->start;
	// return (1);
	set_seen_from_start(d, bf, set);
	flag++;
	while (set->cur != d->end)
	{
		if (!is_next(set, bf, d))
		{
			return (0);
		}
		end++;
		set->cur = set->seen[set->index];
		update_seen(d, bf, set);
		// debug_bfs(d, bf, set);
		// if (flag == 1)
			// exit(0);
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
	
	// t_room *room;
	// size_t	i = 0;
	// size_t	j = 0;
	// while (set->paths[i][j] != -1)
	// {
	// 	while (set->paths[i][j] != -1)
	// 	{
	// 		room = ft_vecget(&d->rooms, set->paths[i][j]);
	// 		printf("|%s| ", room->name);
	// 		j++;
	// 		if (set->paths[i][j] != -1)
	// 			printf("-> ");
	// 	}
	// 	j = 0;
	// 	i++;
	// 	printf("\n-------------------\n");
	// }
	// debug_bfs(d, bf, set);
	//static int u = 0;
	//printf("  {%d}   room jumps = %d bfs_count %d\n", set->turns, end, u++);
	
	// // exit(0);
	// printf("\n\n#####################\n\n");
	// exit(0);
	return (1);
}
