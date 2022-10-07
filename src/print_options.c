/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 14:18:03 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	normal_print(t_printer *p, t_vec *farm)
{
	write(1, farm->data, farm->len);
	write(1, p->result.data, p->result.len);
}

static void	print_paths(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	size_t	i;
	size_t	j;
	t_room	*room;

	normal_print(p, farm);
	ft_printf("Path count: %d\n", bf->best->count);
	i = 0;
	j = 0;
	while (bf->best->paths[i][j] != -1)
	{
		while (bf->best->paths[i][j] != -1)
		{
			room = ft_vecget(&d->rooms, bf->best->paths[i][j]);
			ft_printf("|%s| ", room->name);
			j++;
			if (bf->best->paths[i][j] != -1)
				ft_printf("-> ");
		}
		j = 0;
		i++;
		if (bf->best->paths[i][j] != -1)
			ft_printf("\n-------------------\n");
	}
	ft_printf("\n");
}

void	print_options(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	if (p->flag == PATHS)
		print_paths(d, bf, p, farm);
	else if (p->flag == QUIET)
		ft_printf(">>>> %d <<<<\n", bf->best->turns);
	else
		normal_print(p, farm);
	ft_vecdel(farm);
}
