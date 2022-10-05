/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:35:52 by altikka           #+#    #+#             */
/*   Updated: 2022/10/05 19:03:59 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	start_end_connect(t_lem *d)
{
	int	i;

	i = 0;
	while (d->links[d->start][i] != -1)
	{
		if (d->links[d->start][i] == d->end)
			return (1);
		i++;
	}
	return (0);
}

static void	populate_grid(t_lem *d)
{
	t_room	*temp;
	int		*links;
	size_t	i;

	i = 0;
	while (i < d->rooms.len)
	{
		temp = ft_vecget(&d->rooms, i);
		links = (int *)temp->links.data;
		ft_memset(d->links[i], -1, sizeof(int) * (temp->links.len + 1));
		ft_memcpy(d->links[i], links, sizeof(int) * temp->links.len);
		i++;
	}
}

static int	allocate_grid(t_lem *d)
{
	t_room	*temp;
	size_t	i;

	d->links = (int **)malloc(sizeof(int *) * (d->rooms.len + 1));
	if (!d->links)
		return (panic(NULL, "Error: grid's memory allocation failed."));
	i = 0;
	while (i < d->rooms.len)
	{
		temp = ft_vecget(&d->rooms, i);
		d->links[i] = (int *)malloc(sizeof(int) * (temp->links.len + 1));
		if (!d->links[i])
			return (panic(NULL, "Error: grid's pointer allocation failed."));
		i++;
	}
	d->links[i] = (int *) '\0';
	return (1);
}

int	prepare_data(t_lem *d)
{
	if (allocate_grid(d) < 0)
		return (panic(NULL, "Error: Couldn't create links."));
	populate_grid(d);
	d->room_count = (int ) d->rooms.len;
	if (start_end_connect(d))
		d->start_to_end = true;
	return (1);
}

int	return_next_line(const int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}
