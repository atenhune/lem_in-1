/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:55:18 by atenhune          #+#    #+#             */
/*   Updated: 2022/09/30 12:26:38 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	zero_bfs(t_lem *d, t_bfs *bf)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->room_count)
	{
		j = 0;
		bf->fl_dir[i] = -1;
		while (j < d->room_count)
			bf->flow[i][j++] = 0;
		i++;
	}
}

static void	init_bfs(t_lem *d, t_bfs *bfs)
{
	int		i;

	i  = 0;
	bfs->best = NULL;
	bfs->fl_dir = malloc(sizeof(int) * d->room_count);
	bfs->flow = (int **)malloc(sizeof(int *) * d->room_count);
	while (i < d->room_count)
		bfs->flow[i++] = malloc(sizeof(int) * d->room_count);
	zero_bfs(d, bfs);
}

int solve(t_lem *d)
{
	t_bfs		bf;
	int			temp;
	t_room 		*room;

	init_bfs(d, &bf);
	temp = 0;
	while (bfs(d, &bf))
		temp++;
	// double_check_paths(d, bf);
	// printf("\nSECOND BFS:\n");
	size_t	i = 0;
	size_t	j = 0;
	while (bf.best->paths[i][j] != -1)
	{
		while (bf.best->paths[i][j] != -1)
		{
			room = ft_vecget(&d->rooms, bf.best->paths[i][j]);
			printf("|%s| ", room->name);
			j++;
			if (bf.best->paths[i][j] != -1)
				printf("-> ");
		}
		j = 0;
		i++;
		printf("\n-------------------\n");
	}
	// debug_bfs(d, bf, set);
	printf(">>>> %d <<<<\n", bf.best->turns);
	// printf(">>>> %d <<<<\n", bf->best->paths[2][0]);
	if (!bf.best)
		return (-1);
	return (1);
}