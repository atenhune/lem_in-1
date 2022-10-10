/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:07:39 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:31:30 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	init_printer(t_bfs *bf, t_printer *p, t_flag flag)
{
	int	i;

	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->result, 6, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize result."));
	p->ant_line = ft_memalloc(sizeof(int) * bf->best->count);
	if (!p->ant_line)
		return (panic(NULL, "Error: Couldn't initialize ant line."));
	p->ants_on_paths = (int **) malloc(sizeof(int *) * bf->best->count);
	if (!p->ants_on_paths)
		return (panic(NULL, "Error: Path's memory allocation failed."));
	i = 0;
	while (i < bf->best->count)
	{
		p->ants_on_paths[i] = ft_memalloc(
				sizeof(int) * bf->best->weight[bf->best->count - 1]);
		if (!p->ants_on_paths[i])
			return (panic(NULL, "Error: Path's pointer allocation failed."));
		i++;
	}
	p->path_count = bf->best->count;
	p->flag = flag;
	p->done = 0;
	return (1);
}
