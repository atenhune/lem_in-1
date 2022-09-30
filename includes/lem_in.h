/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:09:22 by altikka           #+#    #+#             */
/*   Updated: 2022/09/30 07:46:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "hashmap.h"

/*
**STRUCTIONS FOR THE PROGRAM
*/

typedef struct s_room
{
	char	*name;
	int		x;
	int		y;
	t_vec	links;
	int		index;
}			t_room;

typedef struct s_lem
{
	int		ants;
	t_vec	rooms;
	int		**links;
	int		start;
	int		end;
}			t_lem;

/*
**STRUCTIONS & FUNCTIONS FOR THE PARSER
*/

typedef enum e_state
{
	ANTS,
	ROOMS,
	LINKS
}			t_state;

typedef struct s_parser
{
	t_vec	inputs;
	char	*line;
	int		start;
	int		end;
	t_state	state;
	t_hash	table[TABLE_SIZE];
}			t_parser;

int		parse_ants(t_lem *d, t_parser *p);
int		parse_rooms(t_lem *d, t_parser *p);
int		parse_links(t_lem *d, t_parser *p);

typedef int				(*t_parsers)(t_lem *, t_parser *);

static const t_parsers	g_parsers[3] = {
	parse_ants,
	parse_rooms,
	parse_links
};

int		init_parser(t_parser *p);
int		return_next_line(const int fd, char **line, int *ret);
int		panic_parser(t_parser *p, const char *msg);
void	free_parser(t_parser *p);
int		create_links(t_lem *d);

/*
**FUNCTIONS FOR THE PROGRAM
*/

int		init_data(t_lem *d, t_vec *farm);
int		panic(t_lem *d, const char *msg);
void	free_data(t_lem *d);
int		parse_data(t_lem *d, t_vec *farm);

#endif
