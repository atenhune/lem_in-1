/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_turns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:29:17 by altikka           #+#    #+#             */
/*   Updated: 2022/10/05 18:31:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	place_ant(t_pathset *set)
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

static int	last_ant(t_pathset *set)
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

int	turn_amount(t_lem *d, t_pathset *set)
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
