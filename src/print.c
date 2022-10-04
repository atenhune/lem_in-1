/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:08 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/04 19:07:43 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static	size_t	count_used_paths(t_bfs *bf)
// {
// 	size_t	ret;
// 	size_t	i;

// 	ret = 0;
// 	i = 0;
// 	while (i < (size_t)bf->best->count)
// 	{
// 		if (bf->best->used[i] == 1)
// 			ret++;
// 		i++;
// 	}
// 	return (ret);
// }

static int	save_instruction(t_lem *d, t_printer *p, int ant_nbr, int r_index) //parse 2
{
	t_room	*temp;
	char	*ant;

	temp = ft_vecget(&d->rooms, r_index);
	ant = ft_itoa(ant_nbr);
	if (ft_vecpush(&p->result, "L") < 0)
		return (-1); ///dgfhmgfdsfg
	if (ft_vecncat(&p->result, ant, ft_strlen(ant)) < 0)
		return (-1); ///dgfhmgfdsfg
	if (ft_vecpush(&p->result, "-") < 0)
		return (-1); ///dgfhmgfdsfg
	if (ft_vecncat(&p->result, temp->name, ft_strlen(temp->name)) < 0)
		return (-1);
	if (ft_vecpush(&p->result, " ") < 0)
		return (-1); ///dgfhmgfdsfg
	if (r_index == d->end)
		p->done++;
	return (1);
}

static int	collect_turn(t_lem *d, t_bfs *bf, t_printer *p) //parse 1 
{
	int		row;
	int		col;

	row = 0;
	col = bf->best->weight[row] - 1;
	while (row < bf->best->count)
	{
		while (col >= 0)
		{
			if (bf->best->paths[row][col] != -1)
			{
				if (p->ants_on_paths[row][col])
				{
					if (save_instruction(d, p, p->ants_on_paths[row][col], bf->best->paths[row][col]) < 0)
						return (-1); // asdfasdf
				}
			}
			col--;
		}
		row++;
		col = bf->best->weight[row] - 1;
	}
	// int	ofs;
	// int	end;

	// ofs = 0;
	// row = 0;
	// col = bf->best->weight[row] - 1;
	// end = 0;
	// while (!end)
	// {
	// 	while (row < bf->best->count)
	// 	{
	// 		// printf("row: %d col: %d\n", row, col);
	// 		if (col >= 0 && p->ants_on_paths[row][col])
	// 		{
	// 			if (save_instruction(d, p, p->ants_on_paths[row][col],
	// 			bf->best->paths[row][col]) < 0)
	//  				return (-1); // asdfasdf
	// 		}
	// 		row++;
	// 		if (row != bf->best->count)
	// 			col = (bf->best->weight[row] - 1) - ofs;
	// 	}
	// 	if (row == bf->best->count && col == 0)
	// 		end = 1;
	// 	ofs++;
	// 	row = 0;
	// 	col = (bf->best->weight[row] - 1) - ofs;
	// }
	return (1);
}

static void	go_ants_go(t_bfs *bf, t_printer *p) //helper 4
{
	static int	ant_nbr = 1;
	int			i;

	i = 0;
	while (i < bf->best->count)
	{
		if (p->ant_line[i])
		{
			p->ants_on_paths[i][0] = ant_nbr++;
			p->ant_line[i]--;
		}
		else
			p->ants_on_paths[i][0] = 0;
		i++;
	}
}

static void	push_ants(t_bfs *bf, t_printer *p) //helper 3
{
	int	i;

	i = 0;
	while (i < bf->best->count)
	{
		ft_memmove(&p->ants_on_paths[i][1], &p->ants_on_paths[i][0],
			sizeof(int) * (bf->best->weight[i] - 1)); 
		i++;
	}
}

static int	place_ants_on_paths(t_lem *d, t_bfs *bf, t_printer *p) //helper 2
{
	if (ft_vecpush(&p->result, "\n") < 0)
		return (-1); ///dgfhmgfdsfg
	while (d->ants != p->done)
	{
		push_ants(bf, p);
		go_ants_go(bf, p);
		collect_turn(d, bf, p);
		if (ft_vecpush(&p->result, "\n") < 0)
			return (-1); ///dgfhmgfdsfg
	}
	return (1);
}

static void	place_ants_in_line(t_lem *d, t_bfs *bf, t_printer *p) //helper 1
{
	int	ants;
	int	i;

	ants = d->ants;
	i = 0;
	while (ants > 0)
	{
		while (i < bf->best->count && ants > 0)
		{
			if (bf->best->weight[i] + p->ant_line[i]
				< bf->best->weight[i + 1] + p->ant_line[i + 1]
				|| i == bf->best->count - 1)
			{
				p->ant_line[i]++;
				ants--;
				break ;
			}
			i++;
		}
		i = 0;
	}
}

static int	path_len(int *path) //util 3
{
	int	i;

	i = 0;
	while (path[i] != -1)
		i++;
	return (i);
}

static void	sort_paths(t_bfs *bf) //util 2
{
	int	i;
	int	len;
	int	next_len;
	int	*temp;

	i = 0;
	while (i < bf->best->count - 1)
	{
		len = path_len(bf->best->paths[i]);
		next_len = path_len(bf->best->paths[i + 1]);
		if (len > next_len)
		{
			temp = bf->best->paths[i + 1];
			bf->best->paths[i + 1] = bf->best->paths[i];
			bf->best->paths[i] = temp;
			bf->best->weight[i + 1] = len;
			bf->best->weight[i] = next_len;
			i = 0;
		}
		else
		{
			bf->best->weight[i] = len;
			bf->best->weight[i + 1] = next_len;
			i++;
		}
	}
}

static int	init_printer(t_bfs *bf, t_printer *p) //util 1
{
	int	i;

	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->result, 5, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize result."));
	p->ant_line = ft_memalloc(sizeof(int) * bf->best->count);
	if (!p->ant_line)
		return (panic(NULL, "Error: Couldn't initialize ant line."));
	p->ants_on_paths = (int **) malloc(sizeof(int *) * bf->best->count);
	if (!p->ants_on_paths)
		return (panic(NULL, "Error: Path's memory allocation failed."));
	i = 0;
	while (i < bf->best->count)
	{
		p->ants_on_paths[i] = ft_memalloc(sizeof(int) * bf->best->weight[bf->best->count - 1]);
		if (!p->ants_on_paths[i])
			return (panic(NULL, "Error: Path's pointer allocation failed."));
		i++;
	}
	p->path_count = bf->best->count;
	p->done = 0;
	return (1);
}

int	print(t_lem *d, t_bfs *bf, t_vec *farm)
{
	t_printer	p;

	ft_printf(">>>> %d <<<<\n", bf->best->turns);
	// return (1);
	write(1, farm->data, farm->len);
	ft_vecdel(farm);
	sort_paths(bf);
	if (init_printer(bf, &p) < 0) // 
		return (panic_printer(&p, "Error: Couldn't initialize printer."));
	place_ants_in_line(d, bf, &p);
	
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
	if (place_ants_on_paths(d, bf, &p) < 0)
		return (panic_printer(&p, "Error: GET FUKT."));//eregh
	write(1, p.result.data, p.result.len);
	free_printer(&p); //vad
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
	return (1);
}
