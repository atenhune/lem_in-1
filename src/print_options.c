/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 17:55:24 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	print_send_all(t_lem *d, t_vec *farm, t_flag flag)
{
	t_room	*temp;
	int		ant_nbr;

	if (flag == NONE)
		write(1, farm->data, farm->len);
	ft_vecdel(farm);
	if (flag == QUIET)
		return (ft_putendl("Solved using one turn."), 1);
	if (flag == TEST)
		return (ft_putendl(">>>> 1 <<<<"), 1);
	ft_printf("\n");
	temp = ft_vecget(&d->rooms, d->end);
	if (flag == PATHS)
		ft_printf("Path:\n|%s|\n", temp->name);
	ant_nbr = 1;
	while (ant_nbr <= d->ants)
	{
		ft_printf("L%d-%s", ant_nbr, temp->name);
		ant_nbr++;
		if (ant_nbr <= d->ants)
			ft_printf(" ");
	}
	ft_printf("\n");
	return (1);
}

static void	print_normal(t_printer *p, t_vec *farm)
{
	write(1, farm->data, farm->len);
	write(1, p->result.data, p->result.len);
}

static void	print_paths(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	size_t	i;
	size_t	j;
	t_room	*room;

	print_normal(p, farm);
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
			ft_printf("\n--------------------\n");
	}
	ft_printf("\n");
}

void	print_options(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	if (p->flag == PATHS)
		print_paths(d, bf, p, farm);
	else if (p->flag == QUIET)
		ft_printf("Solved using %d turns.\n", bf->best->turns);
	else if (p->flag == TEST)
		ft_printf(">>>> %d <<<<\n", bf->best->turns);
	else
		print_normal(p, farm);
	ft_vecdel(farm);
}
