/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:14:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/27 20:46:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_links(t_lem *d, t_parser *p)
{
	char	*ptr;
	int		target;
	int		to;
	t_room	*temp;

	ptr = ft_strchr(p->line, '-');
	*ptr = '\0';
	target = hash_get(p->line, *(&p->table));
	if (target == -1)
		return (panic(NULL, "Error: Invalid link (1)."));
	*ptr++ = '-';
	to = hash_get(ptr, *(&p->table));
	if (to== -1)
		return (panic(NULL, "Error: Invalid link (2)."));
	temp = ft_vecget(&d->rooms, target);
	ft_vecpush(&temp->links, &to);
	//p->state = DONE;
	ft_printf("got links, DONE\n");//del
	return (1);
}
