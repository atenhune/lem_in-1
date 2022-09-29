/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:37 by altikka           #+#    #+#             */
/*   Updated: 2022/09/29 17:10:06 by altikka          ###   ########.fr       */
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

static void	test_links_print(t_lem *d)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (d->links[i])
	{
		while (d->links[i][j] != -1)
		{
			ft_printf("%d ", d->links[i][j++]);
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

static void	test_print(t_lem *d, t_vec *farm)
{
	t_room	*room;
	t_room	*link;
	int		*n;
	size_t	i;
	size_t	j;

	write(1, farm->data, farm->len);
	ft_printf("\n\ngot %d ants.\n\n", d->ants);
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
		i++;
		ft_printf("\n");
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_lem	d;
	t_vec	farm;

	//* +: -q etc
	(void ) argc;
	(void ) argv;
	if (init_data(&d, &farm) < 0)
		return (panic(NULL, "Error: Initializing data failed."));
	if (parse_data(&d, &farm) < 0)
		return (panic(&d, "Error: Parsing data failed."));
	//* iii: solve()
	//* iv: print()
	test_print(&d, &farm); //debugging
	test_links_print(&d); //debugging
	ft_vecdel(&farm); //will be freed in print()
	free_data(&d);
	system("leaks -q lem-in");
	return (0);
}
