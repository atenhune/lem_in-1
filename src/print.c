/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:08 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/07 11:05:12 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	print_send_all(t_lem *d, t_vec *farm)
{
	t_room	*temp;
	int		ant_nbr;

	if (d->flag != QUIET)
		write(1, farm->data, farm->len);
	ft_vecdel(farm);
	if (d->flag == QUIET)
		return (ft_putendl(">>>> 1 <<<<"), 1);
	//if (d->flag == PATHS)
		//prints right stuff in right format
	ant_nbr = 1;
	temp = ft_vecget(&d->rooms, d->end);
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

int	print(t_lem *d, t_bfs *bf, t_vec *farm)
{
	t_printer	p;

	if (d->start_to_end == true)
		return (print_send_all(d, farm));
	sort_paths(bf);
	if (init_printer(bf, &p) < 0)
	{
		free_bfs(d, bf);
		return (panic_printer(&p, "Error: Couldn't initialize printer."));
	}
	place_ants_in_line(d, bf, &p);
	if (place_ants_on_paths(d, bf, &p) < 0)
	{
		free_bfs(d, bf);
		return (panic_printer(&p, "Error: Couldn't send ants."));
	}
	print_options(d, bf, &p, farm);
	free_printer(&p);
	free_bfs(d, bf);
	return (1);
}
