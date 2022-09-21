/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/21 09:02:21 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

int	parse_links(t_lem *d, t_parser *p)
{
	(void )d;
	p->state = DONE;
	ft_printf("got links, DONE\n");
	return (1);
}

int	parse_rooms(t_lem *d, t_parser *p)
{
	(void )d;
	p->state = LINKS;
	ft_printf("got rooms, next->links\n");
	return (1);
}

int	parse_ants(t_lem *d, t_parser *p)
{
	if (!ft_isnbr(p->line))
		return (-1);
	d->ants = ft_atoi(p->line);
	if (d->ants < 0)
		return (panic(NULL, "Error: Negative ammount of ants."));
	if (d->ants == 0)
		return (panic(NULL, "Error: No ants."));
	p->state = ROOMS;
	ft_printf("got ants, next->rooms\n");
	return (1);
}

static int	collect_lines(t_parser *p, const char c)
{
	if (ft_vecncat(&p->inputs, p->line, ft_strlen(p->line)) < 0)
		return (-1);
	if (ft_vecpush(&p->inputs, &c) < 0)
		return (-1);
	ft_strdel(&p->line);
	return (1);
}

static int	flag_commands(t_parser *p)
{
	if (!ft_strncmp(p->line, "##start", 8))
		p->start++;
	else if (!ft_strncmp(p->line, "##end", 6))
		p->end++;
	return (1);
}

int	parse_data(t_lem *d, t_vec *farm)
{
	t_parser	p;
	int			ret;

	(void)farm;
	if (init_parser(&p) < 0)
		return (panic(NULL, "Error: Initializing parser failed."));
	while (return_next_line(0, &p.line, &ret) && p.state != DONE) //del later
	{
		if (ret == -1)
			return (free_parser(&p, "Error: GNL error."));
		if (p.line[0] == '#')
		{
			if (flag_commands(&p) < 0)
				return (free_parser(&p, "Error: Invalid command."));
		}
		else if (g_parsers[p.state](d, &p) < 0)
			return (free_parser(&p, "Error: Invalid ants/rooms/links."));
		if (collect_lines(&p, '\n') < 0)
			return (free_parser(&p, "Error: Memory issue."));
	}
	ft_printf("DONE\n");
	ft_printf("GOT %d ANTS\n", d->ants);
	write(1, p.inputs.data, p.inputs.len);
	free_parser_data(&p);
	return (1);
}
