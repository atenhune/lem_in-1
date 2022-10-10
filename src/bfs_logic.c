/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:51:30 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:02:05 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	case_helper(t_lem *d, t_pathset *set, t_pos *pos, int seen_from)
{
	if (set->parent[d->links[set->cur][pos->i]] == -1)
		set->parent[d->links[set->cur][pos->i]] = set->cur;
	set->from[d->links[set->cur][pos->i]] = set->cur;
	set->seen[set->seen_len++] = d->links[set->cur][pos->i];
	set->entries[d->links[set->cur][pos->i]][seen_from] = 1;
	if (!set->first[set->cur])
	{
		set->child[set->cur][pos->j++] = d->links[set->cur][pos->i];
		set->child[set->cur][pos->j] = -1;
	}
	else
	{
		set->to[set->cur][pos->j++] = d->links[set->cur][pos->i];
		set->to[set->cur][pos->j] = -1;
	}
}

static void	case_iii(t_lem *d, t_bfs *bf, t_pathset *set)
{
	int		prev;
	int		on_path;
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	while (d->links[set->cur][pos.i] != -1)
	{
		if (set->child[set->cur][0] != -1)
			prev = set->from[set->cur];
		else
			prev = set->parent[set->cur];
		on_path = 1 * (d->links[set->cur][pos.i] == bf->fl_dir[set->cur]);
		if (set->entries[d->links[set->cur][pos.i]][on_path] != 1
			&& d->links[set->cur][pos.i] != d->start
			&& d->links[set->cur][pos.i] != prev)
			case_helper(d, set, &pos, on_path);
		pos.i++;
	}
	set->first[set->cur] = 1;
}

static void	case_ii(t_lem *d, t_bfs *bf, t_pathset *set)
{
	if (bf->fl_dir[set->cur] != d->start
		&& !set->entries[bf->fl_dir[set->cur]][1])
		set->seen[set->seen_len++] = bf->fl_dir[set->cur];
	set->entries[bf->fl_dir[set->cur]][1] = 1;
	if (set->parent[bf->fl_dir[set->cur]] == -1)
		set->parent[bf->fl_dir[set->cur]] = set->cur;
	set->from[bf->fl_dir[set->cur]] = set->cur;
	if (!set->first[set->cur])
	{
		set->child[set->cur][0] = bf->fl_dir[set->cur];
		set->child[set->cur][1] = -1;
	}
	else
	{
		set->to[set->cur][0] = bf->fl_dir[set->cur];
		set->to[set->cur][1] = -1;
	}
	set->flag = 0;
	set->first[set->cur] = 1;
}

static void	case_i(t_lem *d, t_pathset *set)
{
	int		prev;
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	while (d->links[set->cur][pos.i] != -1)
	{
		if (set->child[set->cur][0] != -1)
			prev = set->from[set->cur];
		else
			prev = set->parent[set->cur];
		if (set->entries[d->links[set->cur][pos.i]][0] != 1
			&& d->links[set->cur][pos.i] != d->start
			&& d->links[set->cur][pos.i] != prev)
			case_helper(d, set, &pos, 0);
		pos.i++;
	}
	set->first[set->cur] = 1;
}

/*
** THE LOGIC
** While updating seen room list the program follow three rules:
** case I:		Entering a room that has no flow from a room 
**				that also has no flow
** case II: 	Entering a room that is part of a flow network from a room
**		   		that is not
** case III: 	Entering a room that that is part of a flow network from a room
**				that is also a part of that said flow network
*/

void	update_seen(t_lem *d, t_bfs *bf, t_pathset *set)
{
	if (set->flag)
	{
		case_ii(d, bf, set);
		return ;
	}
	if (bf->fl_dir[set->cur] != -1)
	{
		case_iii(d, bf, set);
		return ;
	}
	case_i(d, set);
}
