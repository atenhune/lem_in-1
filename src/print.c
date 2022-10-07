/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:08 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/07 14:02:22 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	print_send_all(t_lem *d, t_vec *farm, t_flag flag)
{
	t_room	*temp;
	int		ant_nbr;

	if (flag != QUIET)
		write(1, farm->data, farm->len);
	ft_vecdel(farm);
	if (flag == QUIET)
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

int	print(t_lem *d, t_bfs *bf, t_vec *farm, t_flag flag)
{
	t_printer	p;

	if (d->start_to_end == true)
		return (print_send_all(d, farm, flag));
	sort_paths(bf);
	if (init_printer(bf, &p, flag) < 0)
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
