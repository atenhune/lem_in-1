/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:31:25 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:33:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	place_ants_in_line(t_lem *d, t_bfs *bf, t_printer *p)
{
	int	ants;
	int	i;

	ants = d->ants;
	i = 0;
	while (ants > 0)
	{
		while (i < bf->best->count && ants > 0)
		{
			if (bf->best->weight[i] + p->ant_line[i]
				< bf->best->weight[i + 1] + p->ant_line[i + 1]
				|| i == bf->best->count - 1)
			{
				p->ant_line[i]++;
				ants--;
				break ;
			}
			i++;
		}
		i = 0;
	}
}

static int	swap_paths(t_bfs *bf, int index, int len, int next_len)
{
	int	*temp;

	if (len > next_len)
	{
		temp = bf->best->paths[index + 1];
		bf->best->paths[index + 1] = bf->best->paths[index];
		bf->best->paths[index] = temp;
		bf->best->weight[index + 1] = len;
		bf->best->weight[index] = next_len;
		return (0);
	}
	else
	{
		bf->best->weight[index] = len;
		bf->best->weight[index + 1] = next_len;
		index++;
		return (index);
	}
}

static int	path_len(int *path)
{
	int	i;

	i = 0;
	while (path[i] != -1)
		i++;
	return (i);
}

void	sort_paths(t_bfs *bf)
{
	int	i;
	int	len;
	int	next_len;

	i = 0;
	if (bf->best->count == 1)
	{
		bf->best->weight[0] = path_len(bf->best->paths[i]);
		return ;
	}
	while (i < bf->best->count - 1)
	{
		len = path_len(bf->best->paths[i]);
		next_len = path_len(bf->best->paths[i + 1]);
		i = swap_paths(bf, i, len, next_len);
	}
}
