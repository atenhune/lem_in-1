/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 12:47:06 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_paths(t_lem *d, t_bfs *bf, t_vec *farm)
{
	size_t	i;
	size_t	j;
	t_room	*room;

	write(1, farm->data, farm->len);
	ft_printf("\nPath count: %d\n", bf->best->count);
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
}

static void	normal_print(t_printer *p, t_vec *farm)
{
	write(1, farm->data, farm->len);
	ft_printf("\n");
	write(1, p->result.data, p->result.len);
}

void	print_options(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	if (d->flag == PATHS)
		print_paths(d, bf, farm);
	if (d->flag == QUIET)
		ft_printf(">>>> %d <<<<\n", bf->best->turns);
	else
		normal_print(p, farm);
	ft_vecdel(farm);
}
