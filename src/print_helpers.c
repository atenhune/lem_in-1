/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:42:16 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:33:15 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	save_instruction(t_lem *d, t_printer *p, int ant_nbr, int r_index)
{
	t_room	*temp;
	char	*ant;

	temp = ft_vecget(&d->rooms, r_index);
	ant = ft_itoa(ant_nbr);
	if (ft_vecpush(&p->result, "L") < 0)
		return (-1);
	if (ft_vecncat(&p->result, ant, ft_strlen(ant)) < 0)
		return (-1);
	if (ft_vecpush(&p->result, "-") < 0)
		return (-1);
	if (ft_vecncat(&p->result, temp->name, ft_strlen(temp->name)) < 0)
		return (-1);
	if (ft_vecpush(&p->result, " ") < 0)
		return (-1);
	if (r_index == d->end)
		p->done++;
	ft_strdel(&ant);
	return (1);
}

static int	collect_turn(t_lem *d, t_bfs *bf, t_printer *p)
{
	int		row;
	int		col;

	row = 0;
	col = bf->best->weight[row] - 1;
	while (row < bf->best->count)
	{
		while (col >= 0)
		{
			if (bf->best->paths[row][col] != -1)
			{
				if (p->ants_on_paths[row][col])
				{
					if (save_instruction(d, p,
							p->ants_on_paths[row][col],
						bf->best->paths[row][col]) < 0)
						return (panic(NULL, "Error: Couldn't save."));
				}
			}
			col--;
		}
		row++;
		col = bf->best->weight[row] - 1;
	}
	return (1);
}

static void	go_ants_go(t_bfs *bf, t_printer *p)
{
	static int	ant_nbr = 1;
	int			i;

	i = 0;
	while (i < bf->best->count)
	{
		if (p->ant_line[i])
		{
			p->ants_on_paths[i][0] = ant_nbr++;
			p->ant_line[i]--;
		}
		else
			p->ants_on_paths[i][0] = 0;
		i++;
	}
}

static void	push_ants(t_bfs *bf, t_printer *p)
{
	int	i;

	i = 0;
	while (i < bf->best->count)
	{
		ft_memmove(&p->ants_on_paths[i][1], &p->ants_on_paths[i][0],
			sizeof(int) * (bf->best->weight[i] - 1));
		p->ants_on_paths[i][0] = 0;
		i++;
	}
}

int	place_ants_on_paths(t_lem *d, t_bfs *bf, t_printer *p)
{
	ft_vecpush(&p->result, "\n");
	while (d->ants != p->done)
	{
		push_ants(bf, p);
		go_ants_go(bf, p);
		if (collect_turn(d, bf, p) < 0)
			return (panic(NULL, "Error: One of the lines in answer failed."));
		*(char *)&p->result.data[p->result.len - 1] = '\n';
	}
	return (1);
}
