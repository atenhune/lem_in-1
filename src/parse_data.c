/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/26 16:11:25 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

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
	while (return_next_line(0, &p.line, &ret) && p.state != DONE) //del DONE
	{
		if (ret == -1)
			return (free_parser(&p, "Error: GNL issue."));
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
	ft_printf("\ndone with ants/rooms/links.\n\n");
	ft_printf("\ngot %d ants.\n\n", d->ants);
	write(1, p.inputs.data, p.inputs.len);
	ft_printf("\ndone with parsing.\n\n");
	free_parser_data(&p);
	return (1);
}
