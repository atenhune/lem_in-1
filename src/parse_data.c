/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:35:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/20 22:24:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** STRUCTURE
** i: ants
** ii: rooms
** iii: links
*/

int	the_links(t_lem *d, t_parser *p)
{
	(void )d;
	p->state = DONE;
	ft_printf("got links, DONE\n");
	return (1);
}

int	the_rooms(t_lem *d, t_parser *p)
{
	(void )d;
	//check if splitted[0] && !splitted[1]
	//if true, we go to LINKS;
	p->state = LINKS;
	ft_printf("got rooms, next->links\n");
	return (1);
}

static int	ft_isnbr(const char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	number_of_ants(t_lem *d, t_parser *p)
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

//FREE//////////////////////////////////////////////
static void	free_parser_data(t_parser *p)
{
	if (p->inputs.data)
		ft_vecdel(&p->inputs);
	if (p->line)
		ft_strdel(&p->line);
}

static int	free_parser(t_parser *p, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (p)
		free_parser_data(p);
	return (-1);
}
////////////////////////////////////////////////////

static int	return_next_line(const int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}

static int	init_parser(t_parser *p)
{
	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->inputs, 1, sizeof(char)) < 0) //'1' could be bigger
		return (-1);
	p->line = NULL;
	p->state = ANTS;
	p->start = 0;
	p->end = 0;
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
