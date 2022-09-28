/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:14:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/28 09:41:23 by altikka          ###   ########.fr       */
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
		return (panic(NULL, "Error: Invalid link (1)."));
	*ptr++ = '-';
	to = hash_get(ptr, *(&p->table));
	if (to == -1)
		return (panic(NULL, "Error: Invalid link (2)."));
	temp = ft_vecget(&d->rooms, from);
	ft_vecpush(&temp->links, &to);
	//p->state = DONE;
	return (1);
}
