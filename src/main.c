/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:37 by altikka           #+#    #+#             */
/*   Updated: 2022/09/20 18:28:13 by altikka          ###   ########.fr       */
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
	t_room	*temp;
	int		*n;
	size_t	i;

	i = 0;
	while (i < d->rooms.len)
	{
		temp = ft_vecget(&d->rooms, i);
		n = ft_vecget(&temp->links, 0);
		ft_printf("name: %s | link: %d\n", temp->name, *n);
		i++;
	}
}

static void	test_parse(t_lem *d)
{
	t_room	one;
	t_room	two;
	int		a;
	int		b;

	one.name = ft_strnew(5);
	two.name = ft_strnew(5);
	ft_strcpy(one.name, "hello");
	ft_strcpy(two.name, "world");
	ft_vecnew(&one.links, 1, sizeof(int));
	ft_vecnew(&two.links, 1, sizeof(int));
	a = 1000;
	b = 44;
	ft_vecpush(&one.links, &a);
	ft_vecpush(&two.links, &b);
	ft_vecpush(&d->rooms, &one);
	ft_vecpush(&d->rooms, &two);
	test_print(d);
}

int	main(int argc, char **argv)
{
	t_lem	d;
	t_vec	farm;

	//* +: -q etc
	(void ) argc;
	(void ) argv;
	if (init_data(&d) < 0)
		return (panic(NULL, "Error: Initializing data failed."));
	test_parse(&d);
	if (parse_data(&d, &farm) < 0)
		return (panic(&d, "Error: Parsing data failed."));
	//* iii: solve
	//* iv: print
	free_data(&d);
	//system("leaks lem-in");
	return (0);
}
