/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:14:18 by altikka           #+#    #+#             */
/*   Updated: 2022/10/08 14:12:33 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_duplicate_link(t_room *room, int target)
{
	int		*links;
	size_t	len;
	size_t	i;

	links = (int *)room->links.data;
	len = room->links.len;
	i = 0;
	while (i < len)
	{
		if (links[i] == target)
			return (-1);
		i++;
	}
	return (1);
}

int	parse_links(t_lem *d, t_parser *p)
{
	char	*ptr;
	t_room	*temp;
	int		from;
	int		to;

	ptr = ft_strchr(p->line, '-');
	if (!ptr)
		return (panic(NULL, "Error: Invalid link info."));
	*ptr = '\0';
	from = hash_get(p->line, *(&p->table));
	if (from == -1)
		return (panic(NULL, "Error: Invalid 1st link."));
	*ptr++ = '-';
	to = hash_get(ptr, *(&p->table));
	if (to == -1 || to == from)
		return (panic(NULL, "Error: Invalid 2nd link."));
	temp = ft_vecget(&d->rooms, from);
	if (is_duplicate_link(temp, to) < 0)
		return (panic(NULL, "Error: Duplicate link."));
	if (ft_vecpush(&temp->links, &to) < 0)
		return (panic(NULL, "Error: Couldn't save 1st room's link."));
	temp = ft_vecget(&d->rooms, to);
	if (ft_vecpush(&temp->links, &from) < 0)
		return (panic(NULL, "Error: Couldn't save 2nd room's link."));
	return (1);
}
