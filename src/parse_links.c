/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:14:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/30 22:58:55 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (to == -1)
		return (panic(NULL, "Error: Invalid 2nd link."));
	temp = ft_vecget(&d->rooms, from);
	if (ft_vecpush(&temp->links, &to) < 0)
		return (panic(NULL, "Error: Couldn't save 1st room's link."));
	temp = ft_vecget(&d->rooms, to);
	if (ft_vecpush(&temp->links, &from) < 0)
		return (panic(NULL, "Error: Couldn't save 2nd room's link."));
	return (1);
}
