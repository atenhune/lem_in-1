/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 17:21:07 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	collect_lines(t_parser *p, const char c)
{
	if (ft_vecncat(&p->inputs, p->line, ft_strlen(p->line)) < 0)
		return (panic(NULL, "Error: Couldn't collect line."));
	if (ft_vecpush(&p->inputs, &c) < 0)
		return (panic(NULL, "Error: Couldn't save line."));
	ft_strdel(&p->line);
	return (1);
}

static int	save_commands(t_lem *d, t_parser *p)
{
	if (!ft_strncmp(p->line, "##start", 8))
	{
		d->start = d->rooms.len;
		p->start++;
	}
	else if (!ft_strncmp(p->line, "##end", 6))
	{
		d->end = d->rooms.len;
		p->end++;
	}
	return (1);
}

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

int	parse_data(t_lem *d, t_vec *farm) //^write description
{
	t_parser	p;
	int			ret;

	if (init_parser(&p) < 0)
		return (panic(NULL, "Error: Initializing parser failed."));
	while (return_next_line(0, &p.line, &ret))
	{
		if (ret == -1)
			return (panic_parser(&p, "Error: GNL issue."));
		if (p.line[0] == '#')
		{
			if (save_commands(d, &p) < 0)
				return (panic_parser(&p, "Error: Invalid command."));
		}
		else if (g_parsers[p.state](d, &p) < 0)
			return (panic_parser(&p, "Error: Invalid ants/rooms/links."));
		if (collect_lines(&p, '\n') < 0)
			return (panic_parser(&p, "Error: Memory issue collecting lines."));
	}
	if (prepare_data(d) < 0)
		return (panic_parser(&p, "Error: Issue with map / creating links."));
	if (ft_vecappend(farm, &p.inputs) < 0)
		return (panic_parser(&p, "Error: Memory issue saving farm."));
	free_parser(&p);
	return (1);
}
