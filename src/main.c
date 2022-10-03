/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:37 by altikka           #+#    #+#             */
/*   Updated: 2022/10/03 13:45:10 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* 
** PLAN
** +: some options like -q etc
** i: init data
** ii: parse data
** iii: solve
** iv: print
*/

static void	test_print(t_lem *d)
{
	t_room	*room;
	t_room	*link;
	int		*n;
	size_t	i;
	size_t	j;

	return ;
	ft_printf("\n"); //whole function will be removed once print() is done
	i = 0;
	while (i < d->rooms.len)
	{
		room = ft_vecget(&d->rooms, i);
		ft_printf("room: %s,\tindex: [%d],\tlinks: ", room->name, room->index);
		j = 0;
		while (j < room->links.len)
		{
			n = ft_vecget(&room->links, j);
			link = ft_vecget(&d->rooms, *n);
			ft_printf("%s ", link->name);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_lem	d;
	t_bfs	bf;
	t_vec	farm;

	//* +: -q etc
	(void ) argc;
	(void ) argv;
	if (init_data(&d, &farm) < 0)
		return (panic(NULL, "Error: Initializing data failed."));
	if (parse_data(&d, &farm) < 0)
		return (panic(&d, "Error: Parsing data failed."));
	test_print(&d); //debugging, remove later
	if (solve(&d, &bf) < 0)
		return (panic(&d, "Error: No solution."));
	// remember to free bfs
	if (print(&d, &bf, &farm) < 0)
		return (panic(&d, "Error: Failed to print."));
	// ft_vecdel(&farm); //will be freed in print()
	free_data(&d);
	//system("leaks -q lem-in");
	return (0);
}
