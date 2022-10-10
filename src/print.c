/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:08 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/10 11:33:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	print(t_lem *d, t_bfs *bf, t_vec *farm, t_flag flag)
{
	t_printer	p;

	if (d->start_to_end == true)
		return (print_send_all(d, farm, flag));
	sort_paths(bf);
	if (init_printer(bf, &p, flag) < 0)
	{
		free_bfs(d, bf);
		ft_vecdel(farm);
		return (panic_printer(&p, "Error: Couldn't initialize printer."));
	}
	place_ants_in_line(d, bf, &p);
	if (place_ants_on_paths(d, bf, &p) < 0)
	{
		free_bfs(d, bf);
		ft_vecdel(farm);
		return (panic_printer(&p, "Error: Couldn't send ants."));
	}
	print_options(d, bf, &p, farm);
	free_printer(&p);
	free_bfs(d, bf);
	return (1);
}
