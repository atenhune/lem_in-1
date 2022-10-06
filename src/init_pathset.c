/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pathset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:12:13 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/06 21:33:11 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	zero_pathset(t_lem *d, t_pathset *set)
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

static int	expand_pathset(t_lem *d, t_pathset *set)
{
	int	i;

	i = 0;
	while (i < d->room_count)
	{
		set->entries[i] = (int *)malloc(sizeof(int) * 2);
		set->to[i] = (int *)malloc(sizeof(int) * d->room_count);
		set->child[i] = (int *)malloc(sizeof(int) * d->room_count);
		set->paths[i] = (int *)malloc(sizeof(int) * d->room_count);
		if (!set->entries[i] || !set->to[i] || !set->child[i] || !set->paths[i])
			return (-1);
		i++;
	}
	return (1);
}

int	init_pathset(t_lem *d, t_pathset *set)
{
	set->seen = malloc(sizeof(int) * (d->room_count * 2));
	set->used = malloc(sizeof(int) * d->room_count);
	set->first = malloc(sizeof(int) * d->room_count);
	set->weight = malloc(sizeof(int) * d->room_count);
	set->parent = malloc(sizeof(int) * d->room_count);
	set->from = malloc(sizeof(int) * d->room_count);
	set->paths = (int **)malloc(sizeof(int *) * d->room_count);
	set->entries = (int **)malloc(sizeof(int *) * d->room_count);
	set->child = (int **)malloc(sizeof(int *) * d->room_count);
	set->to = (int **)malloc(sizeof(int *) * d->room_count);
	if (!set->seen || !set->used || !set->first || !set->weight
		|| !set->parent || !set->from || !set->paths
		|| !set->entries || !set->child || !set->to)
		return (-1);
	if (expand_pathset(d, set) < 0)
		return (-1);
	zero_pathset(d, set);
	return (1);
}
