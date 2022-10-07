/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:37 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 13:58:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* 
** PLAN
** +: some options like -q etc.
** i: init data
** ii: parse data
** iii: solve
** iv: print
*/

int	main(int argc, char **argv)
{
	t_lem	d;
	t_flag	flag;
	t_bfs	bf;
	t_vec	farm;

	if (init_flags(&flag, argc, argv) <= 0)
		return (ft_putstr(LEM_USAGE), 0);
	if (init_data(&d, &farm) < 0)
		return (panic(NULL, "Error: Initializing data failed."));
	if (parse_data(&d, &farm) < 0)
		return (ft_vecdel(&farm), panic(&d, "Error: Parsing data failed."));
	if (solve(&d, &bf) < 0)
		return (ft_vecdel(&farm), panic(&d, "Error: No solution."));
	if (print(&d, &bf, &farm, flag) < 0)
		return (panic(&d, "Error: Failed to print."));
	free_data(&d);
	//system("leaks -q lem-in");
	return (0);
}
