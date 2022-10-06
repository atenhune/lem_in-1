/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:25:45 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 08:10:11 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_intarr(void **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static void	free_room_data(t_room *room)
{
	if (room->name)
		ft_strdel(&room->name);
	if (room->links.alloc_size)
		ft_vecdel(&room->links);
}

void	free_data(t_lem *d)
{
	t_room	*temp;
	size_t	i;

	if (d->rooms.data)
	{
		i = 0;
		while (i < d->rooms.len)
		{
			temp = ft_vecget(&d->rooms, i);
			if (temp)
				free_room_data(temp);
			i++;
		}
		temp = NULL;
	}
	ft_vecdel(&d->rooms);
	free_intarr((void *)d->links, d->room_count + 1);
}

int	panic(t_lem *d, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (d)
		free_data(d);
	return (-1);
}
