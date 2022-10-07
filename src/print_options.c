/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:17:12 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 11:21:25 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_paths(t_lem *d, t_bfs *bf)
{
	(void)d;
	(void)bf;

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
}

void	print_options(t_lem *d, t_bfs *bf, t_printer *p, t_vec *farm)
{
	if (d->flag == NONE)
		write(1, farm->data, farm->len);
	ft_vecdel(farm);
	if (d->flag == PATHS)
		print_paths(d, bf);
	if (d->flag == QUIET)
		ft_printf(">>>> %d <<<<\n", bf->best->turns);
	else
		write(1, p->result.data, p->result.len);
}
