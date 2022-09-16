/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/16 19:41:34 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

static int	get_links(t_lem *d, t_parse *p)
{
	(void )d;
	p->state = DONE;
	ft_printf("got links, DONE\n");
}

static int	get_rooms(t_lem *d, t_parse *p)
{
	(void )d;
	p->state = LINKS;
	ft_printf("got rooms, next->links\n");
}

static int	ft_isnbr(const char *str)
{
	return (1);
}

static int	get_ants(t_lem *d, t_parse *p)
{
	(void )d;
	p->state = ROOMS;
	ft_printf("got ants, next->rooms\n");
	return (1);
}

static int	get_command(t_parse *p)
{
	return (1);
}

static int	return_next_line(const int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}

static void	init_parser(t_parse *p)
{
	p->line = NULL;
	p->state = ANTS;
	p->start = 0;
	p->end = 0;
}

int	parse_data(t_lem *d)
{
	t_parse	p;
	int		ret;

	init_parser(&p);
	while (return_next_line(0, &p.line, &ret))
	{
		if (*ret == -1)
			return (panic(d, "Error: GNL exited with -1."));
		if (*p.line[0] == '#')
		{
			if (get_command(&p) < 0)
				return (panic(d, "Error: Invalid command."));
		}
		else if (g_parsers[p.state](d, &p) < 0)
			return (panic(d, "Error: Invalid ants/rooms/links."));
	}
	if (p->state != DONE)
	{
		ft_printf("u sux\n");
	}
	return (1);
}
