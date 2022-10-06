/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:08 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/06 19:45:38 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	print(t_lem *d, t_bfs *bf, t_vec *farm)
{
	t_printer	p;

	write(1, farm->data, farm->len);
	ft_vecdel(farm);
	if (d->start_to_end == true)
	{
		if (print_send_all(d) < 0)
			return (panic(NULL, "Error: Couldn't send all ants at once."));
		return (1);
	}
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
	write(1, p.result.data, p.result.len);
	free_printer(&p);
	ft_printf("\n>>>> %d <<<<\n", bf->best->turns);
	free_bfs(d, bf);

	// exit(0);
	// int temp = 0;
	// int temp2 = 0;
	// while(temp < 3)
	// {
	// 	while(temp2 < 3)
	// 		printf("%d ", p.ants_on_paths[temp][temp2++]);
	// 	printf("\n");
	// 	temp2 = 0;
	// 	temp++;
	// }
	// printf("\n");
	// ft_printf(">>>> %d <<<<\n", bf->best->turns);

	// int a = 0;
	// printf("ANT_LINE:\n");
	// while (a < bf->best->count)
	// 	printf("%2d ", p.ant_line[a++]);
	// a = 0;
	// printf("\nWEIGHT:\n");
	// while (a < bf->best->count)
	// 	printf("%2d ", bf->best->weight[a++]);
	// // printf("\n weight: %d\n", bf->best->weight[9]);
	// printf("\n PATH_COUNT: %d\n", bf->best->count);
	// size_t	i = 0;
	// size_t	j = 0;
	// t_room 		*room;
	// while (bf->best->paths[i][j] != -1)
	// {
	// 	while (bf->best->paths[i][j] != -1)
	// 	{
	// 		room = ft_vecget(&d->rooms, bf->best->paths[i][j]);
	// 		printf("|%s| ", room->name);
	// 		j++;
	// 		if (bf->best->paths[i][j] != -1)
	// 			printf("-> ");
	// 	}
	// 	j = 0;
	// 	i++;
	// 	printf("\n-------------------\n");
	// }
	// exit(0);

	return (1);
}
