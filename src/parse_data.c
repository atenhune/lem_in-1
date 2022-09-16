/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/16 11:05:49 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

static int	get_links(t_lem *d, const char *line)
{
	(void )d;
	(void )line;
	return (1);
}

static int	get_rooms(t_lem *d, const char *line)
{
	(void )d;
	(void )line;
	return (1);
}

static int	get_ants(t_lem *d, const char *line)
{
	(void )d;
	(void )line;
	return (1);
}

int	parse_data(t_lem *d)
{
	char	*line;

	if (get_ants(d, line) < 0)
		return (panic(d, "Error: invalid ants."));
	if (get_rooms(d, line) < 0)
		return (panic(d, "Error: invalid rooms."));
	if (get_links(d, line) < 0)
		return (panic(d, "Error: invalid links."));
	return (1);
}
